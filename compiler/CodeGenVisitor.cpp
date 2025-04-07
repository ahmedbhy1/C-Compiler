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

    symbols.enterScope();

    for (auto stmt : ctx->stmt()) {
        this->visit(stmt);
    }

    for (auto& entry : stackOffsets) {
        if (!entry.second.empty()) {
            entry.second.pop(); 
        }
    }
    symbols.exitScope();

    std::cout << "    movq %rbp, %rsp\n";
    std::cout << "    popq %rbp\n";
    std::cout << "    ret\n";

    return 0;
}


antlrcpp::Any CodeGenVisitor::visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) {
    for (auto i : ctx->equalexpr_stmt()) {
        if (i->ID()) {
            std::string varName = i->ID()->getText();

            if (!symbols.declare(varName, "int")) {
                throw std::runtime_error("Variable '" + varName + "' already declared in this scope.");
            }

            stackOffsets[varName].push(stackOffset);

            if (i->expr()) {
                this->visit(i->expr());
                std::cout << "    movl %eax, -" << stackOffset << "(%rbp)\n";
            }

            stackOffset += 4;
        }
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) {
    std::string varName = ctx->ID()->getText();

    if (symbols.lookup(varName) == "") {
        throw std::runtime_error("Variable '" + varName + "' not declared");
    }

    int varOffset = stackOffsets[varName].top();
    this->visit(ctx->expr());
    std::cout << "    movl %eax, -" << varOffset << "(%rbp)\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    this->visit(ctx->expr());
    std::cout << "    movq %rbp, %rsp\n";
    std::cout << "    popq %rbp\n";
    std::cout << "    ret\n";
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
        if (op == "==") std::cout << "    sete %al\n";
        else if (op == "!=") std::cout << "    setne %al\n";
        else if (op == "<") std::cout << "    setl %al\n";
        else if (op == "<=") std::cout << "    setle %al\n";
        else if (op == ">") std::cout << "    setg %al\n";
        else if (op == ">=") std::cout << "    setge %al\n";
        else throw std::runtime_error("Unsupported comparison: " + op);
        std::cout << "    movzbl %al, %eax\n";
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitUnary(ifccParser::UnaryContext *ctx) {
    if (ctx->UNARY()) {
        std::string op = ctx->UNARY()->getText();
        this->visit(ctx->expr());
        if (op == "!") {
            std::cout << "    cmpl $0, %eax\n";
            std::cout << "    sete %al\n";
            std::cout << "    movzbl %al, %eax\n";
        } else {
            throw std::runtime_error("Unsupported unary op: " + op);
        }
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitAnd(ifccParser::AndContext *ctx) {
    if (ctx->AND()) {
        this->visit(ctx->expr(0));
        std::string temp = newTemp();
        stackOffsets[temp].push(stackOffset);
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)\n";
        stackOffset += 4;
        this->visit(ctx->expr(1));
        int offset = stackOffsets[temp].top();
        std::cout << "    and -" << offset << "(%rbp), %eax\n";
        stackOffsets[temp].pop();
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitOr(ifccParser::OrContext *ctx) {
    if (ctx->OR()) {
        this->visit(ctx->expr(0));
        std::string temp = newTemp();
        stackOffsets[temp].push(stackOffset);
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)\n";
        stackOffset += 4;
        this->visit(ctx->expr(1));
        int offset = stackOffsets[temp].top();
        std::cout << "    or -" << offset << "(%rbp), %eax\n";
        stackOffsets[temp].pop();
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitXor(ifccParser::XorContext *ctx) {
    if (ctx->XOR()) {
        this->visit(ctx->expr(0));
        std::string temp = newTemp();
        stackOffsets[temp].push(stackOffset);
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)\n";
        stackOffset += 4;
        this->visit(ctx->expr(1));
        int offset = stackOffsets[temp].top();
        std::cout << "    xor -" << offset << "(%rbp), %eax\n";
        stackOffsets[temp].pop();
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitPlus(ifccParser::PlusContext *ctx) {
    if (ctx->OPA()) {
        this->visit(ctx->expr(0));
        std::string temp = newTemp();
        stackOffsets[temp].push(stackOffset);
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)\n";
        stackOffset += 4;
        this->visit(ctx->expr(1));
        int offset = stackOffsets[temp].top();
        if (ctx->OPA()->getText() == "+") {
            std::cout << "    addl -" << offset << "(%rbp), %eax\n";
        } else {
            std::cout << "    subl %eax, -" << offset << "(%rbp)\n";
            std::cout << "    movl -" << offset << "(%rbp), %eax\n";
        }
        stackOffsets[temp].pop();
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitMul(ifccParser::MulContext *ctx) {
    if (ctx->OPM()) {
        this->visit(ctx->expr(0));
        std::string temp = newTemp();
        stackOffsets[temp].push(stackOffset);
        std::cout << "    movl %eax, -" << stackOffset << "(%rbp)\n";
        stackOffset += 4;
        this->visit(ctx->expr(1));
        int offset = stackOffsets[temp].top();
        std::string op = ctx->OPM()->getText();
        if (op == "*") {
            std::cout << "    imull -" << offset << "(%rbp), %eax\n";
        } else if (op == "/") {
            std::cout << "    movl %eax, %ecx\n";
            std::cout << "    movl -" << offset << "(%rbp), %eax\n";
            std::cout << "    cltd\n";
            std::cout << "    idivl %ecx\n";
        } else if (op == "%") {
            std::cout << "    movl %eax, %ecx\n";
            std::cout << "    movl -" << offset << "(%rbp), %eax\n";
            std::cout << "    cltd\n";
            std::cout << "    idivl %ecx\n";
            std::cout << "    movl %edx, %eax\n";
        }
        stackOffsets[temp].pop();
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitConst(ifccParser::ConstContext *ctx) {
    if (ctx->CONST()) {
        std::cout << "    movl $" << ctx->CONST()->getText() << ", %eax\n";
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitId(ifccParser::IdContext *ctx) {
    std::string varName = ctx->ID()->getText();

    if (symbols.lookup(varName) == "") {
        throw std::runtime_error("Variable '" + varName + "' not declared");
    }

    int offset = stackOffsets[varName].top();
    std::cout << "    movl -" << offset << "(%rbp), %eax\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitParent(ifccParser::ParentContext *ctx) {
    return this->visit(ctx->expr());
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
        std::string fnName = ctx->ID()->getText();
        std::cout << "    call " << fnName << "\n";
    }
    return 0;
}
