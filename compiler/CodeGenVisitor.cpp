#include "CodeGenVisitor.h"
#include <iostream>

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) {
    std::cout << ".globl main\n";
    std::cout << "main:\n";
    std::cout << "    pushq %rbp\n";// Save the base pointer
    std::cout << "    movq %rsp, %rbp\n";// Set the base pointer to the current stack pointer"
    
    // Visit all statements in the program
    for (auto stmt : ctx->stmt()) {
        this->visit(stmt);
    }

    std::cout << "    movq %rbp, %rsp\n";
    std::cout << "    popq %rbp\n";
    std::cout << "    ret\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) {
    std::string varName = ctx->ID()->getText();
    symbolTable[varName] = stackOffset; // Add variable to symbol table
    stackOffset+=4;
    //std::cout<<"show the var name : "<< varName <<"\n" ;
    std::cout << "    subq $4, %rsp\n"; // Allocate space on the stack
    return 0;
}


antlrcpp::Any CodeGenVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) {
    // Allocate 4 bytes on the stack for the variable
    std::string varName = ctx->ID()->getText();
    // Visit the expression on the right-hand side of the assignment
    this->visit(ctx->expr());
    std::string valeur = ctx->expr()->CONST()->getText();
    // Store the result in the variable (on the stack)
    int varOffset = symbolTable[varName];
    std::cout << "    movl $"<< valeur <<", -"<< varOffset << "(%rbp)\n";

    //variables.push(1);
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    // Check if the expression is a constant
    if (ctx->expr()->CONST()) {
        // If the expression is a constant, load it into %eax
        int retval = std::stoi(ctx->expr()->CONST()->getText());
        std::cout << "    movl $" << retval << ", %eax\n";
    }
    // Check if the expression is a variable
    else if (ctx->expr()->ID()) {
        std::string varName = ctx->expr()->ID()->getText();

        // Look up the variable in the symbol table
        if (symbolTable.find(varName) == symbolTable.end()) {
            throw std::runtime_error("Variable '" + varName + "' not declared");
        }

        // Get the variable's stack offset
        int location = symbolTable[varName];

        // Load the variable's value into %eax
        std::cout << "    movl -" << location << "(%rbp), %eax\n";
    }
    // Handle other cases (e.g., complex expressions)
    else {
        // Visit the expression to evaluate it (result will be in %eax)
        this->visit(ctx->expr());
    }

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExpr(ifccParser::ExprContext *ctx) {
    if (ctx->CONST()) {
        // If the expression is a constant, load it into %eax
        int retval = std::stoi(ctx->CONST()->getText());
        //std::cout << "    movl $" << retval << ", (%rsp)\n";
    } else if (ctx->ID()) {
    }

    return 0;
}

