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
    symbolTable[varName].first = stackOffset; // Add variable to symbol table
    int localStackOffset = stackOffset;
    std::cout << "    subq $4, %rsp\n"; // Allocate space on the stack

    // Handle optional initialization
    if (ctx->expr()) {
        std::string constantText = ctx->expr()->getText();
        int value;

        // Check if it's a character constant
        if (constantText.front() == '\'' && constantText.back() == '\'' && constantText.size() == 3) {
            value = static_cast<int>(constantText[1]);  // Extract ASCII value of character
            std::cout << "    movl $" << value << ", -" << localStackOffset << "(%rbp) \n";
        }
        // Otherwise, assume it's a number
        else if(ctx->expr()->CONST()){
            std::cout << "constantText = "<< constantText <<std::endl;
            value = std::stoi(constantText);
            std::cout << "    movl $" << value << ", -" << localStackOffset << "(%rbp) \n";
        }
        else {
            this->visit(ctx->expr());
            std::cout << "    movl %eax, -"<< localStackOffset << "(%rbp) \n";
        }
    }
    stackOffset+=4;

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
    } else {
        // Generate the code for the expression and store in %eax
        this->visit(ctx->expr());
        std::cout << "    movl %eax, -" << varOffset << "(%rbp)\n";
    }
    return 0;
}


antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    if (ctx->expr()->CONST()) {
        std::string constantText = ctx->expr()->CONST()->getText();
        
        // Check if the constant is a character (e.g., 'A')
        if (constantText.front() == '\'' && constantText.back() == '\'') {
            // Extract the character and convert it to its ASCII value
            char charVal = constantText[1];  // Skip the single quotes
            int retval = static_cast<int>(charVal);
            std::cout << "    movl $" << retval << ", %eax\n";
        } else {
            // Otherwise, it's a numeric constant
            int retval = std::stoi(constantText);
            std::cout << "    movl $" << retval << ", %eax\n";
        }
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
    // Visit the left expression (exprc)
    this->visit(ctx->exprc());
    // If there is an operator, handle the comparison
    if (ctx->COMP()) {
        //std::cout<< "is there an operator ?"<<std::endl;
        std::string op = ctx->COMP()->getText();

        // Push the result of the left expression onto the stack
        std::cout << "    pushq %rax\n";

        // Visit the right expression
        this->visit(ctx->expr());

        // Move the result of the right expression to %ebx
        std::cout << "    movl %eax, %ebx\n";

        // Pop the left expression result from the stack into %eax
        std::cout << "    popq %rax\n";

        // Compare the two values
        std::cout << "    cmpl %ebx, %eax\n";

        // Set the result in %al based on the comparison
        if (op == "==") {
            std::cout << "    sete %al\n";
        } else if (op == "!=") {
            std::cout << "    setne %al\n";
        } else if (op == "<") {
            std::cout << "    setl %al\n";
        } else if (op == "<=") {
            std::cout << "    setle %al\n";
        } else if (op == ">") {
            std::cout << "    setg %al\n";
        } else if (op == ">=") {
            std::cout << "    setge %al\n";
        } else {
            throw std::runtime_error("Unsupported comparison operator: " + op);
        }
        // Zero-extend the result in %al to %eax
        std::cout << "    movzbl %al, %eax\n";
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExprc(ifccParser::ExprcContext *ctx) {
    // Visit the left mult_expr and compute its value in %eax
    this->visit(ctx->xor_expr());

    // If there's an addition/subtraction, handle it
    if (ctx->OR()) {
        // Save the left result to a temporary variable on the stack
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset; // Add variable to symbol table
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        // Visit the right exprc and compute its value in %eax
        this->visit(ctx->exprc());

        // Perform the operation
        
        int varStackOffset = symbolTable[temp].first;
        std::cout << "    or -" << varStackOffset << "(%rbp), %eax" << std::endl;
    }
    return nullptr;
}


antlrcpp::Any CodeGenVisitor::visitXor_expr(ifccParser::Xor_exprContext *ctx) {
    // Visit the left mult_expr and compute its value in %eax
    this->visit(ctx->and_expr());

    // If there's an addition/subtraction, handle it
    if (ctx->XOR()) {
        // Save the left result to a temporary variable on the stack
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset; // Add variable to symbol table
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        // Visit the right exprc and compute its value in %eax
        this->visit(ctx->xor_expr());

        // Perform the operation
        
        int varStackOffset = symbolTable[temp].first;
        std::cout << "    xor -" << varStackOffset << "(%rbp), %eax" << std::endl;
        
    }

    return nullptr;
}


antlrcpp::Any CodeGenVisitor::visitAnd_expr(ifccParser::And_exprContext *ctx) {
    // Visit the left mult_expr and compute its value in %eax
    this->visit(ctx->add_expr());

    // If there's an addition/subtraction, handle it
    if (ctx->AND()) {
        // Save the left result to a temporary variable on the stack
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset; // Add variable to symbol table
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        // Visit the right exprc and compute its value in %eax
        this->visit(ctx->and_expr());
        // Perform the operation
        int varStackOffset = symbolTable[temp].first;
        std::cout << "    and -" << varStackOffset << "(%rbp), %eax" << std::endl;
    }

    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitAdd_expr(ifccParser::Add_exprContext *ctx) {
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
        this->visit(ctx->add_expr());

        // Perform the operation
        if (ctx->OPA()->getText() == "+") {
            int varStackOffset = symbolTable[temp].first;
            std::cout << "    addl -" << varStackOffset << "(%rbp), %eax" << std::endl;
        } else if (ctx->OPA()->getText() == "-") {            
            int varStackOffset = symbolTable[temp].first;
            std::cout << "    subl %eax, -" << varStackOffset << "(%rbp)" << std::endl;
            std::cout << "    movl  -" << varStackOffset << "(%rbp),"<< " %eax"<< std::endl;
        }
    }

    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitUnary_expr(ifccParser::Unary_exprContext *ctx) {
    // Visit the operand (primary_expr or another unary_expr)

    if (!ctx->UNARY() && !ctx->OPA()){
        this->visit(ctx->primary_expr());
    }else if (ctx->UNARY()) {
        std::string op = ctx->UNARY()->getText();
        visit(ctx -> unary_expr());
        if (op == "!") {
            // Logical NOT: 0 becomes 1, non-zero becomes 0
            std::cout << "    cmpl $0, %eax\n"; // Compare %eax with 0
            std::cout << "    sete %al\n";      // Set %al to 1 if %eax == 0, else 0
            std::cout << "    movzbl %al, %eax\n"; // Zero-extend %al to %eax
        } else {
            throw std::runtime_error("Unsupported unary operator: " + op);
        }
    }else if(ctx ->OPA()){
        std::string op = ctx->OPA()->getText();
        visit(ctx -> unary_expr());
        if (op == "-") {
            // Negate the value in %eax
            std::cout << "    negl %eax\n";
        }
    }
    
    // The result is in %eax
    return nullptr;
}



antlrcpp::Any CodeGenVisitor::visitMult_expr(ifccParser::Mult_exprContext *ctx) {
    // Visit the left primary_expr and compute its value in %eax
    this->visit(ctx->unary_expr());

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
            std::cout <<"    movl %eax, %ecx" << std::endl;
            std::cout <<"    movl -" << varStackOffset << "(%rbp), %eax"<<std::endl;
            std::cout <<"    cltd" <<std::endl;                        // Sign-extend %eax into %edx:%eax
            std::cout <<"    idivl %ecx"<<std::endl;                   //    = %eax / %ecx
        } else if (ctx->OPM()->getText() == "%") {
            int varStackOffset = symbolTable[temp].first;
            std::cout <<"    movl %eax, %ecx" << std::endl;  // ecx = 3 //eax = 5
            std::cout <<"    movl -" << varStackOffset << "(%rbp), %eax"<<std::endl;
            std::cout <<"    cltd" <<std::endl;                        // Sign-extend %eax into %edx:%eax
            std::cout <<"    idivl %ecx"<<std::endl;                               // Divide %edx:%eax by %ecx
            std::cout << "   movl %edx, %eax" << std::endl;                            // Store remainder in %eax (correct result)
        }
    }

    // The result is already in %eax
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitPrimary_expr(ifccParser::Primary_exprContext *ctx) {
    //std::cout<<"we are Primary"<<std::endl;
    if (ctx->CONST()) {
        // Load the constant into %eax
        std::cout <<"    movl $" << ctx->CONST()->getText() << ", %eax" << std::endl;
    } else if (ctx->ID()) {
        // Load the variable's value into %eax
        int variableSymbol = symbolTable[ctx->ID()->getText()].first;
        std::cout<<"    movl -" << variableSymbol << "(%rbp), %eax"<<std::endl;

    } else if (ctx->expr()) {
        // Handle grouped expressions
        this->visit(ctx->expr());
    }

    // The result is already in %eax
    return nullptr;
}
