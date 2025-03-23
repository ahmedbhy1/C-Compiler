#pragma once


#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include <iostream>
#include <map>
#include <variant>
#include <string>

class  CodeGenVisitor : public ifccBaseVisitor {
	public:
        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
        virtual antlrcpp::Any visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) override;
        virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;
        virtual antlrcpp::Any visitExpr(ifccParser::ExprContext *ctx) override;
        virtual antlrcpp::Any visitAdd_expr(ifccParser::Add_exprContext *ctx) override;
        virtual antlrcpp::Any visitAnd_expr(ifccParser::And_exprContext *ctx) override;
        virtual antlrcpp::Any visitXor_expr(ifccParser::Xor_exprContext *ctx) override;
        virtual antlrcpp::Any visitExprc(ifccParser::ExprcContext *ctx) override;
        virtual antlrcpp::Any visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) override;
        virtual antlrcpp::Any visitMult_expr(ifccParser::Mult_exprContext *ctx) override;
        virtual antlrcpp::Any visitPrimary_expr(ifccParser::Primary_exprContext *ctx) override;
        virtual antlrcpp::Any visitUnary_expr(ifccParser::Unary_exprContext *ctx) override;
        
private:
        std::map<std::string, std::pair<int,int>> symbolTable;
        int stackOffset = 0;
        int tempCounter = 0;
        std::string newTemp() {
            return "temp_" + std::to_string(tempCounter++);
        }
};
