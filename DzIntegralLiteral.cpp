#include <llvm/IR/Constants.h>

#include <regex>

#include "DzIntegralLiteral.h"
#include "DzTypeName.h"
#include "EntryPoint.h"
#include "Type.h"

DzIntegralLiteral::DzIntegralLiteral(DzValue *consumer, DzTypeName *type, const std::string &value)
	: m_consumer(consumer)
	, m_type(type)
	, m_value(value)
{
}

int DzIntegralLiteral::compare(DzValue *other, const EntryPoint &entryPoint) const
{
	UNUSED(other);
	UNUSED(entryPoint);

	return -1;
}

std::vector<DzResult> DzIntegralLiteral::build(const EntryPoint &entryPoint, Stack values) const
{
	auto &context = entryPoint.context();

	auto type = m_type->resolve(entryPoint);
	auto storageType = type->storageType(*context);

	auto value = new TypedValue(type
		, getValue(storageType)
		);

	values.push(value);

	return m_consumer->build(entryPoint, values);
}

llvm::ConstantInt *DzIntegralLiteral::getValue(llvm::Type *storageType) const
{
	auto hex = m_value.find("0x");

	if (hex != std::string::npos)
	{
		return llvm::ConstantInt::get((llvm::IntegerType *)storageType, m_value.substr(hex + 2), 16);
	}

	return llvm::ConstantInt::get((llvm::IntegerType *)storageType, m_value, 10);
}
