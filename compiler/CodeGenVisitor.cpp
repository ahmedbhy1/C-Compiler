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
    variables.push(1);
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    if (ctx->expr()->CONST()) {
        // If the expression is a constant, load it into %eax
        int retval = std::stoi(ctx->expr()->CONST()->getText());
        std::cout << "    movl $" << retval << ", %eax\n";
    } else if (ctx->expr()->ID()) {
        std::cout << "    movl (%rsp), %eax\n";  
    }
    while (variables.size()){
        std::cout << "    addq $4, %rsp\n";
        variables.pop();
    }
    
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExpr(ifccParser::ExprContext *ctx) {
    if (ctx->CONST()) {
        // If the expression is a constant, load it into %eax
        int retval = std::stoi(ctx->CONST()->getText());
        std::cout << "    movl $" << retval << ", (%rsp)\n";
    } else if (ctx->ID()) {

    }

    return 0;
}

