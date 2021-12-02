
// Generated from dz.g4 by ANTLR 4.9.2


#include "dzVisitor.h"

#include "dzParser.h"


using namespace antlrcpp;
using namespace antlr4;

dzParser::dzParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

dzParser::~dzParser() {
  delete _interpreter;
}

std::string dzParser::getGrammarFileName() const {
  return "dz.g4";
}

const std::vector<std::string>& dzParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& dzParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

dzParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> dzParser::ProgramContext::COMMENT() {
  return getTokens(dzParser::COMMENT);
}

tree::TerminalNode* dzParser::ProgramContext::COMMENT(size_t i) {
  return getToken(dzParser::COMMENT, i);
}

std::vector<dzParser::FunctionContext *> dzParser::ProgramContext::function() {
  return getRuleContexts<dzParser::FunctionContext>();
}

dzParser::FunctionContext* dzParser::ProgramContext::function(size_t i) {
  return getRuleContext<dzParser::FunctionContext>(i);
}

std::vector<dzParser::StructureContext *> dzParser::ProgramContext::structure() {
  return getRuleContexts<dzParser::StructureContext>();
}

dzParser::StructureContext* dzParser::ProgramContext::structure(size_t i) {
  return getRuleContext<dzParser::StructureContext>(i);
}

std::vector<dzParser::GlobalContext *> dzParser::ProgramContext::global() {
  return getRuleContexts<dzParser::GlobalContext>();
}

dzParser::GlobalContext* dzParser::ProgramContext::global(size_t i) {
  return getRuleContext<dzParser::GlobalContext>(i);
}


size_t dzParser::ProgramContext::getRuleIndex() const {
  return dzParser::RuleProgram;
}


antlrcpp::Any dzParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

dzParser::ProgramContext* dzParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, dzParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << dzParser::T__0)
      | (1ULL << dzParser::T__5)
      | (1ULL << dzParser::T__16)
      | (1ULL << dzParser::COMMENT)
      | (1ULL << dzParser::ID))) != 0)) {
      setState(32);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case dzParser::COMMENT: {
          setState(28);
          match(dzParser::COMMENT);
          break;
        }

        case dzParser::T__16:
        case dzParser::ID: {
          setState(29);
          function();
          break;
        }

        case dzParser::T__0: {
          setState(30);
          structure();
          break;
        }

        case dzParser::T__5: {
          setState(31);
          global();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(36);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructureContext ------------------------------------------------------------------

dzParser::StructureContext::StructureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<dzParser::FieldContext *> dzParser::StructureContext::field() {
  return getRuleContexts<dzParser::FieldContext>();
}

dzParser::FieldContext* dzParser::StructureContext::field(size_t i) {
  return getRuleContext<dzParser::FieldContext>(i);
}

tree::TerminalNode* dzParser::StructureContext::ID() {
  return getToken(dzParser::ID, 0);
}

std::vector<dzParser::TypeNameContext *> dzParser::StructureContext::typeName() {
  return getRuleContexts<dzParser::TypeNameContext>();
}

dzParser::TypeNameContext* dzParser::StructureContext::typeName(size_t i) {
  return getRuleContext<dzParser::TypeNameContext>(i);
}


size_t dzParser::StructureContext::getRuleIndex() const {
  return dzParser::RuleStructure;
}


antlrcpp::Any dzParser::StructureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitStructure(this);
  else
    return visitor->visitChildren(this);
}

dzParser::StructureContext* dzParser::structure() {
  StructureContext *_localctx = _tracker.createInstance<StructureContext>(_ctx, getState());
  enterRule(_localctx, 2, dzParser::RuleStructure);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(37);
    match(dzParser::T__0);
    setState(38);
    dynamic_cast<StructureContext *>(_localctx)->name = match(dzParser::ID);
    setState(48);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == dzParser::T__1) {
      setState(39);
      match(dzParser::T__1);
      setState(40);
      typeName();
      setState(45);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == dzParser::T__2) {
        setState(41);
        match(dzParser::T__2);
        setState(42);
        typeName();
        setState(47);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(50);
    match(dzParser::T__3);
    setState(51);
    field();
    setState(56);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == dzParser::T__2) {
      setState(52);
      match(dzParser::T__2);
      setState(53);
      field();
      setState(58);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(59);
    match(dzParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlobalContext ------------------------------------------------------------------

dzParser::GlobalContext::GlobalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* dzParser::GlobalContext::ID() {
  return getToken(dzParser::ID, 0);
}

dzParser::LiteralContext* dzParser::GlobalContext::literal() {
  return getRuleContext<dzParser::LiteralContext>(0);
}


size_t dzParser::GlobalContext::getRuleIndex() const {
  return dzParser::RuleGlobal;
}


antlrcpp::Any dzParser::GlobalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitGlobal(this);
  else
    return visitor->visitChildren(this);
}

dzParser::GlobalContext* dzParser::global() {
  GlobalContext *_localctx = _tracker.createInstance<GlobalContext>(_ctx, getState());
  enterRule(_localctx, 4, dzParser::RuleGlobal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    match(dzParser::T__5);
    setState(62);
    match(dzParser::ID);
    setState(63);
    match(dzParser::T__1);
    setState(64);
    literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

dzParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

dzParser::FieldContext* dzParser::AssignmentContext::field() {
  return getRuleContext<dzParser::FieldContext>(0);
}

dzParser::ExpressionContext* dzParser::AssignmentContext::expression() {
  return getRuleContext<dzParser::ExpressionContext>(0);
}


size_t dzParser::AssignmentContext::getRuleIndex() const {
  return dzParser::RuleAssignment;
}


antlrcpp::Any dzParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

dzParser::AssignmentContext* dzParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 6, dzParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    field();
    setState(67);
    match(dzParser::T__1);
    setState(68);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldContext ------------------------------------------------------------------

dzParser::FieldContext::FieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* dzParser::FieldContext::ID() {
  return getToken(dzParser::ID, 0);
}

dzParser::TypeNameContext* dzParser::FieldContext::typeName() {
  return getRuleContext<dzParser::TypeNameContext>(0);
}

dzParser::ExpressionContext* dzParser::FieldContext::expression() {
  return getRuleContext<dzParser::ExpressionContext>(0);
}


size_t dzParser::FieldContext::getRuleIndex() const {
  return dzParser::RuleField;
}


antlrcpp::Any dzParser::FieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitField(this);
  else
    return visitor->visitChildren(this);
}

dzParser::FieldContext* dzParser::field() {
  FieldContext *_localctx = _tracker.createInstance<FieldContext>(_ctx, getState());
  enterRule(_localctx, 8, dzParser::RuleField);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(70);
      typeName();
      break;
    }

    default:
      break;
    }
    setState(73);
    match(dzParser::ID);
    setState(76);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(74);
      match(dzParser::T__1);
      setState(75);
      expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

dzParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

dzParser::TypeNameContext* dzParser::FunctionContext::typeName() {
  return getRuleContext<dzParser::TypeNameContext>(0);
}

std::vector<tree::TerminalNode *> dzParser::FunctionContext::ID() {
  return getTokens(dzParser::ID);
}

tree::TerminalNode* dzParser::FunctionContext::ID(size_t i) {
  return getToken(dzParser::ID, i);
}

std::vector<dzParser::ArgumentContext *> dzParser::FunctionContext::argument() {
  return getRuleContexts<dzParser::ArgumentContext>();
}

dzParser::ArgumentContext* dzParser::FunctionContext::argument(size_t i) {
  return getRuleContext<dzParser::ArgumentContext>(i);
}

dzParser::BlockContext* dzParser::FunctionContext::block() {
  return getRuleContext<dzParser::BlockContext>(0);
}


size_t dzParser::FunctionContext::getRuleIndex() const {
  return dzParser::RuleFunction;
}


antlrcpp::Any dzParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

dzParser::FunctionContext* dzParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 10, dzParser::RuleFunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(78);
      dynamic_cast<FunctionContext *>(_localctx)->attribute = match(dzParser::ID);
      break;
    }

    default:
      break;
    }
    setState(81);
    typeName();
    setState(82);
    dynamic_cast<FunctionContext *>(_localctx)->name = match(dzParser::ID);
    setState(83);
    match(dzParser::T__6);
    setState(92);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << dzParser::T__6)
      | (1ULL << dzParser::T__16)
      | (1ULL << dzParser::ID))) != 0)) {
      setState(84);
      argument();
      setState(89);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == dzParser::T__2) {
        setState(85);
        match(dzParser::T__2);
        setState(86);
        argument();
        setState(91);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(94);
    match(dzParser::T__7);
    setState(96);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == dzParser::T__3) {
      setState(95);
      block();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

dzParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t dzParser::LiteralContext::getRuleIndex() const {
  return dzParser::RuleLiteral;
}

void dzParser::LiteralContext::copyFrom(LiteralContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StringLiteralContext ------------------------------------------------------------------

tree::TerminalNode* dzParser::StringLiteralContext::STRING() {
  return getToken(dzParser::STRING, 0);
}

dzParser::StringLiteralContext::StringLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::StringLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitStringLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Uint32LiteralContext ------------------------------------------------------------------

tree::TerminalNode* dzParser::Uint32LiteralContext::INT() {
  return getToken(dzParser::INT, 0);
}

dzParser::Uint32LiteralContext::Uint32LiteralContext(LiteralContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::Uint32LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitUint32Literal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NothingContext ------------------------------------------------------------------

dzParser::NothingContext::NothingContext(LiteralContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::NothingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitNothing(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharLiteralContext ------------------------------------------------------------------

tree::TerminalNode* dzParser::CharLiteralContext::CHARACTER() {
  return getToken(dzParser::CHARACTER, 0);
}

dzParser::CharLiteralContext::CharLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::CharLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitCharLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Int64LiteralContext ------------------------------------------------------------------

tree::TerminalNode* dzParser::Int64LiteralContext::INT() {
  return getToken(dzParser::INT, 0);
}

dzParser::Int64LiteralContext::Int64LiteralContext(LiteralContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::Int64LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitInt64Literal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolLiteralContext ------------------------------------------------------------------

tree::TerminalNode* dzParser::BoolLiteralContext::BOOL() {
  return getToken(dzParser::BOOL, 0);
}

dzParser::BoolLiteralContext::BoolLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::BoolLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitBoolLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Int32LiteralContext ------------------------------------------------------------------

tree::TerminalNode* dzParser::Int32LiteralContext::INT() {
  return getToken(dzParser::INT, 0);
}

dzParser::Int32LiteralContext::Int32LiteralContext(LiteralContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::Int32LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitInt32Literal(this);
  else
    return visitor->visitChildren(this);
}
dzParser::LiteralContext* dzParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 12, dzParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(107);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<dzParser::Int32LiteralContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(98);
      match(dzParser::INT);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<dzParser::Int64LiteralContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(99);
      match(dzParser::INT);
      setState(100);
      match(dzParser::T__8);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<dzParser::BoolLiteralContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(101);
      match(dzParser::BOOL);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<dzParser::StringLiteralContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(102);
      match(dzParser::STRING);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<dzParser::Uint32LiteralContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(103);
      match(dzParser::INT);
      setState(104);
      match(dzParser::T__9);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<dzParser::CharLiteralContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(105);
      match(dzParser::CHARACTER);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<dzParser::NothingContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(106);
      match(dzParser::T__10);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WithContext ------------------------------------------------------------------

dzParser::WithContext::WithContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<dzParser::AssignmentContext *> dzParser::WithContext::assignment() {
  return getRuleContexts<dzParser::AssignmentContext>();
}

dzParser::AssignmentContext* dzParser::WithContext::assignment(size_t i) {
  return getRuleContext<dzParser::AssignmentContext>(i);
}


size_t dzParser::WithContext::getRuleIndex() const {
  return dzParser::RuleWith;
}


antlrcpp::Any dzParser::WithContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitWith(this);
  else
    return visitor->visitChildren(this);
}

dzParser::WithContext* dzParser::with() {
  WithContext *_localctx = _tracker.createInstance<WithContext>(_ctx, getState());
  enterRule(_localctx, 14, dzParser::RuleWith);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    match(dzParser::T__11);
    setState(110);
    match(dzParser::T__3);
    setState(111);
    assignment();
    setState(116);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == dzParser::T__2) {
      setState(112);
      match(dzParser::T__2);
      setState(113);
      assignment();
      setState(118);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(119);
    match(dzParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

dzParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t dzParser::ExpressionContext::getRuleIndex() const {
  return dzParser::RuleExpression;
}

void dzParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CallContext ------------------------------------------------------------------

tree::TerminalNode* dzParser::CallContext::ID() {
  return getToken(dzParser::ID, 0);
}

std::vector<dzParser::ExpressionContext *> dzParser::CallContext::expression() {
  return getRuleContexts<dzParser::ExpressionContext>();
}

dzParser::ExpressionContext* dzParser::CallContext::expression(size_t i) {
  return getRuleContext<dzParser::ExpressionContext>(i);
}

dzParser::CallContext::CallContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstantContext ------------------------------------------------------------------

dzParser::LiteralContext* dzParser::ConstantContext::literal() {
  return getRuleContext<dzParser::LiteralContext>(0);
}

dzParser::ConstantContext::ConstantContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConditionalContext ------------------------------------------------------------------

dzParser::ExpressionContext* dzParser::ConditionalContext::expression() {
  return getRuleContext<dzParser::ExpressionContext>(0);
}

dzParser::BlockContext* dzParser::ConditionalContext::block() {
  return getRuleContext<dzParser::BlockContext>(0);
}

dzParser::ConditionalContext::ConditionalContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::ConditionalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitConditional(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayContext ------------------------------------------------------------------

std::vector<dzParser::ExpressionContext *> dzParser::ArrayContext::expression() {
  return getRuleContexts<dzParser::ExpressionContext>();
}

dzParser::ExpressionContext* dzParser::ArrayContext::expression(size_t i) {
  return getRuleContext<dzParser::ExpressionContext>(i);
}

dzParser::ArrayContext::ArrayContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::ArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitArray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryContext ------------------------------------------------------------------

std::vector<dzParser::ExpressionContext *> dzParser::BinaryContext::expression() {
  return getRuleContexts<dzParser::ExpressionContext>();
}

dzParser::ExpressionContext* dzParser::BinaryContext::expression(size_t i) {
  return getRuleContext<dzParser::ExpressionContext>(i);
}

tree::TerminalNode* dzParser::BinaryContext::OP() {
  return getToken(dzParser::OP, 0);
}

dzParser::BinaryContext::BinaryContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::BinaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitBinary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> dzParser::MemberContext::ID() {
  return getTokens(dzParser::ID);
}

tree::TerminalNode* dzParser::MemberContext::ID(size_t i) {
  return getToken(dzParser::ID, i);
}

dzParser::WithContext* dzParser::MemberContext::with() {
  return getRuleContext<dzParser::WithContext>(0);
}

dzParser::MemberContext::MemberContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::MemberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitMember(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InstantiationContext ------------------------------------------------------------------

dzParser::TypeNameContext* dzParser::InstantiationContext::typeName() {
  return getRuleContext<dzParser::TypeNameContext>(0);
}

std::vector<dzParser::AssignmentContext *> dzParser::InstantiationContext::assignment() {
  return getRuleContexts<dzParser::AssignmentContext>();
}

dzParser::AssignmentContext* dzParser::InstantiationContext::assignment(size_t i) {
  return getRuleContext<dzParser::AssignmentContext>(i);
}

dzParser::InstantiationContext::InstantiationContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::InstantiationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitInstantiation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GroupContext ------------------------------------------------------------------

dzParser::ExpressionContext* dzParser::GroupContext::expression() {
  return getRuleContext<dzParser::ExpressionContext>(0);
}

dzParser::GroupContext::GroupContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::GroupContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitGroup(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExpansionContext ------------------------------------------------------------------

dzParser::ExpressionContext* dzParser::ExpansionContext::expression() {
  return getRuleContext<dzParser::ExpressionContext>(0);
}

dzParser::ExpansionContext::ExpansionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::ExpansionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitExpansion(this);
  else
    return visitor->visitChildren(this);
}

dzParser::ExpressionContext* dzParser::expression() {
   return expression(0);
}

dzParser::ExpressionContext* dzParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  dzParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  dzParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, dzParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(185);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(122);
      match(dzParser::ID);
      setState(123);
      match(dzParser::T__6);
      setState(132);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << dzParser::T__6)
        | (1ULL << dzParser::T__10)
        | (1ULL << dzParser::T__13)
        | (1ULL << dzParser::T__14)
        | (1ULL << dzParser::T__16)
        | (1ULL << dzParser::INT)
        | (1ULL << dzParser::BOOL)
        | (1ULL << dzParser::STRING)
        | (1ULL << dzParser::CHARACTER)
        | (1ULL << dzParser::ID))) != 0)) {
        setState(124);
        expression(0);
        setState(129);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == dzParser::T__2) {
          setState(125);
          match(dzParser::T__2);
          setState(126);
          expression(0);
          setState(131);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(134);
      match(dzParser::T__7);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ConstantContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(135);
      literal();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MemberContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(136);
      match(dzParser::ID);
      setState(141);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(137);
          match(dzParser::T__12);
          setState(138);
          match(dzParser::ID); 
        }
        setState(143);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
      }
      setState(145);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(144);
        with();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<InstantiationContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(147);
      typeName();
      setState(148);
      match(dzParser::T__3);
      setState(150);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == dzParser::T__16

      || _la == dzParser::ID) {
        setState(149);
        assignment();
      }
      setState(156);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == dzParser::T__2) {
        setState(152);
        match(dzParser::T__2);
        setState(153);
        assignment();
        setState(158);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(159);
      match(dzParser::T__4);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ConditionalContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(161);
      match(dzParser::T__13);
      setState(162);
      match(dzParser::T__6);
      setState(163);
      expression(0);
      setState(164);
      match(dzParser::T__7);
      setState(165);
      block();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ArrayContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(167);
      match(dzParser::T__14);
      setState(169);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << dzParser::T__6)
        | (1ULL << dzParser::T__10)
        | (1ULL << dzParser::T__13)
        | (1ULL << dzParser::T__14)
        | (1ULL << dzParser::T__16)
        | (1ULL << dzParser::INT)
        | (1ULL << dzParser::BOOL)
        | (1ULL << dzParser::STRING)
        | (1ULL << dzParser::CHARACTER)
        | (1ULL << dzParser::ID))) != 0)) {
        setState(168);
        expression(0);
      }
      setState(175);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == dzParser::T__2) {
        setState(171);
        match(dzParser::T__2);
        setState(172);
        expression(0);
        setState(177);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(178);
      match(dzParser::T__15);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<GroupContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(179);
      match(dzParser::T__6);
      setState(180);
      expression(0);
      setState(181);
      match(dzParser::T__7);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ExpansionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(183);
      match(dzParser::T__16);
      setState(184);
      expression(1);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(192);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<BinaryContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->left = previousContext;
        pushNewRecursionContext(newContext, startState, RuleExpression);
        setState(187);

        if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
        setState(188);
        dynamic_cast<BinaryContext *>(_localctx)->op = match(dzParser::OP);
        setState(189);
        dynamic_cast<BinaryContext *>(_localctx)->right = expression(8); 
      }
      setState(194);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ContinuationContext ------------------------------------------------------------------

dzParser::ContinuationContext::ContinuationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<dzParser::ExpressionContext *> dzParser::ContinuationContext::expression() {
  return getRuleContexts<dzParser::ExpressionContext>();
}

dzParser::ExpressionContext* dzParser::ContinuationContext::expression(size_t i) {
  return getRuleContext<dzParser::ExpressionContext>(i);
}


size_t dzParser::ContinuationContext::getRuleIndex() const {
  return dzParser::RuleContinuation;
}


antlrcpp::Any dzParser::ContinuationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitContinuation(this);
  else
    return visitor->visitChildren(this);
}

dzParser::ContinuationContext* dzParser::continuation() {
  ContinuationContext *_localctx = _tracker.createInstance<ContinuationContext>(_ctx, getState());
  enterRule(_localctx, 18, dzParser::RuleContinuation);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(195);
    match(dzParser::T__6);
    setState(204);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << dzParser::T__6)
      | (1ULL << dzParser::T__10)
      | (1ULL << dzParser::T__13)
      | (1ULL << dzParser::T__14)
      | (1ULL << dzParser::T__16)
      | (1ULL << dzParser::INT)
      | (1ULL << dzParser::BOOL)
      | (1ULL << dzParser::STRING)
      | (1ULL << dzParser::CHARACTER)
      | (1ULL << dzParser::ID))) != 0)) {
      setState(196);
      expression(0);
      setState(201);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == dzParser::T__2) {
        setState(197);
        match(dzParser::T__2);
        setState(198);
        expression(0);
        setState(203);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(206);
    match(dzParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetContext ------------------------------------------------------------------

dzParser::RetContext::RetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

dzParser::ExpressionContext* dzParser::RetContext::expression() {
  return getRuleContext<dzParser::ExpressionContext>(0);
}

dzParser::ContinuationContext* dzParser::RetContext::continuation() {
  return getRuleContext<dzParser::ContinuationContext>(0);
}


size_t dzParser::RetContext::getRuleIndex() const {
  return dzParser::RuleRet;
}


antlrcpp::Any dzParser::RetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitRet(this);
  else
    return visitor->visitChildren(this);
}

dzParser::RetContext* dzParser::ret() {
  RetContext *_localctx = _tracker.createInstance<RetContext>(_ctx, getState());
  enterRule(_localctx, 20, dzParser::RuleRet);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(208);
    match(dzParser::T__17);
    setState(210);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << dzParser::T__6)
      | (1ULL << dzParser::T__10)
      | (1ULL << dzParser::T__13)
      | (1ULL << dzParser::T__14)
      | (1ULL << dzParser::T__16)
      | (1ULL << dzParser::INT)
      | (1ULL << dzParser::BOOL)
      | (1ULL << dzParser::STRING)
      | (1ULL << dzParser::CHARACTER)
      | (1ULL << dzParser::ID))) != 0)) {
      setState(209);
      dynamic_cast<RetContext *>(_localctx)->value = expression(0);
    }
    setState(214);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == dzParser::T__18) {
      setState(212);
      match(dzParser::T__18);
      setState(213);
      dynamic_cast<RetContext *>(_localctx)->chained = continuation();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

dzParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

dzParser::RetContext* dzParser::BlockContext::ret() {
  return getRuleContext<dzParser::RetContext>(0);
}

std::vector<dzParser::ExpressionContext *> dzParser::BlockContext::expression() {
  return getRuleContexts<dzParser::ExpressionContext>();
}

dzParser::ExpressionContext* dzParser::BlockContext::expression(size_t i) {
  return getRuleContext<dzParser::ExpressionContext>(i);
}


size_t dzParser::BlockContext::getRuleIndex() const {
  return dzParser::RuleBlock;
}


antlrcpp::Any dzParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

dzParser::BlockContext* dzParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 22, dzParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(216);
    match(dzParser::T__3);
    setState(220);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << dzParser::T__6)
      | (1ULL << dzParser::T__10)
      | (1ULL << dzParser::T__13)
      | (1ULL << dzParser::T__14)
      | (1ULL << dzParser::T__16)
      | (1ULL << dzParser::INT)
      | (1ULL << dzParser::BOOL)
      | (1ULL << dzParser::STRING)
      | (1ULL << dzParser::CHARACTER)
      | (1ULL << dzParser::ID))) != 0)) {
      setState(217);
      expression(0);
      setState(222);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(223);
    ret();
    setState(224);
    match(dzParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentContext ------------------------------------------------------------------

dzParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t dzParser::ArgumentContext::getRuleIndex() const {
  return dzParser::RuleArgument;
}

void dzParser::ArgumentContext::copyFrom(ArgumentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StandardArgumentContext ------------------------------------------------------------------

dzParser::TypeNameContext* dzParser::StandardArgumentContext::typeName() {
  return getRuleContext<dzParser::TypeNameContext>(0);
}

tree::TerminalNode* dzParser::StandardArgumentContext::ID() {
  return getToken(dzParser::ID, 0);
}

dzParser::StandardArgumentContext::StandardArgumentContext(ArgumentContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::StandardArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitStandardArgument(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TupleArgumentContext ------------------------------------------------------------------

std::vector<dzParser::ArgumentContext *> dzParser::TupleArgumentContext::argument() {
  return getRuleContexts<dzParser::ArgumentContext>();
}

dzParser::ArgumentContext* dzParser::TupleArgumentContext::argument(size_t i) {
  return getRuleContext<dzParser::ArgumentContext>(i);
}

dzParser::TupleArgumentContext::TupleArgumentContext(ArgumentContext *ctx) { copyFrom(ctx); }


antlrcpp::Any dzParser::TupleArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitTupleArgument(this);
  else
    return visitor->visitChildren(this);
}
dzParser::ArgumentContext* dzParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 24, dzParser::RuleArgument);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(240);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case dzParser::T__16:
      case dzParser::ID: {
        _localctx = dynamic_cast<ArgumentContext *>(_tracker.createInstance<dzParser::StandardArgumentContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(226);
        typeName();
        setState(227);
        match(dzParser::ID);
        break;
      }

      case dzParser::T__6: {
        _localctx = dynamic_cast<ArgumentContext *>(_tracker.createInstance<dzParser::TupleArgumentContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(229);
        match(dzParser::T__6);
        setState(230);
        argument();
        setState(235);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == dzParser::T__2) {
          setState(231);
          match(dzParser::T__2);
          setState(232);
          argument();
          setState(237);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(238);
        match(dzParser::T__7);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

dzParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* dzParser::TypeNameContext::ID() {
  return getToken(dzParser::ID, 0);
}


size_t dzParser::TypeNameContext::getRuleIndex() const {
  return dzParser::RuleTypeName;
}


antlrcpp::Any dzParser::TypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<dzVisitor*>(visitor))
    return parserVisitor->visitTypeName(this);
  else
    return visitor->visitChildren(this);
}

dzParser::TypeNameContext* dzParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 26, dzParser::RuleTypeName);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
    _la = _input->LA(1);
    if (!(_la == dzParser::T__16

    || _la == dzParser::ID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool dzParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 8: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool dzParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> dzParser::_decisionToDFA;
atn::PredictionContextCache dzParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN dzParser::_atn;
std::vector<uint16_t> dzParser::_serializedATN;

std::vector<std::string> dzParser::_ruleNames = {
  "program", "structure", "global", "assignment", "field", "function", "literal", 
  "with", "expression", "continuation", "ret", "block", "argument", "typeName"
};

std::vector<std::string> dzParser::_literalNames = {
  "", "'struct'", "':'", "','", "'{'", "'}'", "'global'", "'('", "')'", 
  "'L'", "'u'", "'nothing'", "'with'", "'.'", "'if'", "'['", "']'", "'...'", 
  "'return'", "'->'"
};

std::vector<std::string> dzParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "INT", "BOOL", "OP", "COMMENT", "STRING", "CHARACTER", "WS", "ID"
};

dfa::Vocabulary dzParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> dzParser::_tokenNames;

dzParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x1d, 0xf7, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
       0x3, 0x2, 0x7, 0x2, 0x23, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x26, 0xb, 
       0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x7, 0x3, 0x2e, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x31, 0xb, 0x3, 0x5, 
       0x3, 0x33, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 
       0x3, 0x39, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x3c, 0xb, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x5, 0x6, 0x4a, 0xa, 
       0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x4f, 0xa, 0x6, 0x3, 
       0x7, 0x5, 0x7, 0x52, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x5a, 0xa, 0x7, 0xc, 0x7, 0xe, 
       0x7, 0x5d, 0xb, 0x7, 0x5, 0x7, 0x5f, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 
       0x5, 0x7, 0x63, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x6e, 
       0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 
       0x9, 0x75, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x78, 0xb, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
       0xa, 0x7, 0xa, 0x82, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x85, 0xb, 0xa, 
       0x5, 0xa, 0x87, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
       0x3, 0xa, 0x7, 0xa, 0x8e, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x91, 0xb, 
       0xa, 0x3, 0xa, 0x5, 0xa, 0x94, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
       0xa, 0x5, 0xa, 0x99, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x9d, 
       0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xa0, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 
       0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
       0xa, 0x3, 0xa, 0x5, 0xa, 0xac, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 
       0xa, 0xb0, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xb3, 0xb, 0xa, 0x3, 0xa, 
       0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 
       0xa, 0xbc, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xc1, 
       0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xc4, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xca, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 
       0xcd, 0xb, 0xb, 0x5, 0xb, 0xcf, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
       0xc, 0x3, 0xc, 0x5, 0xc, 0xd5, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 
       0xc, 0xd9, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xdd, 0xa, 0xd, 
       0xc, 0xd, 0xe, 0xd, 0xe0, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
       0xe, 0x7, 0xe, 0xec, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xef, 0xb, 0xe, 
       0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xf3, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 
       0x3, 0xf, 0x2, 0x3, 0x12, 0x10, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
       0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x2, 0x3, 0x4, 0x2, 0x13, 
       0x13, 0x1d, 0x1d, 0x2, 0x113, 0x2, 0x24, 0x3, 0x2, 0x2, 0x2, 0x4, 
       0x27, 0x3, 0x2, 0x2, 0x2, 0x6, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x8, 0x44, 
       0x3, 0x2, 0x2, 0x2, 0xa, 0x49, 0x3, 0x2, 0x2, 0x2, 0xc, 0x51, 0x3, 
       0x2, 0x2, 0x2, 0xe, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x10, 0x6f, 0x3, 0x2, 
       0x2, 0x2, 0x12, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x14, 0xc5, 0x3, 0x2, 0x2, 
       0x2, 0x16, 0xd2, 0x3, 0x2, 0x2, 0x2, 0x18, 0xda, 0x3, 0x2, 0x2, 0x2, 
       0x1a, 0xf2, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xf4, 0x3, 0x2, 0x2, 0x2, 0x1e, 
       0x23, 0x7, 0x19, 0x2, 0x2, 0x1f, 0x23, 0x5, 0xc, 0x7, 0x2, 0x20, 
       0x23, 0x5, 0x4, 0x3, 0x2, 0x21, 0x23, 0x5, 0x6, 0x4, 0x2, 0x22, 0x1e, 
       0x3, 0x2, 0x2, 0x2, 0x22, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x22, 0x20, 0x3, 
       0x2, 0x2, 0x2, 0x22, 0x21, 0x3, 0x2, 0x2, 0x2, 0x23, 0x26, 0x3, 0x2, 
       0x2, 0x2, 0x24, 0x22, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x3, 0x2, 0x2, 
       0x2, 0x25, 0x3, 0x3, 0x2, 0x2, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 
       0x27, 0x28, 0x7, 0x3, 0x2, 0x2, 0x28, 0x32, 0x7, 0x1d, 0x2, 0x2, 
       0x29, 0x2a, 0x7, 0x4, 0x2, 0x2, 0x2a, 0x2f, 0x5, 0x1c, 0xf, 0x2, 
       0x2b, 0x2c, 0x7, 0x5, 0x2, 0x2, 0x2c, 0x2e, 0x5, 0x1c, 0xf, 0x2, 
       0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x31, 0x3, 0x2, 0x2, 0x2, 0x2f, 
       0x2d, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x2, 0x2, 0x30, 0x33, 
       0x3, 0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x32, 0x29, 0x3, 
       0x2, 0x2, 0x2, 0x32, 0x33, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 
       0x2, 0x2, 0x34, 0x35, 0x7, 0x6, 0x2, 0x2, 0x35, 0x3a, 0x5, 0xa, 0x6, 
       0x2, 0x36, 0x37, 0x7, 0x5, 0x2, 0x2, 0x37, 0x39, 0x5, 0xa, 0x6, 0x2, 
       0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3a, 
       0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3d, 
       0x3, 0x2, 0x2, 0x2, 0x3c, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x7, 
       0x7, 0x2, 0x2, 0x3e, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x8, 
       0x2, 0x2, 0x40, 0x41, 0x7, 0x1d, 0x2, 0x2, 0x41, 0x42, 0x7, 0x4, 
       0x2, 0x2, 0x42, 0x43, 0x5, 0xe, 0x8, 0x2, 0x43, 0x7, 0x3, 0x2, 0x2, 
       0x2, 0x44, 0x45, 0x5, 0xa, 0x6, 0x2, 0x45, 0x46, 0x7, 0x4, 0x2, 0x2, 
       0x46, 0x47, 0x5, 0x12, 0xa, 0x2, 0x47, 0x9, 0x3, 0x2, 0x2, 0x2, 0x48, 
       0x4a, 0x5, 0x1c, 0xf, 0x2, 0x49, 0x48, 0x3, 0x2, 0x2, 0x2, 0x49, 
       0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4e, 
       0x7, 0x1d, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0x4, 0x2, 0x2, 0x4d, 0x4f, 
       0x5, 0x12, 0xa, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 
       0x3, 0x2, 0x2, 0x2, 0x4f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x50, 0x52, 0x7, 
       0x1d, 0x2, 0x2, 0x51, 0x50, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 
       0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x5, 0x1c, 
       0xf, 0x2, 0x54, 0x55, 0x7, 0x1d, 0x2, 0x2, 0x55, 0x5e, 0x7, 0x9, 
       0x2, 0x2, 0x56, 0x5b, 0x5, 0x1a, 0xe, 0x2, 0x57, 0x58, 0x7, 0x5, 
       0x2, 0x2, 0x58, 0x5a, 0x5, 0x1a, 0xe, 0x2, 0x59, 0x57, 0x3, 0x2, 
       0x2, 0x2, 0x5a, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 
       0x2, 0x5b, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5f, 0x3, 0x2, 0x2, 0x2, 
       0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x56, 0x3, 0x2, 0x2, 0x2, 0x5e, 
       0x5f, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0x62, 
       0x7, 0xa, 0x2, 0x2, 0x61, 0x63, 0x5, 0x18, 0xd, 0x2, 0x62, 0x61, 
       0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 0x2, 0x63, 0xd, 0x3, 
       0x2, 0x2, 0x2, 0x64, 0x6e, 0x7, 0x16, 0x2, 0x2, 0x65, 0x66, 0x7, 
       0x16, 0x2, 0x2, 0x66, 0x6e, 0x7, 0xb, 0x2, 0x2, 0x67, 0x6e, 0x7, 
       0x17, 0x2, 0x2, 0x68, 0x6e, 0x7, 0x1a, 0x2, 0x2, 0x69, 0x6a, 0x7, 
       0x16, 0x2, 0x2, 0x6a, 0x6e, 0x7, 0xc, 0x2, 0x2, 0x6b, 0x6e, 0x7, 
       0x1b, 0x2, 0x2, 0x6c, 0x6e, 0x7, 0xd, 0x2, 0x2, 0x6d, 0x64, 0x3, 
       0x2, 0x2, 0x2, 0x6d, 0x65, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x67, 0x3, 0x2, 
       0x2, 0x2, 0x6d, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x69, 0x3, 0x2, 0x2, 
       0x2, 0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6c, 0x3, 0x2, 0x2, 0x2, 
       0x6e, 0xf, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x7, 0xe, 0x2, 0x2, 0x70, 
       0x71, 0x7, 0x6, 0x2, 0x2, 0x71, 0x76, 0x5, 0x8, 0x5, 0x2, 0x72, 0x73, 
       0x7, 0x5, 0x2, 0x2, 0x73, 0x75, 0x5, 0x8, 0x5, 0x2, 0x74, 0x72, 0x3, 
       0x2, 0x2, 0x2, 0x75, 0x78, 0x3, 0x2, 0x2, 0x2, 0x76, 0x74, 0x3, 0x2, 
       0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x79, 0x3, 0x2, 0x2, 
       0x2, 0x78, 0x76, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x7, 0x2, 0x2, 
       0x7a, 0x11, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x8, 0xa, 0x1, 0x2, 0x7c, 
       0x7d, 0x7, 0x1d, 0x2, 0x2, 0x7d, 0x86, 0x7, 0x9, 0x2, 0x2, 0x7e, 
       0x83, 0x5, 0x12, 0xa, 0x2, 0x7f, 0x80, 0x7, 0x5, 0x2, 0x2, 0x80, 
       0x82, 0x5, 0x12, 0xa, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x82, 
       0x85, 0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 
       0x3, 0x2, 0x2, 0x2, 0x84, 0x87, 0x3, 0x2, 0x2, 0x2, 0x85, 0x83, 0x3, 
       0x2, 0x2, 0x2, 0x86, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x3, 0x2, 
       0x2, 0x2, 0x87, 0x88, 0x3, 0x2, 0x2, 0x2, 0x88, 0xbc, 0x7, 0xa, 0x2, 
       0x2, 0x89, 0xbc, 0x5, 0xe, 0x8, 0x2, 0x8a, 0x8f, 0x7, 0x1d, 0x2, 
       0x2, 0x8b, 0x8c, 0x7, 0xf, 0x2, 0x2, 0x8c, 0x8e, 0x7, 0x1d, 0x2, 
       0x2, 0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x91, 0x3, 0x2, 0x2, 0x2, 
       0x8f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 0x2, 0x2, 0x2, 0x90, 
       0x93, 0x3, 0x2, 0x2, 0x2, 0x91, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x92, 0x94, 
       0x5, 0x10, 0x9, 0x2, 0x93, 0x92, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 
       0x3, 0x2, 0x2, 0x2, 0x94, 0xbc, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x5, 
       0x1c, 0xf, 0x2, 0x96, 0x98, 0x7, 0x6, 0x2, 0x2, 0x97, 0x99, 0x5, 
       0x8, 0x5, 0x2, 0x98, 0x97, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x3, 0x2, 
       0x2, 0x2, 0x99, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x5, 0x2, 
       0x2, 0x9b, 0x9d, 0x5, 0x8, 0x5, 0x2, 0x9c, 0x9a, 0x3, 0x2, 0x2, 0x2, 
       0x9d, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 
       0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9e, 
       0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x7, 0x2, 0x2, 0xa2, 0xbc, 0x3, 
       0x2, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x10, 0x2, 0x2, 0xa4, 0xa5, 0x7, 
       0x9, 0x2, 0x2, 0xa5, 0xa6, 0x5, 0x12, 0xa, 0x2, 0xa6, 0xa7, 0x7, 
       0xa, 0x2, 0x2, 0xa7, 0xa8, 0x5, 0x18, 0xd, 0x2, 0xa8, 0xbc, 0x3, 
       0x2, 0x2, 0x2, 0xa9, 0xab, 0x7, 0x11, 0x2, 0x2, 0xaa, 0xac, 0x5, 
       0x12, 0xa, 0x2, 0xab, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x3, 
       0x2, 0x2, 0x2, 0xac, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x7, 0x5, 
       0x2, 0x2, 0xae, 0xb0, 0x5, 0x12, 0xa, 0x2, 0xaf, 0xad, 0x3, 0x2, 
       0x2, 0x2, 0xb0, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xaf, 0x3, 0x2, 0x2, 
       0x2, 0xb1, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb4, 0x3, 0x2, 0x2, 0x2, 
       0xb3, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xbc, 0x7, 0x12, 0x2, 0x2, 
       0xb5, 0xb6, 0x7, 0x9, 0x2, 0x2, 0xb6, 0xb7, 0x5, 0x12, 0xa, 0x2, 
       0xb7, 0xb8, 0x7, 0xa, 0x2, 0x2, 0xb8, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xb9, 
       0xba, 0x7, 0x13, 0x2, 0x2, 0xba, 0xbc, 0x5, 0x12, 0xa, 0x3, 0xbb, 
       0x7b, 0x3, 0x2, 0x2, 0x2, 0xbb, 0x89, 0x3, 0x2, 0x2, 0x2, 0xbb, 0x8a, 
       0x3, 0x2, 0x2, 0x2, 0xbb, 0x95, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xa3, 0x3, 
       0x2, 0x2, 0x2, 0xbb, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xb5, 0x3, 0x2, 
       0x2, 0x2, 0xbb, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xc2, 0x3, 0x2, 0x2, 
       0x2, 0xbd, 0xbe, 0xc, 0x9, 0x2, 0x2, 0xbe, 0xbf, 0x7, 0x18, 0x2, 
       0x2, 0xbf, 0xc1, 0x5, 0x12, 0xa, 0xa, 0xc0, 0xbd, 0x3, 0x2, 0x2, 
       0x2, 0xc1, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 
       0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0x13, 0x3, 0x2, 0x2, 0x2, 0xc4, 
       0xc2, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xce, 0x7, 0x9, 0x2, 0x2, 0xc6, 0xcb, 
       0x5, 0x12, 0xa, 0x2, 0xc7, 0xc8, 0x7, 0x5, 0x2, 0x2, 0xc8, 0xca, 
       0x5, 0x12, 0xa, 0x2, 0xc9, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcd, 
       0x3, 0x2, 0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x3, 
       0x2, 0x2, 0x2, 0xcc, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcb, 0x3, 0x2, 
       0x2, 0x2, 0xce, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x3, 0x2, 0x2, 
       0x2, 0xcf, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0xa, 0x2, 0x2, 
       0xd1, 0x15, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd4, 0x7, 0x14, 0x2, 0x2, 
       0xd3, 0xd5, 0x5, 0x12, 0xa, 0x2, 0xd4, 0xd3, 0x3, 0x2, 0x2, 0x2, 
       0xd4, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd6, 
       0xd7, 0x7, 0x15, 0x2, 0x2, 0xd7, 0xd9, 0x5, 0x14, 0xb, 0x2, 0xd8, 
       0xd6, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd9, 0x17, 
       0x3, 0x2, 0x2, 0x2, 0xda, 0xde, 0x7, 0x6, 0x2, 0x2, 0xdb, 0xdd, 0x5, 
       0x12, 0xa, 0x2, 0xdc, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xe0, 0x3, 
       0x2, 0x2, 0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 
       0x2, 0x2, 0xdf, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 
       0x2, 0xe1, 0xe2, 0x5, 0x16, 0xc, 0x2, 0xe2, 0xe3, 0x7, 0x7, 0x2, 
       0x2, 0xe3, 0x19, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x5, 0x1c, 0xf, 
       0x2, 0xe5, 0xe6, 0x7, 0x1d, 0x2, 0x2, 0xe6, 0xf3, 0x3, 0x2, 0x2, 
       0x2, 0xe7, 0xe8, 0x7, 0x9, 0x2, 0x2, 0xe8, 0xed, 0x5, 0x1a, 0xe, 
       0x2, 0xe9, 0xea, 0x7, 0x5, 0x2, 0x2, 0xea, 0xec, 0x5, 0x1a, 0xe, 
       0x2, 0xeb, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xec, 0xef, 0x3, 0x2, 0x2, 0x2, 
       0xed, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x3, 0x2, 0x2, 0x2, 0xee, 
       0xf0, 0x3, 0x2, 0x2, 0x2, 0xef, 0xed, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 
       0x7, 0xa, 0x2, 0x2, 0xf1, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xe4, 0x3, 
       0x2, 0x2, 0x2, 0xf2, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xf3, 0x1b, 0x3, 0x2, 
       0x2, 0x2, 0xf4, 0xf5, 0x9, 0x2, 0x2, 0x2, 0xf5, 0x1d, 0x3, 0x2, 0x2, 
       0x2, 0x20, 0x22, 0x24, 0x2f, 0x32, 0x3a, 0x49, 0x4e, 0x51, 0x5b, 
       0x5e, 0x62, 0x6d, 0x76, 0x83, 0x86, 0x8f, 0x93, 0x98, 0x9e, 0xab, 
       0xb1, 0xbb, 0xc2, 0xcb, 0xce, 0xd4, 0xd8, 0xde, 0xed, 0xf2, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

dzParser::Initializer dzParser::_init;
