QT += testlib

CONFIG += DEBUG

SOURCES += \
	CallContext.cpp \
	CompilerException.cpp \
	DebugPrinter.cpp \
	DzBinary.cpp \
	DzClosure.cpp \
	DzClosureAccessor.cpp \
	DzConstant.cpp \
	DzConsumer.cpp \
	DzFunction.cpp \
	DzFunctionCall.cpp \
	DzMember.cpp \
	DzMemberAccess.cpp \
	DzParameter.cpp \
	DzReturn.cpp \
	DzTerminator.cpp \
	DzTypeName.cpp \
	EntryPoint.cpp \
	KaleidoscopeJIT.cpp \
	Tests.cpp \
	UndeclaredIdentifierException.cpp \
	UnknownTypeException.cpp \
	VisitorV1.cpp \
	VisitorV2.cpp \
	VisitorV3.cpp \
	main.cpp \
	antlr4-runtime/dzBaseVisitor.cpp \
	antlr4-runtime/dzLexer.cpp \
	antlr4-runtime/dzParser.cpp \
	antlr4-runtime/dzVisitor.cpp

HEADERS += \
	CallContext.h \
	CompilerException.h \
	DebugPrinter.h \
	DzBinary.h \
	DzClosure.h \
	DzClosureAccessor.h \
	DzConstant.h \
	DzConsumer.h \
	DzFunction.h \
	DzFunctionCall.h \
	DzMember.h \
	DzMemberAccess.h \
	DzParameter.h \
	DzReturn.h \
	DzTerminator.h \
	DzTypeName.h \
	DzValue.h \
	EntryPoint.h \
	FunctionAttribute.h \
	KaleidoscopeJIT.h \
	Tests.h \
	UndeclaredIdentifierException.h \
	UnknownTypeException.h \
	VisitorV1.h \
	VisitorV2.h \
	VisitorV3.h \
	antlr4-runtime/dzBaseVisitor.h \
	antlr4-runtime/dzLexer.h \
	antlr4-runtime/dzParser.h \
	antlr4-runtime/dzVisitor.h \
	wobjectdefs.h \
	wobjectimpl.h

OTHER_FILES += dz.g4 \
        main.dz \
	foo.dz

LIBS += -lLLVM-12 -lantlr4-runtime

DEPENDPATH += /usr/include/antlr4-runtime
INCLUDEPATH += /usr/include/antlr4-runtime
