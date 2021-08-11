#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Module.h>

class DzCallable;

class EntryPoint
{
	public:
		EntryPoint(llvm::BasicBlock *block
			, llvm::Function *function
			, llvm::Value *returnValueAddress
			, std::unique_ptr<llvm::Module> *module
			, std::unique_ptr<llvm::LLVMContext> *context
			, const std::string &name
			, const std::multimap<std::string, DzCallable *> &functions
			, const std::map<std::string, llvm::Value *> &locals
			);

		EntryPoint() = default;
		EntryPoint(const EntryPoint &) = default;

		llvm::BasicBlock *block() const;
		llvm::Function *function() const;
		llvm::Value *returnValueAddress() const;

		std::unique_ptr<llvm::Module> &module() const;
		std::unique_ptr<llvm::LLVMContext> &context() const;

		std::string name() const;

		std::multimap<std::string, DzCallable *> functions() const;
		std::map<std::string, llvm::Value *> locals() const;

		EntryPoint withBlock(llvm::BasicBlock *block) const;
		EntryPoint withFunction(llvm::Function *function) const;
		EntryPoint withLocals(const std::map<std::string, llvm::Value *> &locals) const;
		EntryPoint withName(const std::string &name) const;
		EntryPoint withReturnValueAddress(llvm::Value *address) const;

	private:
		llvm::BasicBlock *m_block;
		llvm::Function *m_function;
		llvm::Value *m_returnValueAddress;

		std::unique_ptr<llvm::Module> *m_module;
		std::unique_ptr<llvm::LLVMContext> *m_context;

		std::string m_name;

		std::multimap<std::string, DzCallable *> m_functions;
		std::map<std::string, llvm::Value *> m_locals;
};

#endif // ENTRYPOINT_H
