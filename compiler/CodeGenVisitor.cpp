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
    //std::cout << "we have one declaration" << std::endl;
    std::string varName = ctx->ID()->getText();
    symbolTable[varName].first = stackOffset; // Add variable to symbol table
    stackOffset+=4;
    //std::cout<<"show the var name : "<< varName <<"\n" ;
    std::cout << "    subq $4, %rsp\n"; // Allocate space on the stack
    return 0;
}


antlrcpp::Any CodeGenVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) {
    // Allocate 4 bytes on the stack for the variable
    //std::cout << "we have one assignment" << std::endl;
    std::string varName = ctx->ID()->getText();
    // Visit the expression on the right-hand side of the assignment
    this->visit(ctx->expr());
    int valeur;
    int varOffset = symbolTable[varName].first;
    if (ctx->expr()->CONST()){
        valeur = std::stoi(ctx->expr()->CONST()->getText());    
        std::cout << "    movl $"<< valeur <<", -"<< varOffset << "(%rbp)\n";
    } else if (ctx->expr()->exprc()){
        valeur = (int)this->visit(ctx->expr()->exprc());
        std::cout << "    movl $"<< valeur <<", -"<< varOffset << "(%rbp)\n";
    }
    symbolTable[varName].second = valeur;
    

    //variables.push(1);
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    //std::cout << "we have one return" << std::endl;
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
        int location = symbolTable[varName].first;

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
    //std::cout << "we have one expression" << std::endl;
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExprc(ifccParser::ExprcContext *ctx) {
    // Evaluate the first mult_expr
    int left = this->visit(ctx->mult_expr());

    // If there's an addition/subtraction, evaluate the second mult_expr
    if (ctx->OPA()) {
        int right = this->visit(ctx->exprc());
        if (ctx->OPA()->getText() == "+") {
            return left + right;
        } else if (ctx->OPA()->getText() == "-") {
            return left - right;
        }
    }

    // If there's no addition/subtraction, return the result of the first mult_expr
    return left;
}

antlrcpp::Any CodeGenVisitor::visitMult_expr(ifccParser::Mult_exprContext *ctx) {
    // Evaluate the first primary_expr
    int left = this->visit(ctx->primary_expr());

    // If there's a multiplication/division, evaluate the second primary_expr
    if (ctx->OPM()) {
        int right = this->visit(ctx->mult_expr());
        if (ctx->OPM()->getText() == "*") {
            return left * right;
        } else if (ctx->OPM()->getText() == "/") {
            return left / right;
        }
    }

    // If there's no multiplication/division, return the result of the first primary_expr
    return left;
}

antlrcpp::Any CodeGenVisitor::visitPrimary_expr(ifccParser::Primary_exprContext *ctx) {
    if (ctx->CONST()) {
        // Return the constant value
        return std::stoi(ctx->CONST()->getText());
    } else if (ctx->ID()) {
        return symbolTable[ctx->ID()->getText()].second;
    } else if (ctx->exprc()) {
        // Handle grouped expressions
        return this->visit(ctx->exprc());
    }
    return 0;
}

