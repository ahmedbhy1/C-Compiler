
// Generated from ifcc.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ifccListener.h"


/**
 * This class provides an empty implementation of ifccListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ifccBaseListener : public ifccListener {
public:

  virtual void enterAxiom(ifccParser::AxiomContext * /*ctx*/) override { }
  virtual void exitAxiom(ifccParser::AxiomContext * /*ctx*/) override { }

  virtual void enterProg(ifccParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(ifccParser::ProgContext * /*ctx*/) override { }

  virtual void enterStmt(ifccParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(ifccParser::StmtContext * /*ctx*/) override { }

  virtual void enterDecl_stmt(ifccParser::Decl_stmtContext * /*ctx*/) override { }
  virtual void exitDecl_stmt(ifccParser::Decl_stmtContext * /*ctx*/) override { }

  virtual void enterAssign_stmt(ifccParser::Assign_stmtContext * /*ctx*/) override { }
  virtual void exitAssign_stmt(ifccParser::Assign_stmtContext * /*ctx*/) override { }

  virtual void enterReturn_stmt(ifccParser::Return_stmtContext * /*ctx*/) override { }
  virtual void exitReturn_stmt(ifccParser::Return_stmtContext * /*ctx*/) override { }

  virtual void enterExpr(ifccParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(ifccParser::ExprContext * /*ctx*/) override { }

  virtual void enterExprc(ifccParser::ExprcContext * /*ctx*/) override { }
  virtual void exitExprc(ifccParser::ExprcContext * /*ctx*/) override { }

  virtual void enterMult_expr(ifccParser::Mult_exprContext * /*ctx*/) override { }
  virtual void exitMult_expr(ifccParser::Mult_exprContext * /*ctx*/) override { }

  virtual void enterPrimary_expr(ifccParser::Primary_exprContext * /*ctx*/) override { }
  virtual void exitPrimary_expr(ifccParser::Primary_exprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

