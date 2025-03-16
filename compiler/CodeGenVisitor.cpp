#include "CodeGenVisitor.h"
#include <iostream>

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) {
    std::cout << ".globl main\n";
    std::cout << "main:\n";
    std::cout << "    pushq %rbp\n"; // Save base pointer
    std::cout << "    movq %rsp, %rbp\n"; // Set base pointer

    visitChildren(ctx); // Visit all statements

    std::cout << "    movq %rbp, %rsp\n"; // Restore stack pointer
    std::cout << "    popq %rbp\n"; // Restore base pointer
    std::cout << "    ret\n"; // Return
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) {
    std::string varName = ctx->ID()->getText();
    stackOffset -= 4;  // Allocate 4 bytes for the variable
    symbolTable[varName] = stackOffset;

    std::cout << "    subq $4, %rsp\n";  // Adjust stack pointer

    if (ctx->expr()) {
        visit(ctx->expr());
        std::cout << "    movl %eax, " << stackOffset << "(%rbp)\n";
    }
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) {
    std::string varName = ctx->ID()->getText();
    visit(ctx->expr());
    if (symbolTable.find(varName) != symbolTable.end()) {
        std::cout << "    movl %eax, " << symbolTable[varName] << "(%rbp)\n";
    }
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    visit(ctx->expr());
    std::cout << "    movl %eax, %eax\n";  // Ensure return value in %eax
    std::cout << "    movq %rbp, %rsp\n";  // Restore stack pointer
    std::cout << "    popq %rbp\n";        // Restore base pointer
    std::cout << "    ret\n";              // Return
    return nullptr;
}

// ===========================
// Bitwise Operations Visitors
// ===========================

antlrcpp::Any CodeGenVisitor::visitBitwiseAndExpr(ifccParser::BitwiseAndExprContext *ctx) {
    visit(ctx->expr(0));
    std::cout << "    pushq %rax\n";   // Save left operand
    visit(ctx->expr(1));
    std::cout << "    popq %rcx\n";    // Load left operand into %rcx
    std::cout << "    andl %ecx, %eax\n";  // Perform bitwise AND
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitBitwiseOrExpr(ifccParser::BitwiseOrExprContext *ctx) {
    visit(ctx->expr(0));
    std::cout << "    pushq %rax\n";
    visit(ctx->expr(1));
    std::cout << "    popq %rcx\n";
    std::cout << "    orl %ecx, %eax\n";  // Perform bitwise OR
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitBitwiseXorExpr(ifccParser::BitwiseXorExprContext *ctx) {
    visit(ctx->expr(0));
    std::cout << "    pushq %rax\n";
    visit(ctx->expr(1));
    std::cout << "    popq %rcx\n";
    std::cout << "    xorl %ecx, %eax\n";  // Perform bitwise XOR
    return nullptr;
}

// ===========================
// Other Expression Visitors
// ===========================

antlrcpp::Any CodeGenVisitor::visitParenthesizedExpr(ifccParser::ParenthesizedExprContext *ctx) {
    return visit(ctx->expr());
}

antlrcpp::Any CodeGenVisitor::visitIdentifierExpr(ifccParser::IdentifierExprContext *ctx) {
    std::string varName = ctx->getText();
    if (symbolTable.find(varName) != symbolTable.end()) {
        std::cout << "    movl " << symbolTable[varName] << "(%rbp), %eax\n";
    }
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitConstantExpr(ifccParser::ConstantExprContext *ctx) {
    int value = std::stoi(ctx->getText());
    std::cout << "    movl $" << value << ", %eax\n";
    return value;
}
