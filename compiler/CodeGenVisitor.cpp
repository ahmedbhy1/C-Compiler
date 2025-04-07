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

    for (const auto& var : symbolTable) {
        if (usedVariables.find(var.first) == usedVariables.end() && var.first[0] != '#') {
            std::cout <<"#Variable '" + var.first + "' declared but never used\n";
        } 
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) {
    std::vector<std::string> varNames;

    for (auto i : ctx->equalexpr_stmt()){
        if (i->ID()){
            int localStackOffset = stackOffset;
            std::string varName = i->ID()->getText();
            if (symbolTable.find(varName) != symbolTable.end()) {
                throw std::runtime_error("Variable '" + varName + "' already declared");
            }
            symbolTable[varName].first = stackOffset;
            if (i->expr()){
                this -> visit(i->expr());
                std::cout << "    movl %eax , -" <<localStackOffset << "(%rbp) \n";
            }
            stackOffset+=4;
        }
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) {
    std::string varName = ctx->ID()->getText();

    if (symbolTable.find(varName) == symbolTable.end()) {
        throw std::runtime_error("Variable '" + varName + "' not declared");
    }
    int varOffset = symbolTable[varName].first;
    this->visit(ctx->expr());
    std::cout << "    movl %eax, -" << varOffset << "(%rbp)\n";
    return 0;
}


antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    this->visit(ctx->expr());
    return 0;
}


antlrcpp::Any CodeGenVisitor::visitComp(ifccParser::CompContext *ctx){
    this->visit(ctx->expr(0)); 
    usedVariables.insert(ctx->expr(0)->getText());          
    std::cout << "    movl %eax, %ecx\n";   

    this->visit(ctx->expr(1));
    usedVariables.insert(ctx->expr(1)->getText());             

    std::cout << "    cmpl %eax, %ecx\n"; 

    std::string op = ctx->COMP()->getText();
    if (op == "==") std::cout << "    sete %al\n";
    else if (op == "!=") std::cout << "    setne %al\n";
    else if (op == "<") std::cout << "    setl %al\n";
    else if (op == "<=") std::cout << "    setle %al\n";
    else if (op == ">") std::cout << "    setg %al\n";
    else if (op == ">=") std::cout << "    setge %al\n";
    else throw std::runtime_error("Unsupported comparison operator: " + op);

    std::cout << "    movzbl %al, %eax\n"; 
    return 0;
}



antlrcpp::Any CodeGenVisitor::visitUnary(ifccParser::UnaryContext *ctx){
    if (ctx->UNARY()){
        std::string op = ctx->UNARY()->getText();
        visit(ctx -> expr());
        if (op == "!") {
            std::cout << "    cmpl $0, %eax\n"; // Compare %eax with 0
            std::cout << "    sete %al\n";      // Set %al to 1 if %eax == 0, else 0
            std::cout << "    movzbl %al, %eax\n"; // Zero-extend %al to %eax
        } else {
            throw std::runtime_error("Unsupported unary operator: " + op);
        }
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitAnd(ifccParser::AndContext *ctx){
    if (ctx->AND()) {
        this->visit(ctx->expr(0));
        usedVariables.insert(ctx->expr(0)->getText());
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        this->visit(ctx->expr(1));
        usedVariables.insert(ctx->expr(1)->getText());
        int varStackOffset = symbolTable[temp].first;
        std::cout << "    and -" << varStackOffset << "(%rbp), %eax" << std::endl;
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitOr(ifccParser::OrContext *ctx){
    if (ctx->OR()) {
        this->visit(ctx->expr(0));
        usedVariables.insert(ctx->expr(0)->getText());
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        this->visit(ctx->expr(1));
        usedVariables.insert(ctx->expr(1)->getText());
        int varStackOffset = symbolTable[temp].first;
        std::cout << "    or -" << varStackOffset << "(%rbp), %eax" << std::endl;
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitXor(ifccParser::XorContext *ctx){
    if (ctx->XOR()){
        this->visit(ctx->expr(0));
        usedVariables.insert(ctx->expr(0)->getText());
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        this->visit(ctx->expr(1));    
        usedVariables.insert(ctx->expr(1)->getText());
        int varStackOffset = symbolTable[temp].first;
        std::cout << "    xor -" << varStackOffset << "(%rbp), %eax" << std::endl;
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitPlus(ifccParser::PlusContext *ctx){
    if (ctx->OPA()) {
        this->visit(ctx->expr(0));
        usedVariables.insert(ctx->expr(0)->getText());
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        this->visit(ctx->expr(1));
        usedVariables.insert(ctx->expr(1)->getText());
        if (ctx->OPA()->getText() == "+") {
            int varStackOffset = symbolTable[temp].first;
            std::cout << "    addl -" << varStackOffset << "(%rbp), %eax" << std::endl;
        } else if (ctx->OPA()->getText() == "-") {            
            int varStackOffset = symbolTable[temp].first;
            std::cout << "    subl %eax, -" << varStackOffset << "(%rbp)" << std::endl;
            std::cout << "    movl  -" << varStackOffset << "(%rbp),"<< " %eax"<< std::endl;
        }
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExpr(ifccParser::ExprContext *ctx){
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitMul(ifccParser::MulContext *ctx){
    if (ctx->OPM()) {
        this->visit(ctx->expr(0));
        usedVariables.insert(ctx->expr(0)->getText());
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        this->visit(ctx->expr(1));
        usedVariables.insert(ctx->expr(1)->getText());
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
    return 0;
}


antlrcpp::Any CodeGenVisitor::visitGetchar_expr(ifccParser::Getchar_exprContext *ctx) {
    std::cout << "    call getchar\n";
    return 0;
}


antlrcpp::Any CodeGenVisitor::visitConst(ifccParser::ConstContext *ctx){
    if (ctx->CONST()) {
        std::cout <<"    movl $" << ctx->CONST()->getText() << ", %eax" << std::endl;
    } 
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitPutchar_stmt(ifccParser::Putchar_stmtContext *ctx) {
    this->visit(ctx->expr());     
    std::cout << "    movl %eax, %edi\n";
    std::cout << "    call putchar\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitGetchar_stmt(ifccParser::Getchar_stmtContext *ctx) {
    std::string varName = ctx->ID()->getText();

    if (symbolTable.find(varName) == symbolTable.end()) {
        throw std::runtime_error("Variable '" + varName + "' not declared");
    }

    int varOffset = symbolTable[varName].first;

    std::cout << "    call getchar\n";                    // Result in %eax
    std::cout << "    movl %eax, -" << varOffset << "(%rbp)\n";  // Store result in variable
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitBreak_stmt(ifccParser::Break_stmtContext *ctx) {
    if (breakLabels.empty()) {
        throw std::runtime_error("`break` used outside of a loop or switch.");
    }
    std::cout << "    jmp " << breakLabels.top() << "\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitContinue_stmt(ifccParser::Continue_stmtContext *ctx) {
    if (continueLabels.empty()) {
        throw std::runtime_error("`continue` used outside of a loop.");
    }
    std::cout << "    jmp " << continueLabels.top() << "\n";
    return 0;
}


antlrcpp::Any CodeGenVisitor::visitId(ifccParser::IdContext *ctx){
    if (ctx->ID()) {
        int variableSymbol = symbolTable[ctx->ID()->getText()].first;
        std::cout<<"    movl -" << variableSymbol << "(%rbp), %eax"<<std::endl;
    }
    usedVariables.insert(ctx->ID()->getText());
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitParent(ifccParser::ParentContext *ctx){
    if (ctx->expr()) {
        this->visit(ctx->expr());
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitMoin(ifccParser::MoinContext *ctx){
    if (ctx->OPA() && ctx->OPA()->getText()=="-") {
        this->visit(ctx->expr());
        std::cout << "    negl %eax\n";
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitFunct(ifccParser::FunctContext *ctx){
    if (ctx-> ID() && ctx-> OPENPARENT() && ctx -> CLOSEPARENT()) {
        std::string functionName = ctx-> ID()->getText();
        std::cout << "    call "<<functionName << "\n";
    }
    return 0;
}

