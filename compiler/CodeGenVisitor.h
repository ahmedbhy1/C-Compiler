#pragma once

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include <iostream>
#include <map>
#include <variant>
#include <string>
#include "SymbolTable.h"  // Include SymbolTable.h

class CodeGenVisitor : public ifccBaseVisitor {
public:
    virtual antlrcpp::Any visitProgs(ifccParser::ProgsContext *ctx);
    virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx);
    virtual antlrcpp::Any visitDecl_stmt(ifccParser::Decl_stmtContext *ctx);
    virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx);
    virtual antlrcpp::Any visitConst(ifccParser::ConstContext *ctx);
    virtual antlrcpp::Any visitUnary(ifccParser::UnaryContext *ctx);
    virtual antlrcpp::Any visitOr(ifccParser::OrContext *ctx);
    virtual antlrcpp::Any visitAnd(ifccParser::AndContext *ctx);
    virtual antlrcpp::Any visitXor(ifccParser::XorContext *ctx);
    virtual antlrcpp::Any visitPlus(ifccParser::PlusContext *ctx);
    virtual antlrcpp::Any visitMul(ifccParser::MulContext *ctx);
    virtual antlrcpp::Any visitAssign_stmt(ifccParser::Assign_stmtContext *ctx);
    virtual antlrcpp::Any visitComp(ifccParser::CompContext *ctx);
    virtual antlrcpp::Any visitId(ifccParser::IdContext *ctx);
    virtual antlrcpp::Any visitParent(ifccParser::ParentContext *ctx);
    virtual antlrcpp::Any visitMoin(ifccParser::MoinContext *ctx);
    virtual antlrcpp::Any visitFunct(ifccParser::FunctContext *ctx);

    // Add the visitBlock function
    virtual antlrcpp::Any visitBlock(ifccParser::BlockContext *ctx) override;

    // Declare the visitExpr function (no override)
    virtual antlrcpp::Any visitExpr(ifccParser::ExprContext *ctx);

private:
    SymbolTable symbols;  // Symbol table for variable scoping
    std::map<std::string, std::stack<int>> stackOffsets;  // Stack offsets to track variable positions
    int stackOffset = 0;
    int tempCounter = 0;

    std::string newTemp() {
        return "temp_" + std::to_string(tempCounter++);
    }
};
