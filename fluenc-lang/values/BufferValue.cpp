#include <llvm/IR/Constants.h>
#include <llvm/IR/Instructions.h>

#include "BufferValue.h"
#include "Utility.h"
#include "StringIteratableGenerator.h"
#include "LazyValue.h"
#include "IRBuilderEx.h"
#include "ScalarValue.h"
#include "ReferenceValue.h"

#include "types/BufferType.h"
#include "types/Int64Type.h"

BufferValue::BufferValue(const ReferenceValue *address)
	: m_address(address)
{

}

ValueId BufferValue::id() const
{
	return ValueId::Buffer;
}

const ReferenceValue *BufferValue::reference(const EntryPoint &entryPoint) const
{
	auto llvmContext = entryPoint.context();
	auto block = entryPoint.block();

	auto elementType = llvm::Type::getInt8Ty(*llvmContext);

	auto intType = llvm::Type::getInt32Ty(*llvmContext);

	llvm::Value *indexes[] =
	{
		llvm::ConstantInt::get(intType, sizeof(size_t))
	};

	return new ReferenceValue(m_address->type()
		, llvm::GetElementPtrInst::CreateInBounds(elementType, *m_address, indexes, "bufferLoad", block)
		);
}

const LazyValue *BufferValue::iterator(const EntryPoint &entryPoint) const
{
	auto length = new ReferenceValue(Int64Type::instance(), *m_address);

	// Create a shared pointer, so that we can reuse the logic of
	// StringIteratableGenerator & co. It usually expects a pointer
	// to a string.
	//
	auto address = reference(entryPoint);
	auto value = new ScalarValue(address->type(), *address);

	IRBuilderEx builder(entryPoint);

	auto sharedPointer = entryPoint.alloc(address->type());

	builder.createStore(value, sharedPointer);

	auto generator = new StringIteratableGenerator(sharedPointer, length);

	return new LazyValue(generator, entryPoint);
}

const Type *BufferValue::type() const
{
	return BufferType::instance();
}

const BaseValue *BufferValue::clone(const EntryPoint &entryPoint, CloneStrategy strategy) const
{
	UNUSED(entryPoint);
	UNUSED(strategy);

	return this;
}
