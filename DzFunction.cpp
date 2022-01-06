#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>

#include <llvm/IR/Type.h>
#include <llvm/IR/IRBuilder.h>

#include "DzFunction.h"
#include "DzArgument.h"
#include "DzTypeName.h"
#include "EntryPoint.h"
#include "AllIterator.h"
#include "Type.h"
#include "IndexIterator.h"
#include "DzTupleArgument.h"

#include "values/ExpandableValue.h"
#include "values/TypedValue.h"
#include "values/TupleValue.h"
#include "values/BaseValue.h"
#include "values/UserTypeValue.h"
#include "values/NamedValue.h"
#include "values/TaintedValue.h"

DzFunction::DzFunction(FunctionAttribute attribute
	, const std::string &name
	, const std::vector<DzBaseArgument *> &arguments
	, DzValue *block
	)
	: m_attribute(attribute)
	, m_name(name)
	, m_arguments(arguments)
	, m_block(block)
{
}

std::string DzFunction::name() const
{
	return m_name;
}

FunctionAttribute DzFunction::attribute() const
{
	return m_attribute;
}

bool DzFunction::hasMatchingSignature(const EntryPoint &entryPoint, const Stack &values) const
{
	if (m_arguments.size() != values.size())
	{
		return false;
	}

	auto result = true;

	std::transform(begin(m_arguments), end(m_arguments), values.rbegin(), all_true(result), [=](DzBaseArgument *argument, auto value)
	{
		if (!value)
		{
			return false;
		}

		auto argumentType = argument->type(entryPoint);
		auto valueType = value->type();

		return valueType->is(argumentType, entryPoint);
	});

	return result;
}

std::vector<DzResult> DzFunction::build(const EntryPoint &entryPoint, Stack values) const
{
	auto pep = entryPoint
		.withValues(values);

	auto locals = entryPoint.locals();

	for (const auto &argument : m_arguments)
	{
		for (auto &[name, value] : handleArgument(argument, entryPoint, values.pop()))
		{
			locals[name] = value;
		}
	}

	auto ep = pep
		.withName(m_name)
		.markEntry()
		.withLocals(locals);

	return m_block->build(ep, values);
}

std::vector<DzFunction::Argument> DzFunction::handleArgument(DzBaseArgument *argument, const EntryPoint &entryPoint, const BaseValue *value) const
{
	if (auto tainted = dynamic_cast<const TaintedValue *>(value))
	{
		return handleArgument(argument, entryPoint, tainted->subject());
	}

	if (auto standardArgument = dynamic_cast<DzArgument *>(argument))
	{
		auto name = standardArgument->name();

		std::vector<Argument> result
		{
			{ name, value }
		};

		if (auto userValue = dynamic_cast<const UserTypeValue * >(value))
		{
			auto fields = userValue->fields();

			std::transform(begin(fields), end(fields), std::back_inserter(result), [=](auto field) -> Argument
			{
				std::stringstream ss;
				ss << name;
				ss << ".";
				ss << field->name();

				return { ss.str(), field->value() };
			});
		}

		return result;
	}

	if (auto tupleArgument = dynamic_cast<DzTupleArgument *>(argument))
	{
		auto tupleValue = static_cast<const TupleValue *>(value);

		auto tupleValues = tupleValue->values();
		auto arguments = tupleArgument->arguments();

		std::vector<Argument> results;

		for (auto argument : arguments)
		{
			for (auto &result : handleArgument(argument, entryPoint, tupleValues.pop()))
			{
				results.push_back(result);
			}
		}

		return results;
	}

	throw new std::exception();
}
