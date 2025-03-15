#pragma once


#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"

class  CodeGenVisitor : public ifccBaseVisitor {
	public:
        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
        virtual antlrcpp::Any visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) override;
        virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;
        virtual antlrcpp::Any visitExpr(ifccParser::ExprContext *ctx) override;
        virtual antlrcpp::Any visitExprc(ifccParser::ExprcContext *ctx) override;
        virtual antlrcpp::Any visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) override;
        virtual antlrcpp::Any visitMult_expr(ifccParser::Mult_exprContext *ctx) override;
        virtual antlrcpp::Any visitPrimary_expr(ifccParser::Primary_exprContext *ctx) override;
private:
        std::map<std::string, int> symbolTable;
        int stackOffset = 0;

};
