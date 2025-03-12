#include "CodeGenVisitor.h"
#include <iostream>

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) {
    std::cout << ".globl main\n";
    std::cout << "main:\n";

    // Visit all statements in the program
    for (auto stmt : ctx->stmt()) {
        this->visit(stmt);
    }

    // Return from the function
    std::cout << "    ret\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) {
    // Allocate 4 bytes on the stack for the variable
    std::cout << "    subq $4, %rsp\n";

    // Visit the expression on the right-hand side of the assignment
    this->visit(ctx->expr());

    // Store the result in the variable (on the stack)
    std::string varName = ctx->ID()->getText();
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    // Load the value of the variable from the stack into %eax
    std::cout << "    movl (%rsp), %eax\n";

    // Deallocate the stack space
    std::cout << "    addq $4, %rsp\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExpr(ifccParser::ExprContext *ctx) {
    if (ctx->CONST()) {
        // If the expression is a constant, load it into %eax
        int retval = std::stoi(ctx->CONST()->getText());
        std::cout << "    movl $" << retval << ", (%rsp)\n";
    } else if (ctx->ID()) {
        // Load the value of the variable from the stack into %eax
        std::cout << "    movl (%rsp), %eax\n";
    }

    return 0;
}

