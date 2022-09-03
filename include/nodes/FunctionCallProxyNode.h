#ifndef FUNCTIONCALLPROXYNODE_H
#define FUNCTIONCALLPROXYNODE_H

#include "Node.h"

class FunctionCallProxyNode : public Node
{
	friend class Emitter;
	friend class Analyzer;

	public:
		FunctionCallProxyNode(const std::vector<std::string> &names
			, const Node *regularCall
			, const Node *consumer
			);

		std::vector<DzResult> accept(const Emitter &visitor, DefaultVisitorContext context) const override;
		std::vector<DzResult> accept(const Analyzer &visitor, DefaultVisitorContext context) const override;

	private:
		std::vector<std::string> m_names;

		const Node *m_regularCall;
		const Node *m_consumer;
};

#endif // FUNCTIONCALLPROXYNODE_H
