#include "BlockStackFrame.h"

BlockStackFrame::BlockStackFrame(DzValue *consumer)
	: m_consumer(consumer)
{
}

std::vector<DzResult> BlockStackFrame::build(const EntryPoint &entryPoint, Stack values) const
{
	UNUSED(values);

	return m_consumer->build(entryPoint, Stack());
}
