
// Generated from ifcc.g4 by ANTLR 4.13.2


#include "ifccVisitor.h"

#include "ifccParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct IfccParserStaticData final {
  IfccParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  IfccParserStaticData(const IfccParserStaticData&) = delete;
  IfccParserStaticData(IfccParserStaticData&&) = delete;
  IfccParserStaticData& operator=(const IfccParserStaticData&) = delete;
  IfccParserStaticData& operator=(IfccParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag ifccParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<IfccParserStaticData> ifccParserStaticData = nullptr;

void ifccParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (ifccParserStaticData != nullptr) {
    return;
  }
#else
  assert(ifccParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<IfccParserStaticData>(
    std::vector<std::string>{
      "axiom", "prog", "stmt", "decl_stmt", "assign_stmt", "return_stmt", 
      "expr"
    },
    std::vector<std::string>{
      "", "'int'", "'main'", "'('", "')'", "'{'", "'}'", "'='", "';'", "'&'", 
      "'|'", "'^'", "'return'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "RETURN", "ID", "CONST", 
      "COMMENT", "DIRECTIVE", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,17,76,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,1,0,
  	1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,5,1,24,8,1,10,1,12,1,27,9,1,1,1,1,1,1,
  	2,1,2,1,2,3,2,34,8,2,1,3,1,3,1,3,1,3,3,3,40,8,3,1,3,1,3,1,4,1,4,1,4,1,
  	4,1,4,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,60,8,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,5,6,71,8,6,10,6,12,6,74,9,6,1,6,0,1,12,7,
  	0,2,4,6,8,10,12,0,0,77,0,14,1,0,0,0,2,17,1,0,0,0,4,33,1,0,0,0,6,35,1,
  	0,0,0,8,43,1,0,0,0,10,48,1,0,0,0,12,59,1,0,0,0,14,15,3,2,1,0,15,16,5,
  	0,0,1,16,1,1,0,0,0,17,18,5,1,0,0,18,19,5,2,0,0,19,20,5,3,0,0,20,21,5,
  	4,0,0,21,25,5,5,0,0,22,24,3,4,2,0,23,22,1,0,0,0,24,27,1,0,0,0,25,23,1,
  	0,0,0,25,26,1,0,0,0,26,28,1,0,0,0,27,25,1,0,0,0,28,29,5,6,0,0,29,3,1,
  	0,0,0,30,34,3,6,3,0,31,34,3,8,4,0,32,34,3,10,5,0,33,30,1,0,0,0,33,31,
  	1,0,0,0,33,32,1,0,0,0,34,5,1,0,0,0,35,36,5,1,0,0,36,39,5,13,0,0,37,38,
  	5,7,0,0,38,40,3,12,6,0,39,37,1,0,0,0,39,40,1,0,0,0,40,41,1,0,0,0,41,42,
  	5,8,0,0,42,7,1,0,0,0,43,44,5,13,0,0,44,45,5,7,0,0,45,46,3,12,6,0,46,47,
  	5,8,0,0,47,9,1,0,0,0,48,49,5,12,0,0,49,50,3,12,6,0,50,51,5,8,0,0,51,11,
  	1,0,0,0,52,53,6,6,-1,0,53,54,5,3,0,0,54,55,3,12,6,0,55,56,5,4,0,0,56,
  	60,1,0,0,0,57,60,5,13,0,0,58,60,5,14,0,0,59,52,1,0,0,0,59,57,1,0,0,0,
  	59,58,1,0,0,0,60,72,1,0,0,0,61,62,10,6,0,0,62,63,5,9,0,0,63,71,3,12,6,
  	7,64,65,10,5,0,0,65,66,5,10,0,0,66,71,3,12,6,6,67,68,10,4,0,0,68,69,5,
  	11,0,0,69,71,3,12,6,5,70,61,1,0,0,0,70,64,1,0,0,0,70,67,1,0,0,0,71,74,
  	1,0,0,0,72,70,1,0,0,0,72,73,1,0,0,0,73,13,1,0,0,0,74,72,1,0,0,0,6,25,
  	33,39,59,70,72
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ifccParserStaticData = std::move(staticData);
}

}

ifccParser::ifccParser(TokenStream *input) : ifccParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ifccParser::ifccParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ifccParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *ifccParserStaticData->atn, ifccParserStaticData->decisionToDFA, ifccParserStaticData->sharedContextCache, options);
}

ifccParser::~ifccParser() {
  delete _interpreter;
}

const atn::ATN& ifccParser::getATN() const {
  return *ifccParserStaticData->atn;
}

std::string ifccParser::getGrammarFileName() const {
  return "ifcc.g4";
}

const std::vector<std::string>& ifccParser::getRuleNames() const {
  return ifccParserStaticData->ruleNames;
}

const dfa::Vocabulary& ifccParser::getVocabulary() const {
  return ifccParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ifccParser::getSerializedATN() const {
  return ifccParserStaticData->serializedATN;
}


//----------------- AxiomContext ------------------------------------------------------------------

ifccParser::AxiomContext::AxiomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::ProgContext* ifccParser::AxiomContext::prog() {
  return getRuleContext<ifccParser::ProgContext>(0);
}

tree::TerminalNode* ifccParser::AxiomContext::EOF() {
  return getToken(ifccParser::EOF, 0);
}


size_t ifccParser::AxiomContext::getRuleIndex() const {
  return ifccParser::RuleAxiom;
}


std::any ifccParser::AxiomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAxiom(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::AxiomContext* ifccParser::axiom() {
  AxiomContext *_localctx = _tracker.createInstance<AxiomContext>(_ctx, getState());
  enterRule(_localctx, 0, ifccParser::RuleAxiom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(14);
    prog();
    setState(15);
    match(ifccParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgContext ------------------------------------------------------------------

ifccParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ifccParser::StmtContext *> ifccParser::ProgContext::stmt() {
  return getRuleContexts<ifccParser::StmtContext>();
}

ifccParser::StmtContext* ifccParser::ProgContext::stmt(size_t i) {
  return getRuleContext<ifccParser::StmtContext>(i);
}


size_t ifccParser::ProgContext::getRuleIndex() const {
  return ifccParser::RuleProg;
}


std::any ifccParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ProgContext* ifccParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 2, ifccParser::RuleProg);
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
    setState(17);
    match(ifccParser::T__0);
    setState(18);
    match(ifccParser::T__1);
    setState(19);
    match(ifccParser::T__2);
    setState(20);
    match(ifccParser::T__3);
    setState(21);
    match(ifccParser::T__4);
    setState(25);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 12290) != 0)) {
      setState(22);
      stmt();
      setState(27);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(28);
    match(ifccParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

ifccParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::Decl_stmtContext* ifccParser::StmtContext::decl_stmt() {
  return getRuleContext<ifccParser::Decl_stmtContext>(0);
}

ifccParser::Assign_stmtContext* ifccParser::StmtContext::assign_stmt() {
  return getRuleContext<ifccParser::Assign_stmtContext>(0);
}

ifccParser::Return_stmtContext* ifccParser::StmtContext::return_stmt() {
  return getRuleContext<ifccParser::Return_stmtContext>(0);
}


size_t ifccParser::StmtContext::getRuleIndex() const {
  return ifccParser::RuleStmt;
}


std::any ifccParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::StmtContext* ifccParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 4, ifccParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(33);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(30);
        decl_stmt();
        break;
      }

      case ifccParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(31);
        assign_stmt();
        break;
      }

      case ifccParser::RETURN: {
        enterOuterAlt(_localctx, 3);
        setState(32);
        return_stmt();
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

//----------------- Decl_stmtContext ------------------------------------------------------------------

ifccParser::Decl_stmtContext::Decl_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::Decl_stmtContext::ID() {
  return getToken(ifccParser::ID, 0);
}

ifccParser::ExprContext* ifccParser::Decl_stmtContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}


size_t ifccParser::Decl_stmtContext::getRuleIndex() const {
  return ifccParser::RuleDecl_stmt;
}


std::any ifccParser::Decl_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitDecl_stmt(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::Decl_stmtContext* ifccParser::decl_stmt() {
  Decl_stmtContext *_localctx = _tracker.createInstance<Decl_stmtContext>(_ctx, getState());
  enterRule(_localctx, 6, ifccParser::RuleDecl_stmt);
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
    setState(35);
    match(ifccParser::T__0);
    setState(36);
    match(ifccParser::ID);
    setState(39);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ifccParser::T__6) {
      setState(37);
      match(ifccParser::T__6);
      setState(38);
      expr(0);
    }
    setState(41);
    match(ifccParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assign_stmtContext ------------------------------------------------------------------

ifccParser::Assign_stmtContext::Assign_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::Assign_stmtContext::ID() {
  return getToken(ifccParser::ID, 0);
}

ifccParser::ExprContext* ifccParser::Assign_stmtContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}


size_t ifccParser::Assign_stmtContext::getRuleIndex() const {
  return ifccParser::RuleAssign_stmt;
}


std::any ifccParser::Assign_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAssign_stmt(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::Assign_stmtContext* ifccParser::assign_stmt() {
  Assign_stmtContext *_localctx = _tracker.createInstance<Assign_stmtContext>(_ctx, getState());
  enterRule(_localctx, 8, ifccParser::RuleAssign_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    match(ifccParser::ID);
    setState(44);
    match(ifccParser::T__6);
    setState(45);
    expr(0);
    setState(46);
    match(ifccParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_stmtContext ------------------------------------------------------------------

ifccParser::Return_stmtContext::Return_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::Return_stmtContext::RETURN() {
  return getToken(ifccParser::RETURN, 0);
}

ifccParser::ExprContext* ifccParser::Return_stmtContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}


size_t ifccParser::Return_stmtContext::getRuleIndex() const {
  return ifccParser::RuleReturn_stmt;
}


std::any ifccParser::Return_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitReturn_stmt(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::Return_stmtContext* ifccParser::return_stmt() {
  Return_stmtContext *_localctx = _tracker.createInstance<Return_stmtContext>(_ctx, getState());
  enterRule(_localctx, 10, ifccParser::RuleReturn_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    match(ifccParser::RETURN);
    setState(49);
    expr(0);
    setState(50);
    match(ifccParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ifccParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::ExprContext::getRuleIndex() const {
  return ifccParser::RuleExpr;
}

void ifccParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BitwiseAndExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::BitwiseAndExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::BitwiseAndExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::BitwiseAndExprContext::BitwiseAndExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::BitwiseAndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitBitwiseAndExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseOrExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::BitwiseOrExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::BitwiseOrExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::BitwiseOrExprContext::BitwiseOrExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::BitwiseOrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitBitwiseOrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierExprContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::IdentifierExprContext::ID() {
  return getToken(ifccParser::ID, 0);
}

ifccParser::IdentifierExprContext::IdentifierExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::IdentifierExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitIdentifierExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstantExprContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::ConstantExprContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::ConstantExprContext::ConstantExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::ConstantExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitConstantExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedExprContext ------------------------------------------------------------------

ifccParser::ExprContext* ifccParser::ParenthesizedExprContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

ifccParser::ParenthesizedExprContext::ParenthesizedExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::ParenthesizedExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitParenthesizedExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseXorExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::BitwiseXorExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::BitwiseXorExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::BitwiseXorExprContext::BitwiseXorExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any ifccParser::BitwiseXorExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitBitwiseXorExpr(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ExprContext* ifccParser::expr() {
   return expr(0);
}

ifccParser::ExprContext* ifccParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ifccParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ifccParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, ifccParser::RuleExpr, precedence);

    

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
    setState(59);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__2: {
        _localctx = _tracker.createInstance<ParenthesizedExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(53);
        match(ifccParser::T__2);
        setState(54);
        expr(0);
        setState(55);
        match(ifccParser::T__3);
        break;
      }

      case ifccParser::ID: {
        _localctx = _tracker.createInstance<IdentifierExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(57);
        match(ifccParser::ID);
        break;
      }

      case ifccParser::CONST: {
        _localctx = _tracker.createInstance<ConstantExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(58);
        match(ifccParser::CONST);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(72);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(70);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BitwiseAndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(61);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(62);
          match(ifccParser::T__8);
          setState(63);
          expr(7);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BitwiseOrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(64);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(65);
          match(ifccParser::T__9);
          setState(66);
          expr(6);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BitwiseXorExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(67);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(68);
          match(ifccParser::T__10);
          setState(69);
          expr(5);
          break;
        }

        default:
          break;
        } 
      }
      setState(74);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool ifccParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ifccParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

void ifccParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  ifccParserInitialize();
#else
  ::antlr4::internal::call_once(ifccParserOnceFlag, ifccParserInitialize);
#endif
}
