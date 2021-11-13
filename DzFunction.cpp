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

#include "types/UserType.h"

#include "values/ExpandableValue.h"
#include "values/TypedValue.h"

DzFunction::DzFunction(FunctionAttribute attribute
	, const std::string &name
	, const std::vector<DzArgument *> &arguments
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

	std::transform(begin(m_arguments), end(m_arguments), values.rbegin(), all_true(result), [=](DzArgument *argument, auto value)
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
	auto &module = entryPoint.module();
	auto &context = entryPoint.context();

	auto pep = entryPoint
		.withValues(values);

	auto block = entryPoint.block();

	auto dataLayout = module->getDataLayout();

	auto locals = entryPoint.locals();

	for (const auto &argument : m_arguments)
	{
		auto name = argument->name();

		auto value = values.pop();

		if (auto addressOfArgument = dynamic_cast<const TypedValue *>(value))
		{
			auto argumentType = addressOfArgument->type();
			auto storageType = argumentType->storageType(*context);

			auto align = dataLayout.getABITypeAlign(storageType);

			if (auto userType = dynamic_cast<const UserType *>(argumentType))
			{
				auto intType = llvm::Type::getInt32Ty(*context);

				auto load = new llvm::LoadInst(storageType, *addressOfArgument, name, false, align, block);

				auto i = 0;

				for (auto &field : userType->fields())
				{
					std::stringstream ss;
					ss << name;
					ss << ".";
					ss << field.name();

					auto localName = ss.str();

					auto fieldType = field.type();

					if (fieldType)
					{
						llvm::Value *indexes[] =
						{
							llvm::ConstantInt::get(intType, 0),
							llvm::ConstantInt::get(intType, i++)
						};

						auto gep = llvm::GetElementPtrInst::CreateInBounds(load, indexes, field.name(), block);

						locals[localName] = new TypedValue(fieldType, gep);
					}
					else
					{
						locals[localName] = nullptr;
					}
				}

				locals[name] = addressOfArgument;
			}
			else
			{
				locals[name] = new TypedValue(argumentType, *addressOfArgument);
			}
		}
		else if (auto dependentValue = dynamic_cast<const ExpandableValue *>(value))
		{
			locals[name] = dependentValue;
		}
	}

	auto ep = pep
		.withName(m_name)
		.withEntry(block)
		.withLocals(locals);

	return m_block->build(ep, values);
}
