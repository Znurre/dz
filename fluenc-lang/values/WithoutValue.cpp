#include "WithoutValue.h"
#include "Utility.h"

#include "types/WithoutType.h"

const WithoutValue *WithoutValue::instance()
{
	static WithoutValue instance;

	return &instance;
}

const Type *WithoutValue::type() const
{
	return WithoutType::instance();
}

const BaseValue *WithoutValue::clone(const EntryPoint &entryPoint, CloneStrategy strategy) const
{
	UNUSED(entryPoint);
	UNUSED(strategy);

	return this;
}
