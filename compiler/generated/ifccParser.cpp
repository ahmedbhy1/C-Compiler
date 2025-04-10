
// Generated from ifcc.g4 by ANTLR 4.7.2


#include "ifccVisitor.h"

#include "ifccParser.h"


using namespace antlrcpp;
using namespace antlr4;

ifccParser::ifccParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ifccParser::~ifccParser() {
  delete _interpreter;
}

std::string ifccParser::getGrammarFileName() const {
  return "ifcc.g4";
}

const std::vector<std::string>& ifccParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ifccParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- AxiomContext ------------------------------------------------------------------

ifccParser::AxiomContext::AxiomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::ProgsContext* ifccParser::AxiomContext::progs() {
  return getRuleContext<ifccParser::ProgsContext>(0);
}

tree::TerminalNode* ifccParser::AxiomContext::EOF() {
  return getToken(ifccParser::EOF, 0);
}


size_t ifccParser::AxiomContext::getRuleIndex() const {
  return ifccParser::RuleAxiom;
}

antlrcpp::Any ifccParser::AxiomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAxiom(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::AxiomContext* ifccParser::axiom() {
  AxiomContext *_localctx = _tracker.createInstance<AxiomContext>(_ctx, getState());
  enterRule(_localctx, 0, ifccParser::RuleAxiom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(18);
    progs();
    setState(19);
    match(ifccParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgsContext ------------------------------------------------------------------

ifccParser::ProgsContext::ProgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ifccParser::ProgContext *> ifccParser::ProgsContext::prog() {
  return getRuleContexts<ifccParser::ProgContext>();
}

ifccParser::ProgContext* ifccParser::ProgsContext::prog(size_t i) {
  return getRuleContext<ifccParser::ProgContext>(i);
}


size_t ifccParser::ProgsContext::getRuleIndex() const {
  return ifccParser::RuleProgs;
}

antlrcpp::Any ifccParser::ProgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitProgs(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ProgsContext* ifccParser::progs() {
  ProgsContext *_localctx = _tracker.createInstance<ProgsContext>(_ctx, getState());
  enterRule(_localctx, 2, ifccParser::RuleProgs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(24);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ifccParser::T__0

    || _la == ifccParser::T__3) {
      setState(21);
      prog();
      setState(26);
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

//----------------- ProgContext ------------------------------------------------------------------

ifccParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::ProgContext::ID() {
  return getToken(ifccParser::ID, 0);
}

tree::TerminalNode* ifccParser::ProgContext::OPENPARENT() {
  return getToken(ifccParser::OPENPARENT, 0);
}

tree::TerminalNode* ifccParser::ProgContext::CLOSEPARENT() {
  return getToken(ifccParser::CLOSEPARENT, 0);
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

antlrcpp::Any ifccParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ProgContext* ifccParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 4, ifccParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(51);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(27);
        match(ifccParser::T__0);
        setState(28);
        match(ifccParser::ID);
        setState(29);
        match(ifccParser::OPENPARENT);
        setState(30);
        match(ifccParser::CLOSEPARENT);
        setState(31);
        match(ifccParser::T__1);
        setState(35);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << ifccParser::T__0)
          | (1ULL << ifccParser::T__1)
          | (1ULL << ifccParser::T__6)
          | (1ULL << ifccParser::RETURN)
          | (1ULL << ifccParser::ID))) != 0)) {
          setState(32);
          stmt();
          setState(37);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(38);
        match(ifccParser::T__2);
        break;
      }

      case ifccParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(39);
        match(ifccParser::T__3);
        setState(40);
        match(ifccParser::ID);
        setState(41);
        match(ifccParser::OPENPARENT);
        setState(42);
        match(ifccParser::CLOSEPARENT);
        setState(43);
        match(ifccParser::T__1);
        setState(47);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << ifccParser::T__0)
          | (1ULL << ifccParser::T__1)
          | (1ULL << ifccParser::T__6)
          | (1ULL << ifccParser::RETURN)
          | (1ULL << ifccParser::ID))) != 0)) {
          setState(44);
          stmt();
          setState(49);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(50);
        match(ifccParser::T__2);
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

//----------------- StmtContext ------------------------------------------------------------------

ifccParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::StmtContext::getRuleIndex() const {
  return ifccParser::RuleStmt;
}

void ifccParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RetContext ------------------------------------------------------------------

ifccParser::Return_stmtContext* ifccParser::RetContext::return_stmt() {
  return getRuleContext<ifccParser::Return_stmtContext>(0);
}

ifccParser::RetContext::RetContext(StmtContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::RetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitRet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclContext ------------------------------------------------------------------

ifccParser::Decl_stmtContext* ifccParser::DeclContext::decl_stmt() {
  return getRuleContext<ifccParser::Decl_stmtContext>(0);
}

ifccParser::DeclContext::DeclContext(StmtContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BlockContext ------------------------------------------------------------------

std::vector<ifccParser::StmtContext *> ifccParser::BlockContext::stmt() {
  return getRuleContexts<ifccParser::StmtContext>();
}

ifccParser::StmtContext* ifccParser::BlockContext::stmt(size_t i) {
  return getRuleContext<ifccParser::StmtContext>(i);
}

ifccParser::BlockContext::BlockContext(StmtContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignContext ------------------------------------------------------------------

ifccParser::Assign_stmtContext* ifccParser::AssignContext::assign_stmt() {
  return getRuleContext<ifccParser::Assign_stmtContext>(0);
}

ifccParser::AssignContext::AssignContext(StmtContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}
ifccParser::StmtContext* ifccParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 6, ifccParser::RuleStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(64);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__0:
      case ifccParser::T__6: {
        _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<ifccParser::DeclContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(53);
        decl_stmt();
        break;
      }

      case ifccParser::ID: {
        _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<ifccParser::AssignContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(54);
        assign_stmt();
        break;
      }

      case ifccParser::RETURN: {
        _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<ifccParser::RetContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(55);
        return_stmt();
        break;
      }

      case ifccParser::T__1: {
        _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<ifccParser::BlockContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(56);
        match(ifccParser::T__1);
        setState(60);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << ifccParser::T__0)
          | (1ULL << ifccParser::T__1)
          | (1ULL << ifccParser::T__6)
          | (1ULL << ifccParser::RETURN)
          | (1ULL << ifccParser::ID))) != 0)) {
          setState(57);
          stmt();
          setState(62);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(63);
        match(ifccParser::T__2);
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

std::vector<ifccParser::Equalexpr_stmtContext *> ifccParser::Decl_stmtContext::equalexpr_stmt() {
  return getRuleContexts<ifccParser::Equalexpr_stmtContext>();
}

ifccParser::Equalexpr_stmtContext* ifccParser::Decl_stmtContext::equalexpr_stmt(size_t i) {
  return getRuleContext<ifccParser::Equalexpr_stmtContext>(i);
}


size_t ifccParser::Decl_stmtContext::getRuleIndex() const {
  return ifccParser::RuleDecl_stmt;
}

antlrcpp::Any ifccParser::Decl_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitDecl_stmt(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::Decl_stmtContext* ifccParser::decl_stmt() {
  Decl_stmtContext *_localctx = _tracker.createInstance<Decl_stmtContext>(_ctx, getState());
  enterRule(_localctx, 8, ifccParser::RuleDecl_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(88);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(66);
        match(ifccParser::T__0);
        setState(67);
        equalexpr_stmt();
        setState(72);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == ifccParser::T__4) {
          setState(68);
          match(ifccParser::T__4);
          setState(69);
          equalexpr_stmt();
          setState(74);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(75);
        match(ifccParser::T__5);
        break;
      }

      case ifccParser::T__6: {
        enterOuterAlt(_localctx, 2);
        setState(77);
        match(ifccParser::T__6);
        setState(78);
        equalexpr_stmt();
        setState(83);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == ifccParser::T__4) {
          setState(79);
          match(ifccParser::T__4);
          setState(80);
          equalexpr_stmt();
          setState(85);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(86);
        match(ifccParser::T__5);
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

//----------------- Equalexpr_stmtContext ------------------------------------------------------------------

ifccParser::Equalexpr_stmtContext::Equalexpr_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::Equalexpr_stmtContext::ID() {
  return getToken(ifccParser::ID, 0);
}

ifccParser::ExprContext* ifccParser::Equalexpr_stmtContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}


size_t ifccParser::Equalexpr_stmtContext::getRuleIndex() const {
  return ifccParser::RuleEqualexpr_stmt;
}

antlrcpp::Any ifccParser::Equalexpr_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitEqualexpr_stmt(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::Equalexpr_stmtContext* ifccParser::equalexpr_stmt() {
  Equalexpr_stmtContext *_localctx = _tracker.createInstance<Equalexpr_stmtContext>(_ctx, getState());
  enterRule(_localctx, 10, ifccParser::RuleEqualexpr_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    match(ifccParser::ID);
    setState(93);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ifccParser::T__7) {
      setState(91);
      match(ifccParser::T__7);
      setState(92);
      expr(0);
    }
   
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

antlrcpp::Any ifccParser::Assign_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAssign_stmt(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::Assign_stmtContext* ifccParser::assign_stmt() {
  Assign_stmtContext *_localctx = _tracker.createInstance<Assign_stmtContext>(_ctx, getState());
  enterRule(_localctx, 12, ifccParser::RuleAssign_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    match(ifccParser::ID);
    setState(96);
    match(ifccParser::T__7);
    setState(97);
    expr(0);
    setState(98);
    match(ifccParser::T__5);
   
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

antlrcpp::Any ifccParser::Return_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitReturn_stmt(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::Return_stmtContext* ifccParser::return_stmt() {
  Return_stmtContext *_localctx = _tracker.createInstance<Return_stmtContext>(_ctx, getState());
  enterRule(_localctx, 14, ifccParser::RuleReturn_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    match(ifccParser::RETURN);
    setState(101);
    expr(0);
    setState(102);
    match(ifccParser::T__5);
   
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

//----------------- ParentContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::ParentContext::OPENPARENT() {
  return getToken(ifccParser::OPENPARENT, 0);
}

ifccParser::ExprContext* ifccParser::ParentContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

tree::TerminalNode* ifccParser::ParentContext::CLOSEPARENT() {
  return getToken(ifccParser::CLOSEPARENT, 0);
}

ifccParser::ParentContext::ParentContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::ParentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitParent(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::CompContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::CompContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

tree::TerminalNode* ifccParser::CompContext::COMP() {
  return getToken(ifccParser::COMP, 0);
}

ifccParser::CompContext::CompContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::CompContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitComp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::OrContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::OrContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

tree::TerminalNode* ifccParser::OrContext::OR() {
  return getToken(ifccParser::OR, 0);
}

ifccParser::OrContext::OrContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::OrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitOr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MoinContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::MoinContext::OPA() {
  return getToken(ifccParser::OPA, 0);
}

ifccParser::ExprContext* ifccParser::MoinContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

ifccParser::MoinContext::MoinContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::MoinContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitMoin(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::ConstContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::ConstContext::ConstContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::ConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::FunctContext::ID() {
  return getToken(ifccParser::ID, 0);
}

tree::TerminalNode* ifccParser::FunctContext::OPENPARENT() {
  return getToken(ifccParser::OPENPARENT, 0);
}

tree::TerminalNode* ifccParser::FunctContext::CLOSEPARENT() {
  return getToken(ifccParser::CLOSEPARENT, 0);
}

ifccParser::FunctContext::FunctContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::FunctContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitFunct(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::MulContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::MulContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

tree::TerminalNode* ifccParser::MulContext::OPM() {
  return getToken(ifccParser::OPM, 0);
}

ifccParser::MulContext::MulContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::MulContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitMul(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AndContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::AndContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::AndContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

tree::TerminalNode* ifccParser::AndContext::AND() {
  return getToken(ifccParser::AND, 0);
}

ifccParser::AndContext::AndContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::AndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- XorContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::XorContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::XorContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

tree::TerminalNode* ifccParser::XorContext::XOR() {
  return getToken(ifccParser::XOR, 0);
}

ifccParser::XorContext::XorContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::XorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitXor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::UnaryContext::UNARY() {
  return getToken(ifccParser::UNARY, 0);
}

ifccParser::ExprContext* ifccParser::UnaryContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

ifccParser::UnaryContext::UnaryContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::IdContext::ID() {
  return getToken(ifccParser::ID, 0);
}

ifccParser::IdContext::IdContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::IdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::PlusContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::PlusContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

tree::TerminalNode* ifccParser::PlusContext::OPA() {
  return getToken(ifccParser::OPA, 0);
}

ifccParser::PlusContext::PlusContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::PlusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitPlus(this);
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
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, ifccParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(118);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<UnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(105);
      match(ifccParser::UNARY);
      setState(106);
      expr(12);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MoinContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(107);
      match(ifccParser::OPA);
      setState(108);
      expr(11);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ConstContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(109);
      match(ifccParser::CONST);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<FunctContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(110);
      match(ifccParser::ID);
      setState(111);
      match(ifccParser::OPENPARENT);
      setState(112);
      match(ifccParser::CLOSEPARENT);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<IdContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(113);
      match(ifccParser::ID);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ParentContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(114);
      match(ifccParser::OPENPARENT);
      setState(115);
      expr(0);
      setState(116);
      match(ifccParser::CLOSEPARENT);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(140);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(138);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(120);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(121);
          match(ifccParser::OPM);
          setState(122);
          expr(11);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(123);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(124);
          match(ifccParser::OPA);
          setState(125);
          expr(10);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(126);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(127);
          match(ifccParser::AND);
          setState(128);
          expr(9);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<XorContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(129);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(130);
          match(ifccParser::XOR);
          setState(131);
          expr(8);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<OrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(132);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(133);
          match(ifccParser::OR);
          setState(134);
          expr(7);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<CompContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(135);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(136);
          match(ifccParser::COMP);
          setState(137);
          expr(6);
          break;
        }

        } 
      }
      setState(142);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
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
    case 8: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ifccParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 10);
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 8);
    case 3: return precpred(_ctx, 7);
    case 4: return precpred(_ctx, 6);
    case 5: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ifccParser::_decisionToDFA;
atn::PredictionContextCache ifccParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ifccParser::_atn;
std::vector<uint16_t> ifccParser::_serializedATN;

std::vector<std::string> ifccParser::_ruleNames = {
  "axiom", "progs", "prog", "stmt", "decl_stmt", "equalexpr_stmt", "assign_stmt", 
  "return_stmt", "expr"
};

std::vector<std::string> ifccParser::_literalNames = {
  "", "'int'", "'{'", "'}'", "'void'", "','", "';'", "'char'", "'='", "'return'", 
  "", "", "", "", "", "", "'!'", "'|'", "'&'", "'^'", "", "", "'('", "')'"
};

std::vector<std::string> ifccParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "RETURN", "ID", "CONST", "COMMENT", 
  "DIRECTIVE", "WS", "COMP", "UNARY", "OR", "AND", "XOR", "OPA", "OPM", 
  "OPENPARENT", "CLOSEPARENT"
};

dfa::Vocabulary ifccParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ifccParser::_tokenNames;

ifccParser::Initializer::Initializer() {
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

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x19, 0x92, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x7, 0x3, 0x19, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 
    0x1c, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x7, 0x4, 0x24, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x27, 0xb, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 
    0x4, 0x30, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x33, 0xb, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x36, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x7, 0x5, 0x3d, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x40, 0xb, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x43, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 
    0x6, 0x49, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x4c, 0xb, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x54, 0xa, 0x6, 
    0xc, 0x6, 0xe, 0x6, 0x57, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x5b, 
    0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x60, 0xa, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x5, 0xa, 0x79, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x7, 0xa, 0x8d, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x90, 0xb, 0xa, 
    0x3, 0xa, 0x2, 0x3, 0x12, 0xb, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x2, 0x2, 0x2, 0x9f, 0x2, 0x14, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1a, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x35, 0x3, 0x2, 0x2, 0x2, 0x8, 0x42, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x5a, 0x3, 0x2, 0x2, 0x2, 0xc, 0x5c, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x61, 0x3, 0x2, 0x2, 0x2, 0x10, 0x66, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x78, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x5, 0x4, 0x3, 0x2, 0x15, 0x16, 
    0x7, 0x2, 0x2, 0x3, 0x16, 0x3, 0x3, 0x2, 0x2, 0x2, 0x17, 0x19, 0x5, 
    0x6, 0x4, 0x2, 0x18, 0x17, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1c, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x18, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x1b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1a, 0x3, 0x2, 0x2, 0x2, 
    0x1d, 0x1e, 0x7, 0x3, 0x2, 0x2, 0x1e, 0x1f, 0x7, 0xc, 0x2, 0x2, 0x1f, 
    0x20, 0x7, 0x18, 0x2, 0x2, 0x20, 0x21, 0x7, 0x19, 0x2, 0x2, 0x21, 0x25, 
    0x7, 0x4, 0x2, 0x2, 0x22, 0x24, 0x5, 0x8, 0x5, 0x2, 0x23, 0x22, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x27, 0x3, 0x2, 0x2, 0x2, 0x25, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0x25, 0x26, 0x3, 0x2, 0x2, 0x2, 0x26, 0x28, 0x3, 0x2, 0x2, 
    0x2, 0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x28, 0x36, 0x7, 0x5, 0x2, 0x2, 
    0x29, 0x2a, 0x7, 0x6, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0xc, 0x2, 0x2, 0x2b, 
    0x2c, 0x7, 0x18, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x19, 0x2, 0x2, 0x2d, 0x31, 
    0x7, 0x4, 0x2, 0x2, 0x2e, 0x30, 0x5, 0x8, 0x5, 0x2, 0x2f, 0x2e, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x33, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 0x32, 0x34, 0x3, 0x2, 0x2, 
    0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x34, 0x36, 0x7, 0x5, 0x2, 0x2, 
    0x35, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x35, 0x29, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x37, 0x43, 0x5, 0xa, 0x6, 0x2, 0x38, 0x43, 
    0x5, 0xe, 0x8, 0x2, 0x39, 0x43, 0x5, 0x10, 0x9, 0x2, 0x3a, 0x3e, 0x7, 
    0x4, 0x2, 0x2, 0x3b, 0x3d, 0x5, 0x8, 0x5, 0x2, 0x3c, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x3d, 0x40, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x41, 0x43, 0x7, 0x5, 0x2, 0x2, 0x42, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x42, 0x38, 0x3, 0x2, 0x2, 0x2, 0x42, 0x39, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x43, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0x3, 0x2, 0x2, 0x45, 0x4a, 0x5, 0xc, 
    0x7, 0x2, 0x46, 0x47, 0x7, 0x7, 0x2, 0x2, 0x47, 0x49, 0x5, 0xc, 0x7, 
    0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4b, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 
    0x7, 0x8, 0x2, 0x2, 0x4e, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x7, 
    0x9, 0x2, 0x2, 0x50, 0x55, 0x5, 0xc, 0x7, 0x2, 0x51, 0x52, 0x7, 0x7, 
    0x2, 0x2, 0x52, 0x54, 0x5, 0xc, 0x7, 0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x54, 0x57, 0x3, 0x2, 0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x55, 0x56, 0x3, 0x2, 0x2, 0x2, 0x56, 0x58, 0x3, 0x2, 0x2, 0x2, 0x57, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x7, 0x8, 0x2, 0x2, 0x59, 0x5b, 
    0x3, 0x2, 0x2, 0x2, 0x5a, 0x44, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x4f, 0x3, 
    0x2, 0x2, 0x2, 0x5b, 0xb, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5f, 0x7, 0xc, 
    0x2, 0x2, 0x5d, 0x5e, 0x7, 0xa, 0x2, 0x2, 0x5e, 0x60, 0x5, 0x12, 0xa, 
    0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 
    0x60, 0xd, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x7, 0xc, 0x2, 0x2, 0x62, 
    0x63, 0x7, 0xa, 0x2, 0x2, 0x63, 0x64, 0x5, 0x12, 0xa, 0x2, 0x64, 0x65, 
    0x7, 0x8, 0x2, 0x2, 0x65, 0xf, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x7, 
    0xb, 0x2, 0x2, 0x67, 0x68, 0x5, 0x12, 0xa, 0x2, 0x68, 0x69, 0x7, 0x8, 
    0x2, 0x2, 0x69, 0x11, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x8, 0xa, 0x1, 
    0x2, 0x6b, 0x6c, 0x7, 0x12, 0x2, 0x2, 0x6c, 0x79, 0x5, 0x12, 0xa, 0xe, 
    0x6d, 0x6e, 0x7, 0x16, 0x2, 0x2, 0x6e, 0x79, 0x5, 0x12, 0xa, 0xd, 0x6f, 
    0x79, 0x7, 0xd, 0x2, 0x2, 0x70, 0x71, 0x7, 0xc, 0x2, 0x2, 0x71, 0x72, 
    0x7, 0x18, 0x2, 0x2, 0x72, 0x79, 0x7, 0x19, 0x2, 0x2, 0x73, 0x79, 0x7, 
    0xc, 0x2, 0x2, 0x74, 0x75, 0x7, 0x18, 0x2, 0x2, 0x75, 0x76, 0x5, 0x12, 
    0xa, 0x2, 0x76, 0x77, 0x7, 0x19, 0x2, 0x2, 0x77, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x78, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x78, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x78, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x78, 0x70, 0x3, 0x2, 0x2, 0x2, 0x78, 
    0x73, 0x3, 0x2, 0x2, 0x2, 0x78, 0x74, 0x3, 0x2, 0x2, 0x2, 0x79, 0x8e, 
    0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0xc, 0xc, 0x2, 0x2, 0x7b, 0x7c, 0x7, 
    0x17, 0x2, 0x2, 0x7c, 0x8d, 0x5, 0x12, 0xa, 0xd, 0x7d, 0x7e, 0xc, 0xb, 
    0x2, 0x2, 0x7e, 0x7f, 0x7, 0x16, 0x2, 0x2, 0x7f, 0x8d, 0x5, 0x12, 0xa, 
    0xc, 0x80, 0x81, 0xc, 0xa, 0x2, 0x2, 0x81, 0x82, 0x7, 0x14, 0x2, 0x2, 
    0x82, 0x8d, 0x5, 0x12, 0xa, 0xb, 0x83, 0x84, 0xc, 0x9, 0x2, 0x2, 0x84, 
    0x85, 0x7, 0x15, 0x2, 0x2, 0x85, 0x8d, 0x5, 0x12, 0xa, 0xa, 0x86, 0x87, 
    0xc, 0x8, 0x2, 0x2, 0x87, 0x88, 0x7, 0x13, 0x2, 0x2, 0x88, 0x8d, 0x5, 
    0x12, 0xa, 0x9, 0x89, 0x8a, 0xc, 0x7, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x11, 
    0x2, 0x2, 0x8b, 0x8d, 0x5, 0x12, 0xa, 0x8, 0x8c, 0x7a, 0x3, 0x2, 0x2, 
    0x2, 0x8c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x80, 0x3, 0x2, 0x2, 0x2, 
    0x8c, 0x83, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x86, 0x3, 0x2, 0x2, 0x2, 0x8c, 
    0x89, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8c, 
    0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0xf, 0x1a, 0x25, 0x31, 
    0x35, 0x3e, 0x42, 0x4a, 0x55, 0x5a, 0x5f, 0x78, 0x8c, 0x8e, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ifccParser::Initializer ifccParser::_init;
