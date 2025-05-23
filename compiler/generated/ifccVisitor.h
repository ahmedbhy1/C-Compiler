
// Generated from ifcc.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ifccParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ifccParser.
 */
class  ifccVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ifccParser.
   */
    virtual antlrcpp::Any visitAxiom(ifccParser::AxiomContext *context) = 0;

    virtual antlrcpp::Any visitProg(ifccParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitStmt(ifccParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitDecl_stmt(ifccParser::Decl_stmtContext *context) = 0;

    virtual antlrcpp::Any visitAssign_stmt(ifccParser::Assign_stmtContext *context) = 0;

    virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *context) = 0;

    virtual antlrcpp::Any visitExpr(ifccParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitExprc(ifccParser::ExprcContext *context) = 0;

    virtual antlrcpp::Any visitXor_expr(ifccParser::Xor_exprContext *context) = 0;

    virtual antlrcpp::Any visitAnd_expr(ifccParser::And_exprContext *context) = 0;

    virtual antlrcpp::Any visitAdd_expr(ifccParser::Add_exprContext *context) = 0;

    virtual antlrcpp::Any visitMult_expr(ifccParser::Mult_exprContext *context) = 0;

    virtual antlrcpp::Any visitUnary_expr(ifccParser::Unary_exprContext *context) = 0;

    virtual antlrcpp::Any visitPrimary_expr(ifccParser::Primary_exprContext *context) = 0;


};

