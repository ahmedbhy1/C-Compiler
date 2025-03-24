#include "CodeGenVisitor.h"
#include <iostream>

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) {
    std::cout << ".globl main\n";
    std::cout << "main:\n";
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
    this->visit(ctx->exprc());
    if (ctx->COMP()) {
        std::string op = ctx->COMP()->getText();

        std::cout << "    pushq %rax\n";

        this->visit(ctx->expr());

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

antlrcpp::Any CodeGenVisitor::visitExprc(ifccParser::ExprcContext *ctx) {
    this->visit(ctx->xor_expr());

    if (ctx->OR()) {
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        this->visit(ctx->exprc());
        int varStackOffset = symbolTable[temp].first;
        std::cout << "    or -" << varStackOffset << "(%rbp), %eax" << std::endl;
    }
    return nullptr;
}


antlrcpp::Any CodeGenVisitor::visitXor_expr(ifccParser::Xor_exprContext *ctx) {
    this->visit(ctx->and_expr());

    if (ctx->XOR()) {
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        this->visit(ctx->xor_expr());    
        int varStackOffset = symbolTable[temp].first;
        std::cout << "    xor -" << varStackOffset << "(%rbp), %eax" << std::endl;
        
    }

    return nullptr;
}


antlrcpp::Any CodeGenVisitor::visitAnd_expr(ifccParser::And_exprContext *ctx) {
    this->visit(ctx->add_expr());

    if (ctx->AND()) {
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        this->visit(ctx->and_expr());
        int varStackOffset = symbolTable[temp].first;
        std::cout << "    and -" << varStackOffset << "(%rbp), %eax" << std::endl;
    }

    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitAdd_expr(ifccParser::Add_exprContext *ctx) {
    this->visit(ctx->mult_expr());

    if (ctx->OPA()) {
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        this->visit(ctx->add_expr());

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
    
    if (!ctx->UNARY() && !ctx->OPA()){
        this->visit(ctx->primary_expr());
    }else if (ctx->UNARY()) {
        std::string op = ctx->UNARY()->getText();
        visit(ctx -> unary_expr());
        if (op == "!") {
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
            std::cout << "    negl %eax\n";
        }
    }
    
    return nullptr;
}



antlrcpp::Any CodeGenVisitor::visitMult_expr(ifccParser::Mult_exprContext *ctx) {
    this->visit(ctx->unary_expr());

    if (ctx->OPM()) {
        std::string temp = newTemp();
        symbolTable[temp].first = stackOffset;
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset+=4;
        
        this->visit(ctx->mult_expr());

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

    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitPrimary_expr(ifccParser::Primary_exprContext *ctx) {
    if (ctx->CONST()) {
        std::cout <<"    movl $" << ctx->CONST()->getText() << ", %eax" << std::endl;
    } else if (ctx->ID()) {
        int variableSymbol = symbolTable[ctx->ID()->getText()].first;
        std::cout<<"    movl -" << variableSymbol << "(%rbp), %eax"<<std::endl;

    } else if (ctx->expr()) {
        this->visit(ctx->expr());
    }

    return nullptr;
}


antlrcpp::Any CodeGenVisitor::visitStmt(ifccParser::StmtContext *ctx) {
    if (ctx->decl_stmt()) {
        this->visit(ctx->decl_stmt());  // Traite la déclaration
    } else if (ctx->assign_stmt()) {
        this->visit(ctx->assign_stmt());  // Traite l'assignation
    } else if (ctx->return_stmt()) {
        this->visit(ctx->return_stmt());  // Traite le return
    } else if (ctx->if_stmt()) {
        this->visit(ctx->if_stmt());  // Traite l'instruction if
    } else if (ctx->while_stmt()) {
        this->visit(ctx->while_stmt());  // Traite l'instruction while
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
