
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

ifccParser::ProgContext* ifccParser::AxiomContext::prog() {
  return getRuleContext<ifccParser::ProgContext>(0);
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
    setState(28);
    prog();
    setState(29);
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

antlrcpp::Any ifccParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ProgContext* ifccParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 2, ifccParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31);
    match(ifccParser::T__0);
    setState(32);
    match(ifccParser::T__1);
    setState(33);
    match(ifccParser::T__2);
    setState(34);
    match(ifccParser::T__3);
    setState(35);
    match(ifccParser::T__4);
    setState(39);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ifccParser::T__0)
      | (1ULL << ifccParser::T__9)
      | (1ULL << ifccParser::RETURN)
      | (1ULL << ifccParser::ID))) != 0)) {
      setState(36);
      stmt();
      setState(41);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(42);
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

antlrcpp::Any ifccParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::StmtContext* ifccParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 4, ifccParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(47);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__0:
      case ifccParser::T__9: {
        enterOuterAlt(_localctx, 1);
        setState(44);
        decl_stmt();
        break;
      }

      case ifccParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(45);
        assign_stmt();
        break;
      }

      case ifccParser::RETURN: {
        enterOuterAlt(_localctx, 3);
        setState(46);
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

std::vector<tree::TerminalNode *> ifccParser::Decl_stmtContext::ID() {
  return getTokens(ifccParser::ID);
}

tree::TerminalNode* ifccParser::Decl_stmtContext::ID(size_t i) {
  return getToken(ifccParser::ID, i);
}

ifccParser::ExprContext* ifccParser::Decl_stmtContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
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
  enterRule(_localctx, 6, ifccParser::RuleDecl_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(77);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(49);
        match(ifccParser::T__0);
        setState(50);
        match(ifccParser::ID);
        setState(55);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == ifccParser::T__6) {
          setState(51);
          match(ifccParser::T__6);
          setState(52);
          match(ifccParser::ID);
          setState(57);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(60);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == ifccParser::T__7) {
          setState(58);
          match(ifccParser::T__7);
          setState(59);
          expr();
        }
        setState(62);
        match(ifccParser::T__8);
        break;
      }

      case ifccParser::T__9: {
        enterOuterAlt(_localctx, 2);
        setState(63);
        match(ifccParser::T__9);
        setState(64);
        match(ifccParser::ID);
        setState(69);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == ifccParser::T__6) {
          setState(65);
          match(ifccParser::T__6);
          setState(66);
          match(ifccParser::ID);
          setState(71);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(74);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == ifccParser::T__7) {
          setState(72);
          match(ifccParser::T__7);
          setState(73);
          expr();
        }
        setState(76);
        match(ifccParser::T__8);
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
  enterRule(_localctx, 8, ifccParser::RuleAssign_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    match(ifccParser::ID);
    setState(80);
    match(ifccParser::T__7);
    setState(81);
    expr();
    setState(82);
    match(ifccParser::T__8);
   
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
  enterRule(_localctx, 10, ifccParser::RuleReturn_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    match(ifccParser::RETURN);
    setState(85);
    expr();
    setState(86);
    match(ifccParser::T__8);
   
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

ifccParser::ExprcContext* ifccParser::ExprContext::exprc() {
  return getRuleContext<ifccParser::ExprcContext>(0);
}

tree::TerminalNode* ifccParser::ExprContext::COMP() {
  return getToken(ifccParser::COMP, 0);
}

ifccParser::ExprContext* ifccParser::ExprContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

tree::TerminalNode* ifccParser::ExprContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}

tree::TerminalNode* ifccParser::ExprContext::ID() {
  return getToken(ifccParser::ID, 0);
}


size_t ifccParser::ExprContext::getRuleIndex() const {
  return ifccParser::RuleExpr;
}

antlrcpp::Any ifccParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ExprContext* ifccParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 12, ifccParser::RuleExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(95);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(88);
      exprc();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(89);
      exprc();
      setState(90);
      match(ifccParser::COMP);
      setState(91);
      expr();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(93);
      match(ifccParser::CONST);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(94);
      match(ifccParser::ID);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprcContext ------------------------------------------------------------------

ifccParser::ExprcContext::ExprcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::Xor_exprContext* ifccParser::ExprcContext::xor_expr() {
  return getRuleContext<ifccParser::Xor_exprContext>(0);
}

tree::TerminalNode* ifccParser::ExprcContext::OR() {
  return getToken(ifccParser::OR, 0);
}

ifccParser::ExprcContext* ifccParser::ExprcContext::exprc() {
  return getRuleContext<ifccParser::ExprcContext>(0);
}


size_t ifccParser::ExprcContext::getRuleIndex() const {
  return ifccParser::RuleExprc;
}

antlrcpp::Any ifccParser::ExprcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitExprc(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ExprcContext* ifccParser::exprc() {
  ExprcContext *_localctx = _tracker.createInstance<ExprcContext>(_ctx, getState());
  enterRule(_localctx, 14, ifccParser::RuleExprc);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(102);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(97);
      xor_expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(98);
      xor_expr();
      setState(99);
      match(ifccParser::OR);
      setState(100);
      exprc();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Xor_exprContext ------------------------------------------------------------------

ifccParser::Xor_exprContext::Xor_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::And_exprContext* ifccParser::Xor_exprContext::and_expr() {
  return getRuleContext<ifccParser::And_exprContext>(0);
}

tree::TerminalNode* ifccParser::Xor_exprContext::XOR() {
  return getToken(ifccParser::XOR, 0);
}

ifccParser::Xor_exprContext* ifccParser::Xor_exprContext::xor_expr() {
  return getRuleContext<ifccParser::Xor_exprContext>(0);
}


size_t ifccParser::Xor_exprContext::getRuleIndex() const {
  return ifccParser::RuleXor_expr;
}

antlrcpp::Any ifccParser::Xor_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitXor_expr(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::Xor_exprContext* ifccParser::xor_expr() {
  Xor_exprContext *_localctx = _tracker.createInstance<Xor_exprContext>(_ctx, getState());
  enterRule(_localctx, 16, ifccParser::RuleXor_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(109);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(104);
      and_expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(105);
      and_expr();
      setState(106);
      match(ifccParser::XOR);
      setState(107);
      xor_expr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- And_exprContext ------------------------------------------------------------------

ifccParser::And_exprContext::And_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::Add_exprContext* ifccParser::And_exprContext::add_expr() {
  return getRuleContext<ifccParser::Add_exprContext>(0);
}

tree::TerminalNode* ifccParser::And_exprContext::AND() {
  return getToken(ifccParser::AND, 0);
}

ifccParser::And_exprContext* ifccParser::And_exprContext::and_expr() {
  return getRuleContext<ifccParser::And_exprContext>(0);
}


size_t ifccParser::And_exprContext::getRuleIndex() const {
  return ifccParser::RuleAnd_expr;
}

antlrcpp::Any ifccParser::And_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAnd_expr(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::And_exprContext* ifccParser::and_expr() {
  And_exprContext *_localctx = _tracker.createInstance<And_exprContext>(_ctx, getState());
  enterRule(_localctx, 18, ifccParser::RuleAnd_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(116);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(111);
      add_expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(112);
      add_expr();
      setState(113);
      match(ifccParser::AND);
      setState(114);
      and_expr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Add_exprContext ------------------------------------------------------------------

ifccParser::Add_exprContext::Add_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::Mult_exprContext* ifccParser::Add_exprContext::mult_expr() {
  return getRuleContext<ifccParser::Mult_exprContext>(0);
}

tree::TerminalNode* ifccParser::Add_exprContext::OPA() {
  return getToken(ifccParser::OPA, 0);
}

ifccParser::Add_exprContext* ifccParser::Add_exprContext::add_expr() {
  return getRuleContext<ifccParser::Add_exprContext>(0);
}


size_t ifccParser::Add_exprContext::getRuleIndex() const {
  return ifccParser::RuleAdd_expr;
}

antlrcpp::Any ifccParser::Add_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAdd_expr(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::Add_exprContext* ifccParser::add_expr() {
  Add_exprContext *_localctx = _tracker.createInstance<Add_exprContext>(_ctx, getState());
  enterRule(_localctx, 20, ifccParser::RuleAdd_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(123);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(118);
      mult_expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(119);
      mult_expr();
      setState(120);
      match(ifccParser::OPA);
      setState(121);
      add_expr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mult_exprContext ------------------------------------------------------------------

ifccParser::Mult_exprContext::Mult_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::Unary_exprContext* ifccParser::Mult_exprContext::unary_expr() {
  return getRuleContext<ifccParser::Unary_exprContext>(0);
}

tree::TerminalNode* ifccParser::Mult_exprContext::OPM() {
  return getToken(ifccParser::OPM, 0);
}

ifccParser::Mult_exprContext* ifccParser::Mult_exprContext::mult_expr() {
  return getRuleContext<ifccParser::Mult_exprContext>(0);
}


size_t ifccParser::Mult_exprContext::getRuleIndex() const {
  return ifccParser::RuleMult_expr;
}

antlrcpp::Any ifccParser::Mult_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitMult_expr(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::Mult_exprContext* ifccParser::mult_expr() {
  Mult_exprContext *_localctx = _tracker.createInstance<Mult_exprContext>(_ctx, getState());
  enterRule(_localctx, 22, ifccParser::RuleMult_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(130);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(125);
      unary_expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(126);
      unary_expr();
      setState(127);
      match(ifccParser::OPM);
      setState(128);
      mult_expr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_exprContext ------------------------------------------------------------------

ifccParser::Unary_exprContext::Unary_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::Primary_exprContext* ifccParser::Unary_exprContext::primary_expr() {
  return getRuleContext<ifccParser::Primary_exprContext>(0);
}

tree::TerminalNode* ifccParser::Unary_exprContext::UNARY() {
  return getToken(ifccParser::UNARY, 0);
}

ifccParser::Unary_exprContext* ifccParser::Unary_exprContext::unary_expr() {
  return getRuleContext<ifccParser::Unary_exprContext>(0);
}

tree::TerminalNode* ifccParser::Unary_exprContext::OPA() {
  return getToken(ifccParser::OPA, 0);
}


size_t ifccParser::Unary_exprContext::getRuleIndex() const {
  return ifccParser::RuleUnary_expr;
}

antlrcpp::Any ifccParser::Unary_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitUnary_expr(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::Unary_exprContext* ifccParser::unary_expr() {
  Unary_exprContext *_localctx = _tracker.createInstance<Unary_exprContext>(_ctx, getState());
  enterRule(_localctx, 24, ifccParser::RuleUnary_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(137);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__2:
      case ifccParser::ID:
      case ifccParser::CONST: {
        enterOuterAlt(_localctx, 1);
        setState(132);
        primary_expr();
        break;
      }

      case ifccParser::UNARY: {
        enterOuterAlt(_localctx, 2);
        setState(133);
        match(ifccParser::UNARY);
        setState(134);
        unary_expr();
        break;
      }

      case ifccParser::OPA: {
        enterOuterAlt(_localctx, 3);
        setState(135);
        match(ifccParser::OPA);
        setState(136);
        unary_expr();
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

//----------------- Primary_exprContext ------------------------------------------------------------------

ifccParser::Primary_exprContext::Primary_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::Primary_exprContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}

tree::TerminalNode* ifccParser::Primary_exprContext::ID() {
  return getToken(ifccParser::ID, 0);
}

ifccParser::ExprcContext* ifccParser::Primary_exprContext::exprc() {
  return getRuleContext<ifccParser::ExprcContext>(0);
}


size_t ifccParser::Primary_exprContext::getRuleIndex() const {
  return ifccParser::RulePrimary_expr;
}

antlrcpp::Any ifccParser::Primary_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitPrimary_expr(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::Primary_exprContext* ifccParser::primary_expr() {
  Primary_exprContext *_localctx = _tracker.createInstance<Primary_exprContext>(_ctx, getState());
  enterRule(_localctx, 26, ifccParser::RulePrimary_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(145);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::CONST: {
        enterOuterAlt(_localctx, 1);
        setState(139);
        match(ifccParser::CONST);
        break;
      }

      case ifccParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(140);
        match(ifccParser::ID);
        break;
      }

      case ifccParser::T__2: {
        enterOuterAlt(_localctx, 3);
        setState(141);
        match(ifccParser::T__2);
        setState(142);
        exprc();
        setState(143);
        match(ifccParser::T__3);
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

// Static vars and initialization.
std::vector<dfa::DFA> ifccParser::_decisionToDFA;
atn::PredictionContextCache ifccParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ifccParser::_atn;
std::vector<uint16_t> ifccParser::_serializedATN;

std::vector<std::string> ifccParser::_ruleNames = {
  "axiom", "prog", "stmt", "decl_stmt", "assign_stmt", "return_stmt", "expr", 
  "exprc", "xor_expr", "and_expr", "add_expr", "mult_expr", "unary_expr", 
  "primary_expr"
};

std::vector<std::string> ifccParser::_literalNames = {
  "", "'int'", "'main'", "'('", "')'", "'{'", "'}'", "','", "'='", "';'", 
  "'char'", "'return'", "", "", "", "", "", "", "'!'", "'|'", "'&'", "'^'"
};

std::vector<std::string> ifccParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "RETURN", "ID", "CONST", "COMMENT", 
  "DIRECTIVE", "WS", "COMP", "UNARY", "OR", "AND", "XOR", "OPA", "OPM"
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
    0x3, 0x19, 0x96, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x28, 0xa, 0x3, 0xc, 0x3, 
    0xe, 0x3, 0x2b, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x5, 0x4, 0x32, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x7, 0x5, 0x38, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x3b, 0xb, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x3f, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x7, 0x5, 0x46, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x49, 0xb, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x4d, 0xa, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x50, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x62, 0xa, 0x8, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x69, 0xa, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x70, 0xa, 0xa, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x77, 0xa, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x7e, 
    0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 
    0x85, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 
    0xe, 0x8c, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x5, 0xf, 0x94, 0xa, 0xf, 0x3, 0xf, 0x2, 0x2, 0x10, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x2, 
    0x2, 0x2, 0x9b, 0x2, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x4, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x31, 0x3, 0x2, 0x2, 0x2, 0x8, 0x4f, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x51, 0x3, 0x2, 0x2, 0x2, 0xc, 0x56, 0x3, 0x2, 0x2, 0x2, 0xe, 0x61, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x68, 0x3, 0x2, 0x2, 0x2, 0x12, 0x6f, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x76, 0x3, 0x2, 0x2, 0x2, 0x16, 0x7d, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x84, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x8b, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x93, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x5, 0x4, 0x3, 0x2, 
    0x1f, 0x20, 0x7, 0x2, 0x2, 0x3, 0x20, 0x3, 0x3, 0x2, 0x2, 0x2, 0x21, 
    0x22, 0x7, 0x3, 0x2, 0x2, 0x22, 0x23, 0x7, 0x4, 0x2, 0x2, 0x23, 0x24, 
    0x7, 0x5, 0x2, 0x2, 0x24, 0x25, 0x7, 0x6, 0x2, 0x2, 0x25, 0x29, 0x7, 
    0x7, 0x2, 0x2, 0x26, 0x28, 0x5, 0x6, 0x4, 0x2, 0x27, 0x26, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x29, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0x29, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2c, 0x3, 0x2, 0x2, 0x2, 
    0x2b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x8, 0x2, 0x2, 0x2d, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x32, 0x5, 0x8, 0x5, 0x2, 0x2f, 0x32, 
    0x5, 0xa, 0x6, 0x2, 0x30, 0x32, 0x5, 0xc, 0x7, 0x2, 0x31, 0x2e, 0x3, 
    0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x30, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x7, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 0x3, 0x2, 
    0x2, 0x34, 0x39, 0x7, 0xe, 0x2, 0x2, 0x35, 0x36, 0x7, 0x9, 0x2, 0x2, 
    0x36, 0x38, 0x7, 0xe, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x3b, 0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0xa, 0x2, 0x2, 0x3d, 0x3f, 0x5, 0xe, 
    0x8, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 0x2, 0x40, 0x50, 0x7, 0xb, 0x2, 0x2, 
    0x41, 0x42, 0x7, 0xc, 0x2, 0x2, 0x42, 0x47, 0x7, 0xe, 0x2, 0x2, 0x43, 
    0x44, 0x7, 0x9, 0x2, 0x2, 0x44, 0x46, 0x7, 0xe, 0x2, 0x2, 0x45, 0x43, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x49, 0x3, 0x2, 0x2, 0x2, 0x47, 0x45, 0x3, 
    0x2, 0x2, 0x2, 0x47, 0x48, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0xa, 0x2, 
    0x2, 0x4b, 0x4d, 0x5, 0xe, 0x8, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x50, 0x7, 0xb, 0x2, 0x2, 0x4f, 0x33, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0x50, 0x9, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 
    0xe, 0x2, 0x2, 0x52, 0x53, 0x7, 0xa, 0x2, 0x2, 0x53, 0x54, 0x5, 0xe, 
    0x8, 0x2, 0x54, 0x55, 0x7, 0xb, 0x2, 0x2, 0x55, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x57, 0x7, 0xd, 0x2, 0x2, 0x57, 0x58, 0x5, 0xe, 0x8, 0x2, 
    0x58, 0x59, 0x7, 0xb, 0x2, 0x2, 0x59, 0xd, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x62, 0x5, 0x10, 0x9, 0x2, 0x5b, 0x5c, 0x5, 0x10, 0x9, 0x2, 0x5c, 0x5d, 
    0x7, 0x13, 0x2, 0x2, 0x5d, 0x5e, 0x5, 0xe, 0x8, 0x2, 0x5e, 0x62, 0x3, 
    0x2, 0x2, 0x2, 0x5f, 0x62, 0x7, 0xf, 0x2, 0x2, 0x60, 0x62, 0x7, 0xe, 
    0x2, 0x2, 0x61, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5b, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x61, 0x60, 0x3, 0x2, 0x2, 0x2, 
    0x62, 0xf, 0x3, 0x2, 0x2, 0x2, 0x63, 0x69, 0x5, 0x12, 0xa, 0x2, 0x64, 
    0x65, 0x5, 0x12, 0xa, 0x2, 0x65, 0x66, 0x7, 0x15, 0x2, 0x2, 0x66, 0x67, 
    0x5, 0x10, 0x9, 0x2, 0x67, 0x69, 0x3, 0x2, 0x2, 0x2, 0x68, 0x63, 0x3, 
    0x2, 0x2, 0x2, 0x68, 0x64, 0x3, 0x2, 0x2, 0x2, 0x69, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0x6a, 0x70, 0x5, 0x14, 0xb, 0x2, 0x6b, 0x6c, 0x5, 0x14, 0xb, 
    0x2, 0x6c, 0x6d, 0x7, 0x17, 0x2, 0x2, 0x6d, 0x6e, 0x5, 0x12, 0xa, 0x2, 
    0x6e, 0x70, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6f, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x70, 0x13, 0x3, 0x2, 0x2, 0x2, 0x71, 0x77, 
    0x5, 0x16, 0xc, 0x2, 0x72, 0x73, 0x5, 0x16, 0xc, 0x2, 0x73, 0x74, 0x7, 
    0x16, 0x2, 0x2, 0x74, 0x75, 0x5, 0x14, 0xb, 0x2, 0x75, 0x77, 0x3, 0x2, 
    0x2, 0x2, 0x76, 0x71, 0x3, 0x2, 0x2, 0x2, 0x76, 0x72, 0x3, 0x2, 0x2, 
    0x2, 0x77, 0x15, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7e, 0x5, 0x18, 0xd, 0x2, 
    0x79, 0x7a, 0x5, 0x18, 0xd, 0x2, 0x7a, 0x7b, 0x7, 0x18, 0x2, 0x2, 0x7b, 
    0x7c, 0x5, 0x16, 0xc, 0x2, 0x7c, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x78, 
    0x3, 0x2, 0x2, 0x2, 0x7d, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x7f, 0x85, 0x5, 0x1a, 0xe, 0x2, 0x80, 0x81, 0x5, 0x1a, 
    0xe, 0x2, 0x81, 0x82, 0x7, 0x19, 0x2, 0x2, 0x82, 0x83, 0x5, 0x18, 0xd, 
    0x2, 0x83, 0x85, 0x3, 0x2, 0x2, 0x2, 0x84, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x84, 0x80, 0x3, 0x2, 0x2, 0x2, 0x85, 0x19, 0x3, 0x2, 0x2, 0x2, 0x86, 
    0x8c, 0x5, 0x1c, 0xf, 0x2, 0x87, 0x88, 0x7, 0x14, 0x2, 0x2, 0x88, 0x8c, 
    0x5, 0x1a, 0xe, 0x2, 0x89, 0x8a, 0x7, 0x18, 0x2, 0x2, 0x8a, 0x8c, 0x5, 
    0x1a, 0xe, 0x2, 0x8b, 0x86, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x87, 0x3, 0x2, 
    0x2, 0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x8d, 0x94, 0x7, 0xf, 0x2, 0x2, 0x8e, 0x94, 0x7, 0xe, 0x2, 0x2, 
    0x8f, 0x90, 0x7, 0x5, 0x2, 0x2, 0x90, 0x91, 0x5, 0x10, 0x9, 0x2, 0x91, 
    0x92, 0x7, 0x6, 0x2, 0x2, 0x92, 0x94, 0x3, 0x2, 0x2, 0x2, 0x93, 0x8d, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x93, 0x8f, 0x3, 
    0x2, 0x2, 0x2, 0x94, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x11, 0x29, 0x31, 0x39, 
    0x3e, 0x47, 0x4c, 0x4f, 0x61, 0x68, 0x6f, 0x76, 0x7d, 0x84, 0x8b, 0x93, 
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
