#include "CodeGenVisitor.h"
#include <iostream>

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) {
    std::cout << ".globl main\n";
    std::cout << "main:\n";
    std::cout << "    pushq %rbp\n"; // Save the base pointer
    std::cout << "    movq %rsp, %rbp\n"; // Set the base pointer to the current stack pointer

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
    stackOffset += 4;

    std::cout << "    subq $4, %rsp\n"; // Allocate space on the stack

    // Handle optional initialization
    if (ctx->expr()) {
        this->visit(ctx->expr());
        int varOffset = symbolTable[varName];
        std::cout << "    movl %eax, -" << varOffset << "(%rbp)\n";
    }

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) {
    std::string varName = ctx->ID()->getText();

    if (symbolTable.find(varName) == symbolTable.end()) {
        throw std::runtime_error("Variable '" + varName + "' not declared");
    }

    int varOffset = symbolTable[varName];

    // Evaluate the expression into %eax
    this->visit(ctx->expr());

    // Store result into the variable's location
    std::cout << "    movl %eax, -" << varOffset << "(%rbp)\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    // Evaluate the expression into %eax
    this->visit(ctx->expr());

    // Return value is already in %eax, no need to do anything else
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExpr(ifccParser::ExprContext *ctx) {
    if (ctx->CONST()) {
        int retval = std::stoi(ctx->CONST()->getText());
        std::cout << "    movl $" << retval << ", %eax\n";
    }
    else if (ctx->ID()) {
        std::string varName = ctx->ID()->getText();

        if (symbolTable.find(varName) == symbolTable.end()) {
            throw std::runtime_error("Variable '" + varName + "' not declared");
        }

        int location = symbolTable[varName];
        std::cout << "    movl -" << location << "(%rbp), %eax\n";
    }
    else if (ctx->op) {
        std::string op = ctx->op->getText();

        // Evaluate left operand
        this->visit(ctx->expr(0));
        std::cout << "    pushq %rax\n";

        // Evaluate right operand
        this->visit(ctx->expr(1));
        std::cout << "    movl %eax, %ebx\n"; // Right operand in ebx

        // Restore left operand
        std::cout << "    popq %rax\n";

        // Perform comparison: compare left (%eax) and right (%ebx)
        std::cout << "    cmpl %ebx, %eax\n";

        // Set result in %al (1 if true, 0 if false)
        if (op == "==") {
            std::cout << "    sete %al\n";
        }
        else if (op == "!=") {
            std::cout << "    setne %al\n";
        }
        else if (op == "<") {
            std::cout << "    setl %al\n";
        }
        else if (op == "<=") {
            std::cout << "    setle %al\n";
        }
        else if (op == ">") {
            std::cout << "    setg %al\n";
        }
        else if (op == ">=") {
            std::cout << "    setge %al\n";
        }
        else {
            throw std::runtime_error("Unsupported comparison operator: " + op);
        }

        // Zero-extend the result in %al to %eax (final result: 0 or 1)
        std::cout << "    movzbl %al, %eax\n";
    }
    else {
        throw std::runtime_error("Unknown expression type in visitExpr");
    }

    return 0;
}