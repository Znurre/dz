QT += testlib

CONFIG += DEBUG c++17

SOURCES += \
	AllIterator.cpp \
	nodes/ArrayContinuationNode.cpp \
	nodes/ArrayElementNode.cpp \
	nodes/ArraySinkNode.cpp \
	nodes/BinaryNode.cpp \
	nodes/BlockInstructionNode.cpp \
	nodes/BlockStackFrameNode.cpp \
	nodes/BooleanLiteralNode.cpp \
	nodes/CharacterLiteralNode.cpp \
	nodes/ConditionalNode.cpp \
	nodes/ContinuationNode.cpp \
	nodes/EmptyArrayNode.cpp \
	nodes/ExpansionNode.cpp \
	nodes/ExportedFunctionNode.cpp \
	nodes/ExportedFunctionTerminator.cpp \
	nodes/FunctionCallProxy.cpp \
	nodes/FunctionNode.cpp \
	nodes/GlobalNode.cpp \
	nodes/ImportedFunctionNode.cpp \
	nodes/IndexSinkNode.cpp \
	nodes/InstantiationNode.cpp \
	nodes/IntegralLiteralNode.cpp \
	nodes/JunctionNode.cpp \
	nodes/LazyEvaluationNode.cpp \
	nodes/LazySinkNode.cpp \
	nodes/LocalNode.cpp \
	nodes/MemberAccessNode.cpp \
	Namespace.cpp \
	nodes/ReferenceSinkNode.cpp \
	nodes/ReturnNode.cpp \
	nodes/StackSegmentNode.cpp \
	nodes/FunctionCall.cpp \
	CompilerException.cpp \
	DefaultPrototypeProvider.cpp \
	DzArgument.cpp \
	DzTupleArgument.cpp \
	DzTypeName.cpp \
	EntryPoint.cpp \
	FunctionNotFoundException.cpp \
	FunctionTypeName.cpp \
	IRBuilderEx.cpp \
	IndexIterator.cpp \
	InteropHelper.cpp \
	IteratorStorage.cpp \
	Node.cpp \
	Stack.cpp \
	nodes/StringLiteralNode.cpp \
	nodes/TaintedSinkNode.cpp \
	Type.cpp \
	UndeclaredIdentifierException.cpp \
	UnknownTypeException.cpp \
	Utility.cpp \
	ValueHelper.cpp \
	VisitorV1.cpp \
	VisitorV4.cpp \
	WithPrototypeProvider.cpp \
	main.cpp \
	antlr4-runtime/dzBaseVisitor.cpp \
	antlr4-runtime/dzLexer.cpp \
	antlr4-runtime/dzParser.cpp \
	antlr4-runtime/dzVisitor.cpp \
	nodes/TerminatorNode.cpp \
	types/AnyType.cpp \
	types/ArrayType.cpp \
	types/BooleanType.cpp \
	types/ByteType.cpp \
	types/FunctionType.cpp \
	types/Int32Type.cpp \
	types/Int64Type.cpp \
	types/Prototype.cpp \
	types/PrototypeField.cpp \
	types/PrototypeFieldEmbryo.cpp \
	types/StringType.cpp \
	types/TupleType.cpp \
	types/Uint32Type.cpp \
	types/UserType.cpp \
	types/UserTypeField.cpp \
	types/VoidType.cpp \
	types/WithPrototype.cpp \
	types/WithoutType.cpp \
	values/ArrayValue.cpp \
	values/ArrayValueGenerator.cpp \
	values/DependentValue.cpp \
	values/ExpandableValue.cpp \
	values/FunctionValue.cpp \
	values/IteratorValue.cpp \
	values/IteratorValueGenerator.cpp \
	values/LazyValue.cpp \
	values/NamedValue.cpp \
	values/ReferenceValue.cpp \
	values/ScalarValue.cpp \
	values/TaintedValue.cpp \
	values/TupleValue.cpp \
	values/IndexedValue.cpp \
	values/UserTypeValue.cpp \
	values/WithoutValue.cpp

HEADERS += \
	AllIterator.h \
	nodes/ArrayContinuationNode.h \
	nodes/ArrayElementNode.h \
	nodes/ArraySinkNode.h \
	nodes/BinaryNode.h \
	nodes/BlockInstructionNode.h \
	nodes/BlockStackFrameNode.h \
	nodes/BooleanLiteralNode.h \
	nodes/CallableNode.h \
	nodes/CharacterLiteralNode.h \
	nodes/ConditionalNode.h \
	nodes/ContinuationNode.h \
	nodes/EmptyArrayNode.h \
	nodes/ExpansionNode.h \
	nodes/ExportedFunctionNode.h \
	nodes/ExportedFunctionTerminator.h \
	nodes/FunctionCallProxy.h \
	nodes/FunctionNode.h \
	nodes/GlobalNode.h \
	nodes/ImportedFunctionNode.h \
	nodes/IndexSinkNode.h \
	nodes/InstantiationNode.h \
	nodes/IntegralLiteralNode.h \
	nodes/JunctionNode.h \
	nodes/LazyEvaluationNode.h \
	nodes/LazySinkNode.h \
	nodes/LocalNode.h \
	nodes/MemberAccessNode.h \
	Namespace.h \
	nodes/ReferenceSinkNode.h \
	nodes/ReturnNode.h \
	nodes/StackSegmentNode.h \
	nodes/FunctionCall.h \
	CompilerException.h \
	DefaultPrototypeProvider.h \
	DzArgument.h \
	DzBaseArgument.h \
	DzTupleArgument.h \
	DzTypeName.h \
	EntryPoint.h \
	FunctionAttribute.h \
	FunctionNotFoundException.h \
	FunctionTypeName.h \
	IPrototypeProvider.h \
	IRBuilderEx.h \
	ITypeName.h \
	IndexIterator.h \
	Indexed.h \
	InteropHelper.h \
	IteratorStorage.h \
	KaleidoscopeJIT.h \
	Node.h \
	Stack.h \
	nodes/StringLiteralNode.h \
	nodes/TaintedSinkNode.h \
	Tests.h \
	UndeclaredIdentifierException.h \
	UnknownTypeException.h \
	Utility.h \
	ValueHelper.h \
	VisitorV4.h \
	VoidIterator.h \
	WithPrototypeProvider.h \
	ZipIterator.h \
	antlr4-runtime/dzBaseVisitor.h \
	antlr4-runtime/dzLexer.h \
	antlr4-runtime/dzParser.h \
	antlr4-runtime/dzVisitor.h \
	nodes/TerminatorNode.h \
	types/AnyType.h \
	types/ArrayType.h \
	types/BooleanType.h \
	types/BuiltinType.h \
	types/ByteType.h \
	types/FunctionType.h \
	types/IPrototype.h \
	types/Int32Type.h \
	types/Int64Type.h \
	types/IteratorType.h \
	types/Prototype.h \
	types/PrototypeField.h \
	types/PrototypeFieldEmbryo.h \
	types/StringType.h \
	Type.h \
	types/TupleType.h \
	types/Uint32Type.h \
	types/UserType.h \
	types/UserTypeField.h \
	types/VoidType.h \
	types/WithPrototype.h \
	types/WithoutType.h \
	values/ArrayValue.h \
	values/ArrayValueGenerator.h \
	values/BaseValue.h \
	values/DependentValue.h \
	values/ExpandableValue.h \
	values/FunctionValue.h \
	values/IIteratable.h \
	values/ILazyValueGenerator.h \
	values/IndexedValue.h \
	values/IteratorValue.h \
	values/IteratorValueGenerator.h \
	values/LazyValue.h \
	values/NamedValue.h \
	values/ReferenceValue.h \
	values/ScalarValue.h \
	values/TaintedValue.h \
	values/TupleValue.h \
	values/UserTypeValue.h \
	values/WithoutValue.h \
	wobjectdefs.h \
	wobjectimpl.h

OTHER_FILES += dz.g4 \
        main.dz \
	foo.dz

#QMAKE_CXXFLAGS += -std=c++20

LIBS += \
#    -L/home/znurre/Program/Develop/C++/llvm-project/build/lib/ \
#    -lLLVM-15git \
    -lLLVM-13 \
    -lantlr4-runtime

DEPENDPATH += /usr/include/antlr4-runtime # \
    #/home/znurre/Program/Develop/C++/llvm-project/llvm/include/ \
    #/home/znurre/Program/Develop/C++/llvm-project/build/include/
INCLUDEPATH += /usr/include/antlr4-runtime # \
    #/home/znurre/Program/Develop/C++/llvm-project/llvm/include/ \
    #/home/znurre/Program/Develop/C++/llvm-project/build/include/
