
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

    virtual antlrcpp::Any visitProgs(ifccParser::ProgsContext *context) = 0;

    virtual antlrcpp::Any visitProg(ifccParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitDecl(ifccParser::DeclContext *context) = 0;

    virtual antlrcpp::Any visitAssign(ifccParser::AssignContext *context) = 0;

    virtual antlrcpp::Any visitRet(ifccParser::RetContext *context) = 0;

    virtual antlrcpp::Any visitBlock(ifccParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitDecl_stmt(ifccParser::Decl_stmtContext *context) = 0;

    virtual antlrcpp::Any visitEqualexpr_stmt(ifccParser::Equalexpr_stmtContext *context) = 0;

    virtual antlrcpp::Any visitAssign_stmt(ifccParser::Assign_stmtContext *context) = 0;

    virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *context) = 0;

    virtual antlrcpp::Any visitParent(ifccParser::ParentContext *context) = 0;

    virtual antlrcpp::Any visitComp(ifccParser::CompContext *context) = 0;

    virtual antlrcpp::Any visitOr(ifccParser::OrContext *context) = 0;

    virtual antlrcpp::Any visitMoin(ifccParser::MoinContext *context) = 0;

    virtual antlrcpp::Any visitConst(ifccParser::ConstContext *context) = 0;

    virtual antlrcpp::Any visitFunct(ifccParser::FunctContext *context) = 0;

    virtual antlrcpp::Any visitMul(ifccParser::MulContext *context) = 0;

    virtual antlrcpp::Any visitAnd(ifccParser::AndContext *context) = 0;

    virtual antlrcpp::Any visitXor(ifccParser::XorContext *context) = 0;

    virtual antlrcpp::Any visitUnary(ifccParser::UnaryContext *context) = 0;

    virtual antlrcpp::Any visitId(ifccParser::IdContext *context) = 0;

    virtual antlrcpp::Any visitPlus(ifccParser::PlusContext *context) = 0;


};

