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

    for (auto i : ctx->equalexpr_stmt()){
        if (i->ID()){
            int localStackOffset = stackOffset;
            std::string varName = i->ID()->getText();
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
    }
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
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        this->visit(ctx->expr(1));
        int varStackOffset = symbolTable[temp].first;
        std::cout << "    and -" << varStackOffset << "(%rbp), %eax" << std::endl;
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitOr(ifccParser::OrContext *ctx){
    if (ctx->OR()) {
        this->visit(ctx->expr(0));
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        this->visit(ctx->expr(1));
        int varStackOffset = symbolTable[temp].first;
        std::cout << "    or -" << varStackOffset << "(%rbp), %eax" << std::endl;
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitXor(ifccParser::XorContext *ctx){
    if (ctx->XOR()){
        this->visit(ctx->expr(0));
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        this->visit(ctx->expr(1));    
        int varStackOffset = symbolTable[temp].first;
        std::cout << "    xor -" << varStackOffset << "(%rbp), %eax" << std::endl;
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitPlus(ifccParser::PlusContext *ctx){
    if (ctx->OPA()) {
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
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExpr(ifccParser::ExprContext *ctx){
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitMul(ifccParser::MulContext *ctx){
    if (ctx->OPM()) {
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
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitConst(ifccParser::ConstContext *ctx){
    if (ctx->CONST()) {
        std::cout <<"    movl $" << ctx->CONST()->getText() << ", %eax" << std::endl;
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitId(ifccParser::IdContext *ctx){
    if (ctx->ID()) {
        int variableSymbol = symbolTable[ctx->ID()->getText()].first;
        std::cout<<"    movl -" << variableSymbol << "(%rbp), %eax"<<std::endl;
    }
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


antlrcpp::Any CodeGenVisitor::visitIf_stmt(ifccParser::If_stmtContext *ctx) {
    // Créer des labels pour les différentes sections du if
    std::string label_if_true = "if_true_" + std::to_string(tempCounter++);
    std::string label_if_end = "if_end_" + std::to_string(tempCounter++);
    std::string label_else = "if_else_" + std::to_string(tempCounter++);

    // Évaluer l'expression du if
    this->visit(ctx->expr());  // Visiter l'expression conditionnelle du if

    // Comparer la condition et sauter à l'else si elle est fausse
    std::cout << "    cmp $0, %eax\n";  // Si l'expression est fausse (0)
    std::cout << "    je " << label_else << "\n";  // Sauter à l'else si condition fausse

    // Si la condition est vraie, exécuter le bloc du if
    std::cout << label_if_true << ":\n";
    for (auto stmt : ctx->stmt()) {
        this->visit(stmt);  // Visiter chaque instruction du corps du if
    }

    // Sauter à la fin du if pour éviter l'exécution du else
    std::cout << "    jmp " << label_if_end << "\n";

    // Bloc else, exécuté si la condition du if est fausse
    std::cout << label_else << ":\n";

    // Vérifier si le bloc else existe
    if (ctx->if_else_stmt()) {  // Si le bloc else existe
        for (auto stmt : ctx->if_else_stmt()->stmt()) {
            this->visit(stmt);  // Visiter les instructions dans le bloc else
        }
    }

    // Fin du if
    std::cout << label_if_end << ":\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitWhile_stmt(ifccParser::While_stmtContext *ctx) {
    //std::cout<< "we are in while"<<std::endl;
    std::string label_while_start = "while_start_" + std::to_string(tempCounter++);
    std::string label_while_end = "while_end_" + std::to_string(tempCounter++);

    // Label de début de la boucle while
    std::cout << label_while_start << ":\n";

    // Évaluer la condition de la boucle
    this->visit(ctx->expr());

    // Comparer la condition de la boucle
    std::cout << "    cmp $0, %eax\n";  // Si l'expression est fausse (0)
    std::cout << "    je " << label_while_end << "\n";  // Sortir de la boucle si la condition est fausse

    // Exécuter les instructions de la boucle while
    for (auto stmt : ctx->stmt()) {
        this->visit(stmt);
    }

    // Revenir au début de la boucle
    std::cout << "    jmp " << label_while_start << "\n";

    // Label de fin de la boucle while
    std::cout << label_while_end << ":\n";
    return 0;
}