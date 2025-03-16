
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
    setState(20);
    prog();
    setState(21);
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
    setState(23);
    match(ifccParser::T__0);
    setState(24);
    match(ifccParser::T__1);
    setState(25);
    match(ifccParser::T__2);
    setState(26);
    match(ifccParser::T__3);
    setState(27);
    match(ifccParser::T__4);
    setState(31);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ifccParser::T__0)
      | (1ULL << ifccParser::RETURN)
      | (1ULL << ifccParser::ID))) != 0)) {
      setState(28);
      stmt();
      setState(33);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(34);
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
    setState(39);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(36);
        decl_stmt();
        break;
      }

      case ifccParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(37);
        assign_stmt();
        break;
      }

      case ifccParser::RETURN: {
        enterOuterAlt(_localctx, 3);
        setState(38);
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
    enterOuterAlt(_localctx, 1);
    setState(41);
    match(ifccParser::T__0);
    setState(42);
    match(ifccParser::ID);
    setState(45);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ifccParser::T__6) {
      setState(43);
      match(ifccParser::T__6);
      setState(44);
      expr();
    }
    setState(47);
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
    setState(49);
    match(ifccParser::ID);
    setState(50);
    match(ifccParser::T__6);
    setState(51);
    expr();
    setState(52);
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
    setState(54);
    match(ifccParser::RETURN);
    setState(55);
    expr();
    setState(56);
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

tree::TerminalNode* ifccParser::ExprContext::ID() {
  return getToken(ifccParser::ID, 0);
}

tree::TerminalNode* ifccParser::ExprContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::ExprcContext* ifccParser::ExprContext::exprc() {
  return getRuleContext<ifccParser::ExprcContext>(0);
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
    setState(61);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(58);
      match(ifccParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(59);
      match(ifccParser::CONST);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(60);
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

//----------------- ExprcContext ------------------------------------------------------------------

ifccParser::ExprcContext::ExprcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::Mult_exprContext* ifccParser::ExprcContext::mult_expr() {
  return getRuleContext<ifccParser::Mult_exprContext>(0);
}

tree::TerminalNode* ifccParser::ExprcContext::OPA() {
  return getToken(ifccParser::OPA, 0);
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
    setState(68);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(63);
      mult_expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(64);
      mult_expr();
      setState(65);
      match(ifccParser::OPA);
      setState(66);
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

//----------------- Mult_exprContext ------------------------------------------------------------------

ifccParser::Mult_exprContext::Mult_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::Primary_exprContext* ifccParser::Mult_exprContext::primary_expr() {
  return getRuleContext<ifccParser::Primary_exprContext>(0);
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
  enterRule(_localctx, 16, ifccParser::RuleMult_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(70);
      primary_expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(71);
      primary_expr();
      setState(72);
      match(ifccParser::OPM);
      setState(73);
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

tree::TerminalNode* ifccParser::Primary_exprContext::OPA() {
  return getToken(ifccParser::OPA, 0);
}

ifccParser::Primary_exprContext* ifccParser::Primary_exprContext::primary_expr() {
  return getRuleContext<ifccParser::Primary_exprContext>(0);
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
  enterRule(_localctx, 18, ifccParser::RulePrimary_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(87);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::CONST: {
        enterOuterAlt(_localctx, 1);
        setState(77);
        match(ifccParser::CONST);
        break;
      }

      case ifccParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(78);
        match(ifccParser::ID);
        break;
      }

      case ifccParser::T__2: {
        enterOuterAlt(_localctx, 3);
        setState(79);
        match(ifccParser::T__2);
        setState(80);
        exprc();
        setState(81);
        match(ifccParser::T__3);
        break;
      }

      case ifccParser::OPA: {
        enterOuterAlt(_localctx, 4);
        setState(83);
        match(ifccParser::OPA);
        setState(84);
        primary_expr();
        break;
      }

      case ifccParser::T__8: {
        enterOuterAlt(_localctx, 5);
        setState(85);
        match(ifccParser::T__8);
        setState(86);
        primary_expr();
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
  "exprc", "mult_expr", "primary_expr"
};

std::vector<std::string> ifccParser::_literalNames = {
  "", "'int'", "'main'", "'('", "')'", "'{'", "'}'", "'='", "';'", "'!'", 
  "'return'"
};

std::vector<std::string> ifccParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "RETURN", "ID", "CONST", "COMMENT", 
  "DIRECTIVE", "WS", "OPA", "OPM"
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
    0x3, 0x13, 0x5c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x20, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 
    0x23, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x2a, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x30, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x5, 0x8, 0x40, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x47, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x4e, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x5, 0xb, 0x5a, 0xa, 0xb, 0x3, 0xb, 0x2, 0x2, 0xc, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x2, 0x2, 0x2, 0x5d, 0x2, 
    0x16, 0x3, 0x2, 0x2, 0x2, 0x4, 0x19, 0x3, 0x2, 0x2, 0x2, 0x6, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xa, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x38, 0x3, 0x2, 0x2, 0x2, 0xe, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x46, 0x3, 0x2, 0x2, 0x2, 0x12, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x59, 0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 0x5, 0x4, 0x3, 0x2, 0x17, 0x18, 
    0x7, 0x2, 0x2, 0x3, 0x18, 0x3, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 0x7, 
    0x3, 0x2, 0x2, 0x1a, 0x1b, 0x7, 0x4, 0x2, 0x2, 0x1b, 0x1c, 0x7, 0x5, 
    0x2, 0x2, 0x1c, 0x1d, 0x7, 0x6, 0x2, 0x2, 0x1d, 0x21, 0x7, 0x7, 0x2, 
    0x2, 0x1e, 0x20, 0x5, 0x6, 0x4, 0x2, 0x1f, 0x1e, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x23, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 
    0x22, 0x3, 0x2, 0x2, 0x2, 0x22, 0x24, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x7, 0x8, 0x2, 0x2, 0x25, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x26, 0x2a, 0x5, 0x8, 0x5, 0x2, 0x27, 0x2a, 0x5, 0xa, 
    0x6, 0x2, 0x28, 0x2a, 0x5, 0xc, 0x7, 0x2, 0x29, 0x26, 0x3, 0x2, 0x2, 
    0x2, 0x29, 0x27, 0x3, 0x2, 0x2, 0x2, 0x29, 0x28, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 0x7, 0x3, 0x2, 0x2, 0x2c, 
    0x2f, 0x7, 0xd, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0x9, 0x2, 0x2, 0x2e, 0x30, 
    0x5, 0xe, 0x8, 0x2, 0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x31, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x7, 0xa, 
    0x2, 0x2, 0x32, 0x9, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 0xd, 0x2, 
    0x2, 0x34, 0x35, 0x7, 0x9, 0x2, 0x2, 0x35, 0x36, 0x5, 0xe, 0x8, 0x2, 
    0x36, 0x37, 0x7, 0xa, 0x2, 0x2, 0x37, 0xb, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x39, 0x7, 0xc, 0x2, 0x2, 0x39, 0x3a, 0x5, 0xe, 0x8, 0x2, 0x3a, 0x3b, 
    0x7, 0xa, 0x2, 0x2, 0x3b, 0xd, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x40, 0x7, 
    0xd, 0x2, 0x2, 0x3d, 0x40, 0x7, 0xe, 0x2, 0x2, 0x3e, 0x40, 0x5, 0x10, 
    0x9, 0x2, 0x3f, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x41, 0x47, 0x5, 0x12, 0xa, 0x2, 0x42, 0x43, 0x5, 0x12, 0xa, 0x2, 0x43, 
    0x44, 0x7, 0x12, 0x2, 0x2, 0x44, 0x45, 0x5, 0x10, 0x9, 0x2, 0x45, 0x47, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x41, 0x3, 0x2, 0x2, 0x2, 0x46, 0x42, 0x3, 
    0x2, 0x2, 0x2, 0x47, 0x11, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4e, 0x5, 0x14, 
    0xb, 0x2, 0x49, 0x4a, 0x5, 0x14, 0xb, 0x2, 0x4a, 0x4b, 0x7, 0x13, 0x2, 
    0x2, 0x4b, 0x4c, 0x5, 0x12, 0xa, 0x2, 0x4c, 0x4e, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x5a, 0x7, 0xe, 0x2, 0x2, 0x50, 0x5a, 
    0x7, 0xd, 0x2, 0x2, 0x51, 0x52, 0x7, 0x5, 0x2, 0x2, 0x52, 0x53, 0x5, 
    0x10, 0x9, 0x2, 0x53, 0x54, 0x7, 0x6, 0x2, 0x2, 0x54, 0x5a, 0x3, 0x2, 
    0x2, 0x2, 0x55, 0x56, 0x7, 0x12, 0x2, 0x2, 0x56, 0x5a, 0x5, 0x14, 0xb, 
    0x2, 0x57, 0x58, 0x7, 0xb, 0x2, 0x2, 0x58, 0x5a, 0x5, 0x14, 0xb, 0x2, 
    0x59, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x59, 0x50, 0x3, 0x2, 0x2, 0x2, 0x59, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0x59, 0x55, 0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 
    0x3, 0x2, 0x2, 0x2, 0x5a, 0x15, 0x3, 0x2, 0x2, 0x2, 0x9, 0x21, 0x29, 
    0x2f, 0x3f, 0x46, 0x4d, 0x59, 
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
