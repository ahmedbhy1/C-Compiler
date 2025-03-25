#pragma once


#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include <iostream>
#include <map>
#include <variant>
#include <string>

class  CodeGenVisitor : public ifccBaseVisitor {
	public:
        virtual antlrcpp::Any visitProgs(ifccParser::ProgsContext *ctx) override;
        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
        virtual antlrcpp::Any visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) override;
        virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;
        virtual antlrcpp::Any visitConst(ifccParser::ConstContext *ctx) override;
        virtual antlrcpp::Any visitUnary(ifccParser::UnaryContext *ctx) override;
        virtual antlrcpp::Any visitOr(ifccParser::OrContext *ctx) override;
        virtual antlrcpp::Any visitAnd(ifccParser::AndContext *ctx) override;
        virtual antlrcpp::Any visitXor(ifccParser::XorContext *ctx) override;
        virtual antlrcpp::Any visitPlus(ifccParser::PlusContext *ctx) override;
        virtual antlrcpp::Any visitMul(ifccParser::MulContext *ctx) override;
        virtual antlrcpp::Any visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) override;
        virtual antlrcpp::Any visitComp(ifccParser::CompContext *ctx);
        virtual antlrcpp::Any visitId(ifccParser::IdContext *ctx);
        virtual antlrcpp::Any visitParent(ifccParser::ParentContext *ctx);
        virtual antlrcpp::Any visitMoin(ifccParser::MoinContext *ctx);
        virtual antlrcpp::Any visitExpr(ifccParser::ExprContext *ctx);
        virtual antlrcpp::Any visitFunct(ifccParser::FunctContext *ctx);
        virtual antlrcpp::Any visitWhile_stmt(ifccParser::While_stmtContext *ctx) override;
        virtual antlrcpp::Any visitIf_stmt(ifccParser::If_stmtContext *ctx) override;
        
private:
        std::map<std::string, std::pair<int,int>> symbolTable;
        int stackOffset = 0;
        int tempCounter = 0;
        std::string newTemp() {
            return "temp_" + std::to_string(tempCounter++);
        }
};
