#include "nodes/IndexSinkNode.h"

IndexSinkNode::IndexSinkNode(size_t index, const Node *consumer)
	: m_index(index)
	, m_consumer(consumer)
{
}

std::vector<DzResult> IndexSinkNode::accept(const Emitter &visitor, DefaultVisitorContext context) const
{
	return visitor.visitIndexSink(this, context);
}

std::vector<DzResult> IndexSinkNode::accept(const Analyzer &visitor, DefaultVisitorContext context) const
{
	return visitor.visitIndexSink(this, context);
}
