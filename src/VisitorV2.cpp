#include <vector>
#include <map>
#include <unordered_set>
#include <numeric>

#include "peglib.h"

#include "VisitorV2.h"
#include "ModuleInfo.h"
#include "Namespace.h"
#include "Use.h"
#include "DzTypeName.h"
#include "FunctionTypeName.h"
#include "DzArgument.h"
#include "DzTupleArgument.h"
#include "DefaultPrototypeProvider.h"
#include "Indexed.h"
#include "IndexIterator.h"
#include "WithPrototypeProvider.h"

#include "nodes/CallableNode.h"
#include "nodes/GlobalNode.h"
#include "nodes/TerminatorNode.h"
#include "nodes/BlockInstructionNode.h"
#include "nodes/FunctionNode.h"
#include "nodes/ImportedFunctionNode.h"
#include "nodes/BlockStackFrameNode.h"
#include "nodes/ReturnNode.h"
#include "nodes/ContinuationNode.h"
#include "nodes/ExportedFunctionTerminatorNode.h"
#include "nodes/ExportedFunctionNode.h"
#include "nodes/IntegralLiteralNode.h"
#include "nodes/BooleanLiteralNode.h"
#include "nodes/NothingNode.h"
#include "nodes/StringLiteralNode.h"
#include "nodes/CharacterLiteralNode.h"
#include "nodes/BinaryNode.h"
#include "nodes/InstantiationNode.h"
#include "nodes/ConditionalNode.h"
#include "nodes/ArraySinkNode.h"
#include "nodes/EmptyArrayNode.h"
#include "nodes/FunctionCallNode.h"
#include "nodes/MemberAccessNode.h"
#include "nodes/ReferenceSinkNode.h"
#include "nodes/FunctionCallProxyNode.h"
#include "nodes/StackSegmentNode.h"
#include "nodes/LazyEvaluationNode.h"
#include "nodes/IndexSinkNode.h"
#include "nodes/ExpansionNode.h"
#include "nodes/LocalNode.h"

#include "types/Prototype.h"
#include "types/IteratorType.h"
#include "types/Int32Type.h"
#include "types/Int64Type.h"
#include "types/BooleanType.h"
#include "types/StringType.h"
#include "types/ByteType.h"

class CallableNode;
class BaseValue;
class Prototype;

VisitorV2::VisitorV2(const std::vector<std::string> &namespaces
	, const Type *iteratorType
	, const Node *alpha
	, const Node *beta
	)
	: m_namespaces(namespaces)
	, m_iteratorType(iteratorType)
	, m_alpha(alpha)
	, m_beta(beta)
{
}

std::vector<std::string> qualifiedNames1(const std::vector<std::string> &namespaces, const std::string &name)
{
	if (name.rfind("::") == 0)
	{
		return { name.substr(2) };
	}

	std::ostringstream qualifiedName;

	std::copy(begin(namespaces), end(namespaces)
		, std::ostream_iterator<std::string>(qualifiedName, "::")
		);

	qualifiedName << name;

	return { qualifiedName.str(), name };
}

void populateInstructions1(const std::vector<std::string> &namespaces
	, const std::vector<std::any> &instructions
	, std::vector<CallableNode *> &roots
	, std::multimap<std::string, CallableNode *> &functions
	, std::map<std::string, const BaseValue *> &locals
	, std::map<std::string, const Node *> &globals
	, std::map<std::string, Prototype *> &types
	, std::unordered_set<std::string> &uses
	)
{
	for (auto &instruction : instructions)
	{
		if (instruction.type() == typeid(Namespace *))
		{
			auto _namespace = std::any_cast<Namespace *>(instruction);

			std::vector<std::string> nestedNamespaces(namespaces);

			nestedNamespaces.push_back(_namespace->name());

			populateInstructions1(nestedNamespaces
				, _namespace->children()
				, roots
				, functions
				, locals
				, globals
				, types
				, uses
				);
		}
		else
		{
			if (instruction.type() == typeid(CallableNode *))
			{
				auto callable = std::any_cast<CallableNode *>(instruction);

				if (callable->attribute() == FunctionAttribute::Export)
				{
					roots.push_back(callable);
				}
				else
				{
					auto name = qualifiedNames1(namespaces
						, callable->name()
						);

					functions.insert({ name[0], callable });
				}
			}
			else if (instruction.type() == typeid(Prototype *))
			{
				auto prototype = std::any_cast<Prototype *>(instruction);

				auto name = qualifiedNames1(namespaces
					, prototype->name()
					);

				types.insert({ name[0], prototype });
			}
			else if (instruction.type() == typeid(GlobalNode *))
			{
				auto global = std::any_cast<GlobalNode *>(instruction);

				auto name = qualifiedNames1(namespaces
					, global->name()
					);

				globals.insert({ name[0], global });
			}
			else if (instruction.type() == typeid(Use *))
			{
				auto use = std::any_cast<Use *>(instruction);

				uses.insert(use->fileName());
			}
		}
	}
}

ModuleInfo VisitorV2::visit(const std::shared_ptr<peg::Ast> &ast) const
{
	std::vector<CallableNode *> roots;
	std::multimap<std::string, CallableNode *> functions;
	std::map<std::string, const BaseValue *> locals;
	std::map<std::string, const Node *> globals;
	std::map<std::string, Prototype *> types;
	std::unordered_set<std::string> uses;

	std::vector<std::any> results;

	std::transform(begin(ast->nodes), end(ast->nodes), std::back_inserter(results), [this](auto instruction)
	{
		return visitInstruction(instruction);
	});

	populateInstructions1(std::vector<std::string>()
		, results
		, roots
		, functions
		, locals
		, globals
		, types
		, uses
		);

	return ModuleInfo
	{
		roots,
		functions,
		locals,
		globals,
		types,
		uses,
	};
}

std::any VisitorV2::visitInstruction(const std::shared_ptr<peg::Ast> &ast) const
{
	using namespace peg::udl;

	switch (ast->tag)
	{
		case "Instruction"_:
			return visitInstruction(ast->nodes[0]);
		case "Function"_:
			return visitFunction(ast);
		case "Structure"_:
			return visitStructure(ast);
		case "Global"_:
			return visitGlobal(ast);
		case "Namespace"_:
			return visitNamespace(ast);
		case "Use"_:
			return visitUse(ast);
		case "Block"_:
			return visitBlock(ast);
	}

	throw new std::exception();
}

std::string VisitorV2::visitId(const std::shared_ptr<peg::Ast> &ast) const
{
	return ast->token_to_string();
}

std::string VisitorV2::visitInteger(const std::shared_ptr<peg::Ast> &ast) const
{
	return ast->token_to_string();
}

std::string VisitorV2::visitString(const std::shared_ptr<peg::Ast> &ast) const
{
	return ast->token_to_string();
}

std::vector<ITypeName *> VisitorV2::visitTypeList(const std::shared_ptr<peg::Ast> &ast) const
{
	std::vector<ITypeName *> results;

	std::transform(begin(ast->nodes), end(ast->nodes), std::back_inserter(results), [this](auto node)
	{
		return visitTypeName(node);
	});

	return results;
}

std::vector<PrototypeFieldEmbryo> VisitorV2::visitFieldList(const std::shared_ptr<peg::Ast> &ast) const
{
	std::vector<PrototypeFieldEmbryo> results;

	std::transform(begin(ast->nodes), end(ast->nodes), std::back_inserter(results), [this](auto node)
	{
		return visitField(node);
	});

	return results;
}

std::vector<std::string> VisitorV2::visitIdList(const std::shared_ptr<peg::Ast> &ast) const
{
	std::vector<std::string> results;

	std::transform(begin(ast->nodes), end(ast->nodes), std::back_inserter(results), [this](auto node)
	{
		return visitId(node);
	});

	return results;
}

Node *VisitorV2::visitExpression(const std::shared_ptr<peg::Ast> &ast) const
{
	using namespace peg::udl;

	switch (ast->tag)
	{
		case "Expression"_:
			return visitExpression(ast->nodes[0]);
		case "Literal"_:
			return visitLiteral(ast);
		case "Binary"_:
			return visitBinary(ast);
		case "Member"_:
			return visitMember(ast);
		case "Call"_:
			return visitCall(ast);
		case "Instantiation"_:
			return visitInstantiation(ast);
		case "Conditional"_:
			return visitConditional(ast);
		case "Array"_:
			return visitArray(ast);
		case "Group"_:
			return visitGroup(ast);
		case "Expansion"_:
			return visitExpansion(ast);
		case "Local"_:
			return visitLocal(ast);
	}

	throw new std::exception();
}

Node *VisitorV2::visitLiteral(const std::shared_ptr<peg::Ast> &ast) const
{
	using namespace peg::udl;

	switch (ast->tag)
	{
		case "Literal"_:
			return visitLiteral(ast->nodes[0]);
		case "Int32Literal"_:
			return visitInt32Literal(ast);
		case "Int64Literal"_:
			return visitInt64Literal(ast);
		case "BooleanLiteral"_:
			return visitBooleanLiteral(ast);
		case "StringLiteral"_:
			return visitStringLiteral(ast);
		case "Uint32Literal"_:
			return visitUint32Literal(ast);
		case "CharLiteral"_:
			return visitCharLiteral(ast);
		case "ByteLiteral"_:
			return visitByteLiteral(ast);
		case "NothingLiteral"_:
			return visitNothingLiteral(ast);
	}

	throw new std::exception();
}

Node *VisitorV2::visitInt32Literal(const std::shared_ptr<peg::Ast> &ast) const
{
	return new IntegralLiteralNode(m_alpha
		, DzTypeName::int32()
		, visitInteger(ast->nodes[0])
		);
}

Node *VisitorV2::visitInt64Literal(const std::shared_ptr<peg::Ast> &ast) const
{
	return new IntegralLiteralNode(m_alpha
		, DzTypeName::int64()
		, visitInteger(ast->nodes[0])
		);
}

Node *VisitorV2::visitBooleanLiteral(const std::shared_ptr<peg::Ast> &ast) const
{
	return new BooleanLiteralNode(m_alpha
		, ast->token_to_string()
		);
}

Node *VisitorV2::visitStringLiteral(const std::shared_ptr<peg::Ast> &ast) const
{
	return new StringLiteralNode(m_alpha
		, visitString(ast->nodes[0])
		);
}

Node *VisitorV2::visitUint32Literal(const std::shared_ptr<peg::Ast> &ast) const
{
	return new IntegralLiteralNode(m_alpha
		, DzTypeName::uint32()
		, visitInteger(ast->nodes[0])
		);
}

Node *VisitorV2::visitCharLiteral(const std::shared_ptr<peg::Ast> &ast) const
{
	return new CharacterLiteralNode(m_alpha
		, ast->token_to_string()
		);
}

Node *VisitorV2::visitByteLiteral(const std::shared_ptr<peg::Ast> &ast) const
{
	return new IntegralLiteralNode(m_alpha
		, DzTypeName::byte()
		, visitInteger(ast->nodes[0])
		);
}

Node *VisitorV2::visitNothingLiteral(const std::shared_ptr<peg::Ast> &ast) const
{
	UNUSED(ast);

	return new NothingNode(m_alpha);
}

Node *VisitorV2::visitBinary(const std::shared_ptr<peg::Ast> &ast) const
{
	auto binary = new BinaryNode(m_alpha
		, visitId(ast->nodes[1])
		);

	VisitorV2 leftVisitor(m_namespaces, m_iteratorType, binary, nullptr);

	auto left = leftVisitor
		.visitExpression(ast->nodes[0]);

	VisitorV2 rightVisitor(m_namespaces, m_iteratorType, left, nullptr);

	auto right = rightVisitor
		.visitExpression(ast->nodes[2]);

	return right;
}

Node *VisitorV2::visitMember(const std::shared_ptr<peg::Ast> &ast) const
{
	auto access = visitIdList(ast->nodes[0]);

	auto path = std::accumulate(begin(access) + 1, end(access), (*begin(access)), [](auto name, std::string node)
	{
		std::stringstream ss;
		ss << name << "." << node;

		return ss.str();
	});

	auto qualifiedPath = qualifiedNames1(m_namespaces, path);

	if (ast->nodes.size() > 1)
	{
		auto with = visitWith(ast->nodes[1]);

		return new MemberAccessNode(with, ast, qualifiedPath);
	}

	return new MemberAccessNode(m_alpha, ast, qualifiedPath);
}

Node *VisitorV2::visitCall(const std::shared_ptr<peg::Ast> &ast) const
{
	auto names = qualifiedNames1(m_namespaces
		, visitId(ast->nodes[0])
		);

	auto call = new FunctionCallNode(ast, names);
	auto sink = new ReferenceSinkNode(TerminatorNode::instance());

	VisitorV2 visitor(m_namespaces, m_iteratorType, sink, nullptr);

	std::vector<Node *> values;

	std::transform(begin(ast->nodes) + 1, end(ast->nodes), std::back_inserter(values), [&](auto node)
	{
		return visitor.visitExpression(node);
	});

	auto evaluation = new LazyEvaluationNode(call);
	auto withEvaluation = new StackSegmentNode(values, evaluation, TerminatorNode::instance());
	auto withoutEvaluation = new StackSegmentNode(values, call, TerminatorNode::instance());
	auto proxy = new FunctionCallProxyNode(names, m_alpha, withEvaluation, withoutEvaluation);

	return proxy;
}

Node *VisitorV2::visitInstantiation(const std::shared_ptr<peg::Ast> &ast) const
{
	auto typeName = visitTypeName(ast->nodes[0]);

	std::vector<std::string> fields;

	std::transform(begin(ast->nodes) + 1, end(ast->nodes), std::back_insert_iterator(fields), [this](auto assignment)
	{
		return visitId(assignment->nodes[0]);
	});

	auto prototypeProvider = new DefaultPrototypeProvider(typeName);
	auto instantiation = new InstantiationNode(m_alpha
		, prototypeProvider
		, ast
		, fields
		);

	return std::accumulate(begin(ast->nodes) + 1, end(ast->nodes), static_cast<Node *>(instantiation), [this](auto consumer, auto assignment)
	{
		VisitorV2 visitor(m_namespaces, m_iteratorType, consumer, nullptr);

		return visitor
			.visitExpression(assignment->nodes[1]);
	});
}

Node *VisitorV2::visitConditional(const std::shared_ptr<peg::Ast> &ast) const
{
	VisitorV2 blockVisitor(m_namespaces, m_iteratorType, m_beta, nullptr);

	auto block = blockVisitor
		.visitBlock(ast->nodes[1]);

	auto conditional = new ConditionalNode(m_alpha, block);

	VisitorV2 expressionVisitor(m_namespaces, m_iteratorType, conditional, nullptr);

	auto condition = expressionVisitor
		.visitExpression(ast->nodes[0]);

	return new BlockInstructionNode(condition
		, block->containsIterator()
		);
}

Node *VisitorV2::visitArray(const std::shared_ptr<peg::Ast> &ast) const
{
	if (ast->nodes.empty())
	{
		auto empty = new EmptyArrayNode(TerminatorNode::instance());

		return static_cast<Node *>(empty);
	}

	std::vector<Indexed<std::shared_ptr<peg::Ast>>> indexed;

	std::transform(begin(ast->nodes), end(ast->nodes), index_iterator(0u), std::back_insert_iterator(indexed), [=](auto x, auto y) -> Indexed<std::shared_ptr<peg::Ast>>
	{
		return { y, x };
	});

	auto firstValue = std::accumulate(begin(indexed), end(indexed), static_cast<Node *>(TerminatorNode::instance()), [&](auto next, Indexed<std::shared_ptr<peg::Ast>> expression)
	{
		auto indexSink = new IndexSinkNode(expression.index, next);
		auto referenceSink = new ReferenceSinkNode(indexSink);

		VisitorV2 visitor(m_namespaces, m_iteratorType, referenceSink, nullptr);

		return visitor
			.visitExpression(expression.value);
	});

	return new ArraySinkNode(ast->nodes.size(), m_alpha, firstValue);
}

Node *VisitorV2::visitGroup(const std::shared_ptr<peg::Ast> &ast) const
{
	return visitExpression(ast->nodes[0]);
}

Node *VisitorV2::visitExpansion(const std::shared_ptr<peg::Ast> &ast) const
{
	auto expansion = new ExpansionNode(m_alpha, ast);

	VisitorV2 visitor(m_namespaces, m_iteratorType, expansion, nullptr);

	return visitor
		.visitExpression(ast->nodes[0]);
}

Node *VisitorV2::visitLocal(const std::shared_ptr<peg::Ast> &ast) const
{
	auto local = new LocalNode(m_alpha
		, visitId(ast->nodes[0])
		);

	VisitorV2 visitor(m_namespaces, m_iteratorType, local, nullptr);

	return visitor.visitExpression(ast->nodes[1]);
}

Node *VisitorV2::visitContinuation(const std::shared_ptr<peg::Ast> &ast) const
{
	auto continuation = new ContinuationNode();

	return std::accumulate(begin(ast->nodes) + 1, end(ast->nodes), static_cast<Node *>(continuation), [this](Node *consumer, auto parameter)
	{
		VisitorV2 visitor(m_namespaces, m_iteratorType, consumer, nullptr);

		auto result = visitor
			.visitExpression(parameter);

		return result;
	});
}

Node *VisitorV2::visitWith(const std::shared_ptr<peg::Ast> &ast) const
{
	std::vector<std::string> fields;

	std::transform(begin(ast->nodes), end(ast->nodes), std::back_insert_iterator(fields), [this](auto assignment)
	{
		return visitId(assignment->nodes[0]);
	});

	auto instantiation = new InstantiationNode(m_alpha
		, WithPrototypeProvider::instance()
		, ast
		, fields
		);

	return std::accumulate(begin(ast->nodes), end(ast->nodes), static_cast<Node *>(instantiation), [this](auto consumer, auto assignment)
	{
		VisitorV2 visitor(m_namespaces, m_iteratorType, consumer, nullptr);

		return visitor
			.visitExpression(assignment->nodes[1]);
	});
}

CallableNode *VisitorV2::visitFunction(const std::shared_ptr<peg::Ast> &ast) const
{
	using namespace peg::udl;

	switch (ast->tag)
	{
		case "Function"_:
			return visitFunction(ast->nodes[0]);
		case "RegularFunction"_:
			return visitRegularFunction(ast);
		case "ImportedFunction"_:
			return visitImportedFunction(ast);
		case "ExportedFunction"_:
			return visitExportedFunction(ast);
	}

	throw new std::exception();
}

CallableNode *VisitorV2::visitRegularFunction(const std::shared_ptr<peg::Ast> &ast) const
{
	auto name = visitId(ast->nodes[0]);

	std::vector<DzBaseArgument *> arguments;

	std::transform(begin(ast->nodes) + 1, end(ast->nodes) - 1, std::back_inserter(arguments), [this](auto argument)
	{
		return visitArgument(argument);
	});

	auto iteratorType = new IteratorType();

	VisitorV2 visitor(m_namespaces, iteratorType, TerminatorNode::instance(), nullptr);

	auto block = visitor.visitBlock(*ast->nodes.rbegin());

	if (block->containsIterator())
	{
		return new FunctionNode(FunctionAttribute::Iterator, name, arguments, block);
	}

	return new FunctionNode(FunctionAttribute::None, name, arguments, block);
}

CallableNode *VisitorV2::visitExportedFunction(const std::shared_ptr<peg::Ast> &ast) const
{
	auto returnType = visitTypeName(ast->nodes[0]);
	auto name = visitId(ast->nodes[1]);

	auto terminator = new ExportedFunctionTerminatorNode();

	VisitorV2 visitor(m_namespaces, nullptr, terminator, nullptr);

	auto block = visitor.visitBlock(*ast->nodes.rbegin());

	return new ExportedFunctionNode(name, block, returnType);
}

CallableNode *VisitorV2::visitImportedFunction(const std::shared_ptr<peg::Ast> &ast) const
{
	auto returnType = visitTypeName(ast->nodes[0]);
	auto name = visitId(ast->nodes[1]);

	std::vector<DzBaseArgument *> arguments;

	std::transform(begin(ast->nodes) + 2, end(ast->nodes), std::back_inserter(arguments), [this](auto argument)
	{
		return visitArgument(argument);
	});

	return new ImportedFunctionNode(returnType, name, ast, arguments);
}

DzBaseArgument *VisitorV2::visitArgument(const std::shared_ptr<peg::Ast> &ast) const
{
	using namespace peg::udl;

	switch (ast->tag)
	{
		case "Argument"_:
			return visitArgument(ast->nodes[0]);
		case "StandardArgument"_:
			return visitStandardArgument(ast);
		case "TupleArgument"_:
			return visitTupleArgument(ast);
	}

	throw new std::exception();
}

DzBaseArgument *VisitorV2::visitStandardArgument(const std::shared_ptr<peg::Ast> &ast) const
{
	auto type = visitTypeName(ast->nodes[0]);
	auto name = visitId(ast->nodes[1]);

	return new DzArgument(name, type);
}

DzBaseArgument *VisitorV2::visitTupleArgument(const std::shared_ptr<peg::Ast> &ast) const
{
	std::vector<DzBaseArgument *> arguments;

	std::transform(begin(ast->nodes), end(ast->nodes), std::back_inserter(arguments), [this](auto node)
	{
		return visitArgument(node);
	});

	return new DzTupleArgument(arguments);
}

Prototype *VisitorV2::visitStructure(const std::shared_ptr<peg::Ast> &ast) const
{
	auto name = visitId(ast->nodes[0]);
	auto parentTypes = visitTypeList(ast->nodes[1]);
	auto fields = visitFieldList(ast->nodes[2]);

	return new Prototype(name, fields, parentTypes);
}

GlobalNode *VisitorV2::visitGlobal(const std::shared_ptr<peg::Ast> &ast) const
{
	VisitorV2 visitor(m_namespaces, m_iteratorType, TerminatorNode::instance(), nullptr);

	auto literal = visitor
		.visitExpression(ast->nodes[1]);

	return new GlobalNode(literal
		, visitId(ast->nodes[0])
		);
}

Namespace *VisitorV2::visitNamespace(const std::shared_ptr<peg::Ast> &ast) const
{
	auto name = ast->nodes[0]->token_to_string();
	auto namespaces = m_namespaces;

	namespaces.push_back(name);

	VisitorV2 visitor(namespaces
		, m_iteratorType
		, m_alpha
		, m_beta
		);

	std::vector<std::any> children;

	std::transform(begin(ast->nodes) + 1, end(ast->nodes), std::back_inserter(children), [&](auto instruction)
	{
		return visitor.visitInstruction(instruction);
	});

	return new Namespace(children, name);
}

Use *VisitorV2::visitUse(const std::shared_ptr<peg::Ast> &ast) const
{
	return new Use(visitString(ast->nodes[0]));
}

BlockInstructionNode *VisitorV2::visitReturn(const std::shared_ptr<peg::Ast> &ast) const
{
	if (ast->nodes.size() > 1)
	{
		auto continuation = visitContinuation(ast->nodes[1]);

		auto ret = new ReturnNode(m_iteratorType, m_alpha, continuation);

		VisitorV2 visitor(m_namespaces, nullptr, ret, nullptr);

		auto value = visitor
			.visitExpression(ast->nodes[0]);

		return new BlockInstructionNode(value, true);
	}

	auto ret = new ReturnNode(m_iteratorType, m_alpha, nullptr);

	VisitorV2 visitor(m_namespaces, nullptr, ret, nullptr);

	auto value = visitor
		.visitExpression(ast->nodes[0]);

	return new BlockInstructionNode(value, false);
}

BlockInstructionNode *VisitorV2::visitBlock(const std::shared_ptr<peg::Ast> &ast) const
{
	auto first = rbegin(ast->nodes);

	auto ret = visitReturn(*first);

	return std::accumulate(first + 1, rend(ast->nodes), ret, [this](BlockInstructionNode *consumer, auto expression) -> BlockInstructionNode *
	{
		auto stackFrame = new BlockStackFrameNode(consumer);

		VisitorV2 visitor(m_namespaces, m_iteratorType, stackFrame, m_alpha);

		auto value = visitor
			.visitExpression(expression);

		if (auto instruction = dynamic_cast<const BlockInstructionNode *>(value))
		{
			return new BlockInstructionNode(instruction
				, instruction->containsIterator() || consumer->containsIterator()
				);
		}

		return new BlockInstructionNode(value
			, consumer->containsIterator()
			);
	});
}

ITypeName *VisitorV2::visitTypeName(const std::shared_ptr<peg::Ast> &ast) const
{
	using namespace peg::udl;

	switch (ast->tag)
	{
		case "TypeName"_:
			return visitTypeName(ast->nodes[0]);
		case "RegularType"_:
			return visitRegularType(ast);
		case "FunctionType"_:
			return visitFunctionType(ast);
	}

	return nullptr;
}

ITypeName *VisitorV2::visitRegularType(const std::shared_ptr<peg::Ast> &ast) const
{
	auto qualifiedName = qualifiedNames1(m_namespaces
		, visitId(ast->nodes[0])
		);

	return new DzTypeName(ast, qualifiedName);
}

ITypeName *VisitorV2::visitFunctionType(const std::shared_ptr<peg::Ast> &ast) const
{
	std::vector<const ITypeName *> types;

	std::transform(begin(ast->nodes), end(ast->nodes), std::back_inserter(types), [this](auto typeName)
	{
		return visitRegularType(typeName);
	});

	return new FunctionTypeName(types);
}

PrototypeFieldEmbryo VisitorV2::visitField(const std::shared_ptr<peg::Ast> &ast) const
{
	using namespace peg::udl;

	switch (ast->tag)
	{
		case "Field"_:
			return visitField(ast->nodes[0]);
		case "StandardField"_:
			return visitStandardField(ast);
		case "DecoratedField"_:
			return visitDecoratedField(ast);
	}

	throw new std::exception();
}

PrototypeFieldEmbryo VisitorV2::visitStandardField(const std::shared_ptr<peg::Ast> &ast) const
{
	auto name = visitId(ast->nodes[0]);

	if (ast->nodes.size() > 1)
	{
		VisitorV2 visitor(m_namespaces, m_iteratorType, TerminatorNode::instance(), nullptr);

		auto defaultValue = visitor
			.visitExpression(ast->nodes[1]);

		return { name, defaultValue, nullptr };
	}

	return { name, nullptr, nullptr };
}

PrototypeFieldEmbryo VisitorV2::visitDecoratedField(const std::shared_ptr<peg::Ast> &ast) const
{
	auto type = visitTypeName(ast->nodes[0]);
	auto name = visitId(ast->nodes[1]);

	if (ast->nodes.size() > 2)
	{
		VisitorV2 visitor(m_namespaces, m_iteratorType, TerminatorNode::instance(), nullptr);

		auto defaultValue = visitor
			.visitExpression(ast->nodes[2]);

		return { name, defaultValue, type };
	}

	return { name, nullptr, type };
}
