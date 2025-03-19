#include "CodeGenVisitor.h"
#include <iostream>

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) {
    std::cout << ".globl main\n";
    std::cout << "main:\n";
    std::cout << "    pushq %rbp\n"; // Save the base pointer
    std::cout << "    movq %rsp, %rbp\n"; // Set the base pointer to the current stack pointer

    // Visit all statements in the program
    for (auto stmt : ctx->stmt()) {
        //std::cout << "we are getting from visitProg"<< stmt->getText() << std::endl;
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

    // Handle optional initialization
    if (ctx->expr()) {
        this->visit(ctx->expr());
        int varOffset = symbolTable[varName].first;
        std::cout << "    movl %eax, -" << varOffset << "(%rbp)\n";
    }

    return 0;
}



antlrcpp::Any CodeGenVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) {
    std::string varName = ctx->ID()->getText();

    // Ensure variable exists
    if (symbolTable.find(varName) == symbolTable.end()) {
        throw std::runtime_error("Variable '" + varName + "' not declared");
    }

    int varOffset = symbolTable[varName].first;

    if (ctx->expr()->CONST()) {
        int valeur = std::stoi(ctx->expr()->CONST()->getText());
        std::cout << "    movl $" << valeur << ", -" << varOffset << "(%rbp)\n";
        symbolTable[varName].second = valeur;
    } else if (ctx->expr()->exprc()) {
        this->visit(ctx->expr()->exprc());
        std::cout << "    movl %eax, -" << varOffset << "(%rbp)\n";
        /*
            int valeur = (int)this->visit(ctx->expr()->exprc()); // Compute the value for internal tracking
            std::cout << "    movl $" << valeur << ", -" << varOffset << "(%rbp)\n";
            symbolTable[varName].second = valeur;
        */
    } else {
        // Generate the code for the expression and store in %eax
        this->visit(ctx->expr());
        std::cout << "    movl %eax, -" << varOffset << "(%rbp)\n";
    }

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

        int location = symbolTable[varName].first;
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
    
    //std::cout << "we have one expression" << std::endl;
    return 0;
}
/*
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
*/
antlrcpp::Any CodeGenVisitor::visitExprc(ifccParser::ExprcContext *ctx) {
    // Visit the left mult_expr and compute its value in %eax
    this->visit(ctx->mult_expr());

    // If there's an addition/subtraction, handle it
    if (ctx->OPA()) {
        // Save the left result to a temporary variable on the stack
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset; // Add variable to symbol table
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        // Visit the right exprc and compute its value in %eax
        this->visit(ctx->exprc());

        // Perform the operation
        if (ctx->OPA()->getText() == "+") {
            int varStackOffset = symbolTable[temp].first;
            std::cout << "    addl -" << varStackOffset << "(%rbp), %eax" << std::endl;
        } else if (ctx->OPA()->getText() == "-") {            
            int varStackOffset = symbolTable[temp].first;
            std::cout << "    subl -" << varStackOffset << "(%rbp), %eax" << std::endl;
        }
    }

    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitMult_expr(ifccParser::Mult_exprContext *ctx) {
    // Visit the left primary_expr and compute its value in %eax
    this->visit(ctx->primary_expr());

    // If there's a multiplication/division, handle it
    if (ctx->OPM()) {
        // Save the left result to a temporary variable on the stack
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset; // Add variable to symbol table
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        
        // Visit the right mult_expr and compute its value in %eax
        this->visit(ctx->mult_expr());

        // Perform the operation
        if (ctx->OPM()->getText() == "*") {
            int varStackOffset = symbolTable[temp].first;
            std::cout <<"    imull -" << varStackOffset << "(%rbp), %eax"<<std::endl; // %eax = %eax * temp
        } else if (ctx->OPM()->getText() == "/") {
            
            int varStackOffset = symbolTable[temp].first;
            std::cout <<"    movl -" << varStackOffset << "(%rbp), %ecx"<<std::endl;
            std::cout <<"    cltd" <<std::endl;                        // Sign-extend %eax into %edx:%eax
            std::cout <<"    idivl %ecx"<<std::endl;                   // %eax = %eax / %ecx
        }
    }

    // The result is already in %eax
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitPrimary_expr(ifccParser::Primary_exprContext *ctx) {
    if (ctx->CONST()) {
        // Load the constant into %eax
        std::cout <<"    movl $" << ctx->CONST()->getText() << ", %eax" << std::endl;
    } else if (ctx->ID()) {
        // Load the variable's value into %eax
        int variableSymbol = symbolTable[ctx->ID()->getText()].first;
        std::cout<<"    movl -" << variableSymbol << "(%rbp), %eax"<<std::endl;

    } else if (ctx->exprc()) {
        // Handle grouped expressions
        this->visit(ctx->exprc());
    }

    // The result is already in %eax
    return nullptr;
}
/*
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
*/
/*
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
*/