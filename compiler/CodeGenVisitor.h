#pragma once

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"

#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>

#include "SymbolTable.h" // Include the symbol table you created

class CodeGenVisitor : public ifccBaseVisitor {
public:
    // Function overrides
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
    virtual antlrcpp::Any visitComp(ifccParser::CompContext *ctx) override;
    virtual antlrcpp::Any visitId(ifccParser::IdContext *ctx) override;
    virtual antlrcpp::Any visitParent(ifccParser::ParentContext *ctx) override;
    virtual antlrcpp::Any visitMoin(ifccParser::MoinContext *ctx) override;
    virtual antlrcpp::Any visitExpr(ifccParser::ExprContext *ctx) override;
    virtual antlrcpp::Any visitFunct(ifccParser::FunctContext *ctx) override;

private:
    SymbolTable symbols; 

    std::unordered_map<std::string, std::stack<int>> stackOffsets;

    int stackOffset = 0; 
    int tempCounter = 0; 

    std::string newTemp() {
        return "temp_" + std::to_string(tempCounter++);
    }
};
