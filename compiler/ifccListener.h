
// Generated from ifcc.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ifccParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ifccParser.
 */
class  ifccListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterAxiom(ifccParser::AxiomContext *ctx) = 0;
  virtual void exitAxiom(ifccParser::AxiomContext *ctx) = 0;

  virtual void enterProg(ifccParser::ProgContext *ctx) = 0;
  virtual void exitProg(ifccParser::ProgContext *ctx) = 0;

  virtual void enterStmt(ifccParser::StmtContext *ctx) = 0;
  virtual void exitStmt(ifccParser::StmtContext *ctx) = 0;

  virtual void enterDecl_stmt(ifccParser::Decl_stmtContext *ctx) = 0;
  virtual void exitDecl_stmt(ifccParser::Decl_stmtContext *ctx) = 0;

  virtual void enterAssign_stmt(ifccParser::Assign_stmtContext *ctx) = 0;
  virtual void exitAssign_stmt(ifccParser::Assign_stmtContext *ctx) = 0;

  virtual void enterReturn_stmt(ifccParser::Return_stmtContext *ctx) = 0;
  virtual void exitReturn_stmt(ifccParser::Return_stmtContext *ctx) = 0;

  virtual void enterExpr(ifccParser::ExprContext *ctx) = 0;
  virtual void exitExpr(ifccParser::ExprContext *ctx) = 0;

  virtual void enterExprc(ifccParser::ExprcContext *ctx) = 0;
  virtual void exitExprc(ifccParser::ExprcContext *ctx) = 0;

  virtual void enterMult_expr(ifccParser::Mult_exprContext *ctx) = 0;
  virtual void exitMult_expr(ifccParser::Mult_exprContext *ctx) = 0;

  virtual void enterPrimary_expr(ifccParser::Primary_exprContext *ctx) = 0;
  virtual void exitPrimary_expr(ifccParser::Primary_exprContext *ctx) = 0;


};

