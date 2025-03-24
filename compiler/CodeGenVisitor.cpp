#include "CodeGenVisitor.h"
#include <iostream>

antlrcpp::Any CodeGenVisitor::visitProgs(ifccParser::ProgsContext *ctx) {
    std::cout << ".globl main\n";
    for(auto i : ctx->prog()){
        this->visit(i);
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) {
    std::string name = ctx->ID()->getText();
    std::cout << name<<":\n";
    // Save the base pointer && Set the base pointer to the current stack pointer
    std::cout << "    pushq %rbp\n";
    std::cout << "    movq %rsp, %rbp\n";

    for (auto stmt : ctx->stmt()) {
        this->visit(stmt);
    }

    std::cout << "    movq %rbp, %rsp\n";
    std::cout << "    popq %rbp\n";
    std::cout << "    ret\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) {
    std::vector<std::string> varNames;
    for (auto id : ctx->ID()) {
        varNames.push_back(id->getText());
    }

    for (const auto& varName : varNames) {
        symbolTable[varName].first = stackOffset;
        std::cout << "    subq $4, %rsp\n";
        if (ctx->expr()) {
            int localStackOffset = stackOffset;
            std::string constantText = ctx->expr()->getText();
            int value;

            // Check if it's a character constant
            if (constantText.front() == '\'' && constantText.back() == '\'' && constantText.size() == 3) {
                // Extract ASCII value of character
                value = static_cast<int>(constantText[1]);
                std::cout << "    movl $" << value << ", -" << localStackOffset << "(%rbp) \n";
            } 
            // Otherwise, if it's a number
            else if(ctx->expr()->CONST()) {
                value = std::stoi(constantText);
                std::cout << "    movl $" << value << ", -" << localStackOffset << "(%rbp) \n";
            }else{
                // Otherwise, if it's a expression
                this -> visit(ctx->expr());
                std::cout << "    movl %eax , -" <<localStackOffset << "(%rbp) \n";
            }
        }
        stackOffset+=4;
    }

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) {
    std::string varName = ctx->ID()->getText();

    if (symbolTable.find(varName) == symbolTable.end()) {
        throw std::runtime_error("Variable '" + varName + "' not declared");
    }

    int varOffset = symbolTable[varName].first;

    if (ctx->expr()->CONST()) {
        int valeur = std::stoi(ctx->expr()->CONST()->getText());
        std::cout << "    movl $" << valeur << ", -" << varOffset << "(%rbp)\n";
        symbolTable[varName].second = valeur;
    } else {
        this->visit(ctx->expr());
        std::cout << "    movl %eax, -" << varOffset << "(%rbp)\n";
    }
    return 0;
}


antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    if (ctx->expr()->CONST()) {
        std::string constantText = ctx->expr()->CONST()->getText();
        
        if (constantText.front() == '\'' && constantText.back() == '\'') {
            char charVal = constantText[1];
            int retval = static_cast<int>(charVal);
            std::cout << "    movl $" << retval << ", %eax\n";
        } else {
            int retval = std::stoi(constantText);
            std::cout << "    movl $" << retval << ", %eax\n";
        }
    }

    else if (ctx->expr()->ID()) {
        std::string varName = ctx->expr()->ID()->getText();

        if (symbolTable.find(varName) == symbolTable.end()) {
            throw std::runtime_error("Variable '" + varName + "' not declared");
        }
        int location = symbolTable[varName].first;

        std::cout << "    movl -" << location << "(%rbp), %eax\n";
    }
    else {
        this->visit(ctx->expr());
    }

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExpr(ifccParser::ExprContext *ctx) {
    if (ctx->COMP()) {
        this->visit(ctx->expr(0));
        std::string op = ctx->COMP()->getText();
        std::cout << "    pushq %rax\n";
        this->visit(ctx->expr(1));
        std::cout << "    movl %eax, %ebx\n";
        std::cout << "    popq %rax\n";
        std::cout << "    cmpl %ebx, %eax\n";
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
        std::cout << "    movzbl %al, %eax\n";
    } else if (ctx->OR()) {
        this->visit(ctx->expr(0));
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        this->visit(ctx->expr(1));
        int varStackOffset = symbolTable[temp].first;
        std::cout << "    or -" << varStackOffset << "(%rbp), %eax" << std::endl;
    } else if (ctx->XOR()){
        this->visit(ctx->expr(0));
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        this->visit(ctx->expr(1));    
        int varStackOffset = symbolTable[temp].first;
        std::cout << "    xor -" << varStackOffset << "(%rbp), %eax" << std::endl;
    } else if (ctx->AND()) {
        this->visit(ctx->expr(0));
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        this->visit(ctx->expr(1));
        int varStackOffset = symbolTable[temp].first;
        std::cout << "    and -" << varStackOffset << "(%rbp), %eax" << std::endl;
    } else if (ctx->OPA()) {
        this->visit(ctx->expr(0));
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        this->visit(ctx->expr(1));
        if (ctx->OPA()->getText() == "+") {
            int varStackOffset = symbolTable[temp].first;
            std::cout << "    addl -" << varStackOffset << "(%rbp), %eax" << std::endl;
        } else if (ctx->OPA()->getText() == "-") {            
            int varStackOffset = symbolTable[temp].first;
            std::cout << "    subl %eax, -" << varStackOffset << "(%rbp)" << std::endl;
            std::cout << "    movl  -" << varStackOffset << "(%rbp),"<< " %eax"<< std::endl;
        }

    } else if (ctx->OPM()) {
        this->visit(ctx->expr(0));
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        this->visit(ctx->expr(1));
        if (ctx->OPM()->getText() == "*") {
            int varStackOffset = symbolTable[temp].first;
            std::cout <<"    imull -" << varStackOffset << "(%rbp), %eax"<<std::endl; // %eax = %eax * temp
        } else if (ctx->OPM()->getText() == "/") {
            
            int varStackOffset = symbolTable[temp].first;
            std::cout <<"    movl %eax, %ecx" << std::endl;
            std::cout <<"    movl -" << varStackOffset << "(%rbp), %eax"<<std::endl;
            std::cout <<"    cltd" <<std::endl;
            std::cout <<"    idivl %ecx"<<std::endl;
        } else if (ctx->OPM()->getText() == "%") {
            int varStackOffset = symbolTable[temp].first;
            std::cout <<"    movl %eax, %ecx" << std::endl;
            std::cout <<"    movl -" << varStackOffset << "(%rbp), %eax"<<std::endl;
            std::cout <<"    cltd" <<std::endl;
            std::cout <<"    idivl %ecx"<<std::endl;
            std::cout << "   movl %edx, %eax" << std::endl;
        }
    }
    
    else if (ctx->UNARY()){
        std::string op = ctx->UNARY()->getText();
        visit(ctx -> expr(1));
        if (op == "!") {
            std::cout << "    cmpl $0, %eax\n"; // Compare %eax with 0
            std::cout << "    sete %al\n";      // Set %al to 1 if %eax == 0, else 0
            std::cout << "    movzbl %al, %eax\n"; // Zero-extend %al to %eax
        } else {
            throw std::runtime_error("Unsupported unary operator: " + op);
        }
    }
    else if (ctx->CONST()) {
        std::cout <<"    movl $" << ctx->CONST()->getText() << ", %eax" << std::endl;
    } else if (ctx->ID()) {
        int variableSymbol = symbolTable[ctx->ID()->getText()].first;
        std::cout<<"    movl -" << variableSymbol << "(%rbp), %eax"<<std::endl;
    } else if (ctx->expr(0)) {
        this->visit(ctx->expr(0));
    }

    return 0;
}

