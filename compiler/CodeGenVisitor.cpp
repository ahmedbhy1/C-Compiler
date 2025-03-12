#include "CodeGenVisitor.h"
#include <iostream>

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) {
    std::cout << ".globl main\n";
    std::cout << "main:\n";

    std::cout <<"lets see the statemenets of the program : \n";
    // Visit all statements in the program
    for (auto stmt : ctx->stmt()) {
        //std::cout << stmt ;
        this->visit(stmt);
    }

    // Deallocate the stack space
    std::cout << "    addq $4, %rsp\n";

    // Return from the function
    std::cout << "    ret\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    // Visit the expression in the return statement
    this->visit(ctx->expr());

    // Move the result of the expression into %eax (x86 convention for return value)
    std::cout << "    movl %eax, %eax\n"; // Redundant, but ensures the value is in %eax

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExpr(ifccParser::ExprContext *ctx) {
    if (ctx->CONST()) {
        // If the expression is a constant, load it into %eax
        int retval = std::stoi(ctx->CONST()->getText());
        std::cout << "    movl $" << retval << ", %eax\n";
    } else if (ctx->ID()) {
        // Allocate 4 bytes on the stack for local variables
        std::cout << "    subq $4, %rsp\n";
        
    }

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) {
    // Visit the expression on the right-hand side of the assignment
    this->visit(ctx->expr());

    // Store the result in the variable (on the stack)
    std::string varName = ctx->ID()->getText();
    // Assume the variable is stored on the stack at an offset from %rsp
    std::cout << "    movl -4(%rsp), %eax\n"; // Load the value of x from the stack
    return 0;
}