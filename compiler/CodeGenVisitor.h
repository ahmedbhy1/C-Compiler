#pragma once 

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include <map>
#include <string>

class CodeGenVisitor : public ifccBaseVisitor {
public:
    virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
    virtual antlrcpp::Any visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) override;
    virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;
    virtual antlrcpp::Any visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) override;

    // Corrected: Visitors for bitwise operations
    virtual antlrcpp::Any visitBitwiseAndExpr(ifccParser::BitwiseAndExprContext *ctx) override;
    virtual antlrcpp::Any visitBitwiseOrExpr(ifccParser::BitwiseOrExprContext *ctx) override;
    virtual antlrcpp::Any visitBitwiseXorExpr(ifccParser::BitwiseXorExprContext *ctx) override;
    virtual antlrcpp::Any visitParenthesizedExpr(ifccParser::ParenthesizedExprContext *ctx) override;
    virtual antlrcpp::Any visitIdentifierExpr(ifccParser::IdentifierExprContext *ctx) override;
    virtual antlrcpp::Any visitConstantExpr(ifccParser::ConstantExprContext *ctx) override;

private:
    std::map<std::string, int> symbolTable;
    int stackOffset = 0;
};
