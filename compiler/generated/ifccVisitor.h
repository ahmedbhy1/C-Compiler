
// Generated from ifcc.g4 by ANTLR 4.13.2

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
    virtual std::any visitAxiom(ifccParser::AxiomContext *context) = 0;

    virtual std::any visitProg(ifccParser::ProgContext *context) = 0;

    virtual std::any visitStmt(ifccParser::StmtContext *context) = 0;

    virtual std::any visitDecl_stmt(ifccParser::Decl_stmtContext *context) = 0;

    virtual std::any visitAssign_stmt(ifccParser::Assign_stmtContext *context) = 0;

    virtual std::any visitReturn_stmt(ifccParser::Return_stmtContext *context) = 0;

    virtual std::any visitBitwiseAndExpr(ifccParser::BitwiseAndExprContext *context) = 0;

    virtual std::any visitBitwiseOrExpr(ifccParser::BitwiseOrExprContext *context) = 0;

    virtual std::any visitIdentifierExpr(ifccParser::IdentifierExprContext *context) = 0;

    virtual std::any visitConstantExpr(ifccParser::ConstantExprContext *context) = 0;

    virtual std::any visitParenthesizedExpr(ifccParser::ParenthesizedExprContext *context) = 0;

    virtual std::any visitBitwiseXorExpr(ifccParser::BitwiseXorExprContext *context) = 0;


};

