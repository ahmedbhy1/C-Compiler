#pragma once


#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include <iostream>
#include <map>
#include <variant>
#include <string>
#include "IR.h"

class  CodeGenVisitor : public ifccBaseVisitor {
	public:
        virtual antlrcpp::Any visitProgs(ifccParser::ProgsContext *ctx) override;
        virtual antlrcpp::Any visitDef_func(ifccParser::Def_funcContext *ctx) override;
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
        virtual antlrcpp::Any visitPutchar_stmt(ifccParser::Putchar_stmtContext *ctx) override;
        virtual antlrcpp::Any visitGetchar_stmt(ifccParser::Getchar_stmtContext *ctx) override;
        virtual antlrcpp::Any visitBreak_stmt(ifccParser::Break_stmtContext *ctx) override;
        virtual antlrcpp::Any visitContinue_stmt(ifccParser::Continue_stmtContext *ctx) override;
        virtual antlrcpp::Any visitComp(ifccParser::CompContext *ctx);
        virtual antlrcpp::Any visitId(ifccParser::IdContext *ctx);
        virtual antlrcpp::Any visitParent(ifccParser::ParentContext *ctx);
        virtual antlrcpp::Any visitMoin(ifccParser::MoinContext *ctx);
        virtual antlrcpp::Any visitExpr(ifccParser::ExprContext *ctx);
        virtual antlrcpp::Any visitFunct(ifccParser::FunctContext *ctx);
        virtual antlrcpp::Any visitGetchar_expr(ifccParser::Getchar_exprContext *ctx);
        virtual antlrcpp::Any visitIf_stmt(ifccParser::If_stmtContext *ctx);
        virtual antlrcpp::Any visitWhile_stmt(ifccParser::While_stmtContext *ctx);
        
        
private:
        CFG* currentCFG = nullptr;
        BasicBlock* currentBB = nullptr;
        std::map<std::string, std::pair<int,int>> symbolTable;
        int stackOffset = 0;
        int tempCounter = 0;
        std::string newTemp() {
                return currentCFG->create_new_tempvar(INT32_T);
        }
        std::stack<std::string> breakLabels; 
        std::stack<std::string> continueLabels;

};
