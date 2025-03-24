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
        virtual antlrcpp::Any visitExpr(ifccParser::ExprContext *ctx) override;
        virtual antlrcpp::Any visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) override;
        
private:
        std::map<std::string, std::pair<int,int>> symbolTable;
        int stackOffset = 0;
        int tempCounter = 0;
        std::string newTemp() {
            return "temp_" + std::to_string(tempCounter++);
        }
};
