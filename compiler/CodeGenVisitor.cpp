#include "CodeGenVisitor.h"
#include <iostream>

antlrcpp::Any CodeGenVisitor::visitProgs(ifccParser::ProgsContext *ctx) {
    std::cout << ".globl main\n";
    for (auto i : ctx->prog()) {
        this->visit(i);
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) {
    std::string name = ctx->ID()->getText();
    std::cout << name << ":\n";
    std::cout << "    pushq %rbp\n";
    std::cout << "    movq %rsp, %rbp\n";

    symbols.enterScope();  // Enter a new scope for the program

    for (auto stmt : ctx->stmt()) {
        this->visit(stmt);
    }

    symbols.exitScope();  // Exit the current scope for the program

    std::cout << "    movq %rbp, %rsp\n";
    std::cout << "    popq %rbp\n";
    std::cout << "    ret\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) {
    std::vector<std::string> varNames;

    for (auto i : ctx->equalexpr_stmt()) {
        if (i->ID()) {
            int localStackOffset = stackOffset;
            std::string varName = i->ID()->getText();
            symbols.declare(varName, "int");  // Declare variable in the symbol table
            stackOffsets[varName].push(stackOffset);  // Track stack offset for variable
            stackOffset += 4;  // Move the stack offset for an int variable

            if (i->expr()) {
                this->visit(i->expr());
                std::cout << "    movl %eax , -" << localStackOffset << "(%rbp) \n";
            }
        }
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) {
    std::string varName = ctx->ID()->getText();

    // Check if the variable is declared in the symbol table
    if (symbols.lookup(varName).empty()) {
        throw std::runtime_error("Variable '" + varName + "' not declared");
    }

    // Get the stack offset for the variable
    int varOffset = stackOffsets[varName].top();
    this->visit(ctx->expr());
    std::cout << "    movl %eax, -" << varOffset << "(%rbp)\n";  // Store the value in the correct offset
    return 0;
}

// antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
//     this->visit(ctx->expr());
//     std::cout << "    ret\n";  // Return from function
//     return 0;
// }

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    this->visit(ctx->expr());

    std::cout << "    movq %rbp, %rsp\n";
    std::cout << "    popq %rbp\n";
    std::cout << "    ret\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitBlock(ifccParser::BlockContext *ctx) {
    symbols.enterScope();
    std::vector<std::string> varsDeclaredHere;

    for (auto stmt : ctx->stmt()) {
        if (auto decl = dynamic_cast<ifccParser::Decl_stmtContext*>(stmt)) {
            for (auto eq : decl->equalexpr_stmt()) {
                std::string varName = eq->ID()->getText();
                varsDeclaredHere.push_back(varName);
            }
        }
        this->visit(stmt);
    }

    for (const auto& var : varsDeclaredHere) {
        stackOffsets[var].pop();
        symbols.removeStackOffset(var);
    }

    symbols.exitScope();
    return 0;
}


antlrcpp::Any CodeGenVisitor::visitComp(ifccParser::CompContext *ctx) {
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

antlrcpp::Any CodeGenVisitor::visitUnary(ifccParser::UnaryContext *ctx) {
    if (ctx->UNARY()) {
        std::string op = ctx->UNARY()->getText();
        visit(ctx->expr());
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

antlrcpp::Any CodeGenVisitor::visitAnd(ifccParser::AndContext *ctx) {
    if (ctx->AND()) {
        this->visit(ctx->expr(0));
        std::string temp = newTemp();
        symbols.declare(temp, "int");
        stackOffsets[temp].push(stackOffset);
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset += 4;
        this->visit(ctx->expr(1));
        int varStackOffset = stackOffsets[temp].top();
        std::cout << "    and -" << varStackOffset << "(%rbp), %eax" << std::endl;
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitOr(ifccParser::OrContext *ctx) {
    if (ctx->OR()) {
        this->visit(ctx->expr(0));
        std::string temp = newTemp();
        symbols.declare(temp, "int");
        stackOffsets[temp].push(stackOffset);
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset += 4;
        this->visit(ctx->expr(1));
        int varStackOffset = stackOffsets[temp].top();
        std::cout << "    or -" << varStackOffset << "(%rbp), %eax" << std::endl;
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitXor(ifccParser::XorContext *ctx) {
    if (ctx->XOR()) {
        this->visit(ctx->expr(0));
        std::string temp = newTemp();
        symbols.declare(temp, "int");
        stackOffsets[temp].push(stackOffset);
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset += 4;
        this->visit(ctx->expr(1));
        int varStackOffset = stackOffsets[temp].top();
        std::cout << "    xor -" << varStackOffset << "(%rbp), %eax" << std::endl;
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitPlus(ifccParser::PlusContext *ctx) {
    if (ctx->OPA()) {
        this->visit(ctx->expr(0));
        std::string temp = newTemp();
        symbols.declare(temp, "int");
        stackOffsets[temp].push(stackOffset);
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset += 4;
        this->visit(ctx->expr(1));
        if (ctx->OPA()->getText() == "+") {
            int varStackOffset = stackOffsets[temp].top();
            std::cout << "    addl -" << varStackOffset << "(%rbp), %eax" << std::endl;
        } else if (ctx->OPA()->getText() == "-") {
            int varStackOffset = stackOffsets[temp].top();
            std::cout << "    subl %eax, -" << varStackOffset << "(%rbp)" << std::endl;
            std::cout << "    movl  -" << varStackOffset << "(%rbp), %eax" << std::endl;
        }
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExpr(ifccParser::ExprContext *ctx) {
    std::cout << "Visiting expression\n";
    return nullptr;  
}


antlrcpp::Any CodeGenVisitor::visitMul(ifccParser::MulContext *ctx) {
    if (ctx->OPM()) {
        this->visit(ctx->expr(0));
        std::string temp = newTemp();
        symbols.declare(temp, "int");
        stackOffsets[temp].push(stackOffset);
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)" << std::endl;
        stackOffset += 4;
        this->visit(ctx->expr(1));
        if (ctx->OPM()->getText() == "*") {
            int varStackOffset = stackOffsets[temp].top();
            std::cout << "    imull -" << varStackOffset << "(%rbp), %eax" << std::endl;
        } else if (ctx->OPM()->getText() == "/") {
            int varStackOffset = stackOffsets[temp].top();
            std::cout << "    movl %eax, %ecx" << std::endl;
            std::cout << "    movl -" << varStackOffset << "(%rbp), %eax" << std::endl;
            std::cout << "    cltd" << std::endl;
            std::cout << "    idivl %ecx" << std::endl;
        } else if (ctx->OPM()->getText() == "%") {
            int varStackOffset = stackOffsets[temp].top();
            std::cout << "    movl %eax, %ecx" << std::endl;
            std::cout << "    movl -" << varStackOffset << "(%rbp), %eax" << std::endl;
            std::cout << "    cltd" << std::endl;
            std::cout << "    idivl %ecx" << std::endl;
            std::cout << "   movl %edx, %eax" << std::endl;
        }
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitConst(ifccParser::ConstContext *ctx) {
    if (ctx->CONST()) {
        std::cout << "    movl $" << ctx->CONST()->getText() << ", %eax" << std::endl;
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitId(ifccParser::IdContext *ctx) {
    if (ctx->ID()) {
        int variableSymbol = stackOffsets[ctx->ID()->getText()].top();
        std::cout << "    movl -" << variableSymbol << "(%rbp), %eax" << std::endl;
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitParent(ifccParser::ParentContext *ctx) {
    if (ctx->expr()) {
        this->visit(ctx->expr());
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitMoin(ifccParser::MoinContext *ctx) {
    if (ctx->OPA() && ctx->OPA()->getText() == "-") {
        this->visit(ctx->expr());
        std::cout << "    negl %eax\n";
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitFunct(ifccParser::FunctContext *ctx) {
    if (ctx->ID() && ctx->OPENPARENT() && ctx->CLOSEPARENT()) {
        std::string functionName = ctx->ID()->getText();
        std::cout << "    call " << functionName << "\n";
    }
    return 0;
}
