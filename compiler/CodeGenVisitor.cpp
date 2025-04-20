#include "CodeGenVisitor.h"
#include <iostream>


// Program and function visits
antlrcpp::Any CodeGenVisitor::visitProgs(ifccParser::ProgsContext *ctx) {
    IR ir;
    for (auto prog : ctx->def_func()) {
        this->visit(prog);
        ir.AddCFG(currentCFG);
        currentCFG = nullptr; // Transfer ownership to IR
    }
    
    // Generate final assembly
    //std::cout << ".globl main\n";
    ir.GenerateAsm(std::cout);
    return 0;
}  

antlrcpp::Any CodeGenVisitor::visitDef_func(ifccParser::Def_funcContext *ctx) {
    std::string name = ctx->ID()->getText();
    currentCFG = new CFG(new DefFonction(name));
    
    if (ctx ->param_list()){
        for(auto i :ctx->param_list()->param()){
            std::string name = i->ID()->getText();
            std::string type = i->type()->getText();
            currentCFG->add_param_to_symbol_table(name, getTypes(type));
            currentCFG->ast->addParameter(name,type);
        }
    }
    
    currentBB = currentCFG->get_current_bb();
    
    // Function prologue
    currentBB->add_IRInstr(IRInstr::prologue, INT32_T, {});
    
    // Visit all statements
    for (auto stmt : ctx->stmt()) {
        this->visit(stmt);
    }
    
    // Function epilogue
    currentBB->add_IRInstr(IRInstr::ret, INT32_T, {});
    return 0;
}

// Statement visits
antlrcpp::Any CodeGenVisitor::visitDecl_stmt(ifccParser::Decl_stmtContext *ctx) {
    for (auto decl : ctx->equalexpr_stmt()) {
        std::string varName = decl->ID()->getText();
        //std::cout<<"we declared: "<<varName<<std::endl;
        currentCFG->add_to_symbol_table(varName, INT32_T);
        
        if (decl->expr()) {
            this->visit(decl->expr());
            currentBB->add_IRInstr(IRInstr::copy, INT32_T, {varName, "%eax"});
        }
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitAssign_stmt(ifccParser::Assign_stmtContext *ctx) {
    std::string varName = ctx->ID()->getText();
    if(!currentCFG->isitin_index_table(varName)){
        throw std::runtime_error("variable in not initiated");
    }
    this->visit(ctx->expr());
    currentBB->add_IRInstr(IRInstr::copy, INT32_T, {varName, "%eax"});
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx) {
    this->visit(ctx->expr());
    currentBB->add_IRInstr(IRInstr::ret, INT32_T, {"%eax"});
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExpr(ifccParser::ExprContext *ctx){
    return nullptr;
}

// Expression visits
antlrcpp::Any CodeGenVisitor::visitComp(ifccParser::CompContext *ctx) {
    this->visit(ctx->expr(0));
    std::string temp1 = currentCFG->create_new_tempvar(INT32_T);
    currentBB->add_IRInstr(IRInstr::copy, INT32_T, {temp1, "%eax"});
    
    this->visit(ctx->expr(1));
    std::string temp2 = currentCFG->create_new_tempvar(INT32_T);
    currentBB->add_IRInstr(IRInstr::copy, INT32_T, {temp2, "%eax"});
    
    std::string op = ctx->COMP()->getText();
    IRInstr::Operation cmpOp;
    if (op == "==") cmpOp = IRInstr::cmp_eq;
    else if (op == "!=") cmpOp = IRInstr::cmp_neq;
    else if (op == "<") cmpOp = IRInstr::cmp_l;
    else if (op == "<=") cmpOp = IRInstr::cmp_le;
    else if (op == ">") cmpOp = IRInstr::cmp_g;
    else if (op == ">=") cmpOp = IRInstr::cmp_ge;
    else throw std::runtime_error("Unsupported comparison operator: " + op);
    
    std::string result = currentCFG->create_new_tempvar(INT32_T);
    currentBB->add_IRInstr(cmpOp, INT32_T, {result, temp1, temp2});
    currentBB->add_IRInstr(IRInstr::copy, INT32_T, {"%eax", result});
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitUnary(ifccParser::UnaryContext *ctx) {
    if (ctx->UNARY()) {
        std::string op = ctx->UNARY()->getText();
        visit(ctx->expr());
        
        if (op == "!") {
            std::string result = currentCFG->create_new_tempvar(INT32_T);
            currentBB->add_IRInstr(IRInstr::neg, INT32_T, {result, "%eax"});
            currentBB->add_IRInstr(IRInstr::copy, INT32_T, {"%eax", result});
        } else {
            throw std::runtime_error("Unsupported unary operator: " + op);
        }
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitAnd(ifccParser::AndContext *ctx) {
    if (ctx->AND()) {
        this->visit(ctx->expr(0));
        std::string temp = currentCFG->create_new_tempvar(INT32_T);
        currentBB->add_IRInstr(IRInstr::copy, INT32_T, {temp, "%eax"});
        
        this->visit(ctx->expr(1));
        currentBB->add_IRInstr(IRInstr::andB, INT32_T, {"%eax", temp, temp});
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitOr(ifccParser::OrContext *ctx) {
    if (ctx->OR()) {
        this->visit(ctx->expr(0));
        std::string temp = currentCFG->create_new_tempvar(INT32_T);
        currentBB->add_IRInstr(IRInstr::copy, INT32_T, {temp, "%eax"});
        
        this->visit(ctx->expr(1));
        currentBB->add_IRInstr(IRInstr::orB, INT32_T, {"%eax", temp, temp});
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitXor(ifccParser::XorContext *ctx) {
    if (ctx->XOR()) {
        this->visit(ctx->expr(0));
        std::string temp = currentCFG->create_new_tempvar(INT32_T);
        currentBB->add_IRInstr(IRInstr::copy, INT32_T, {temp, "%eax"});
        
        this->visit(ctx->expr(1));
        currentBB->add_IRInstr(IRInstr::xorB, INT32_T, {"%eax", temp, temp});
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitPlus(ifccParser::PlusContext *ctx) {
    if (ctx->OPA()) {
        this->visit(ctx->expr(0));
        std::string temp = currentCFG->create_new_tempvar(INT32_T);
        currentBB->add_IRInstr(IRInstr::copy, INT32_T, {temp, "%eax"});
        
        this->visit(ctx->expr(1));
        if (ctx->OPA()->getText() == "+") {
            currentBB->add_IRInstr(IRInstr::add, INT32_T, {"%eax", "%eax", temp});
        } else {
            currentBB->add_IRInstr(IRInstr::sub, INT32_T, {"%eax", temp, "%eax"});
        }
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitMul(ifccParser::MulContext *ctx) {
    if (ctx->OPM()) {
        this->visit(ctx->expr(0));
        std::string temp = currentCFG->create_new_tempvar(INT32_T);
        currentBB->add_IRInstr(IRInstr::copy, INT32_T, {temp, "%eax"});
        
        this->visit(ctx->expr(1));
        std::string op = ctx->OPM()->getText();
        if (op == "*") {
            currentBB->add_IRInstr(IRInstr::mul, INT32_T, {"%eax", "%eax", temp});
        } else if (op == "/") {
            currentBB->add_IRInstr(IRInstr::div, INT32_T, {"%eax", temp, "%eax"});
        } else if (op == "%") {
            currentBB->add_IRInstr(IRInstr::mod, INT32_T, {"%eax", temp, "%eax"});
        }
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitConst(ifccParser::ConstContext *ctx) {
    if (ctx->CONST()) {
        std::string value = ctx->CONST()->getText();
        std::string temp = currentCFG->create_new_tempvar(INT32_T);
        currentBB->add_IRInstr(IRInstr::ldconst, INT32_T, {temp, value});
        currentBB->add_IRInstr(IRInstr::copy, INT32_T, {"%eax", temp});
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitId(ifccParser::IdContext *ctx) {
    if (ctx->ID()) {
        std::string varName = ctx->ID()->getText();
        currentBB->add_IRInstr(IRInstr::copy, INT32_T, {"%eax", varName});
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
        currentBB->add_IRInstr(IRInstr::neg, INT32_T, {"%eax", "%eax"});
    }
    return 0;
}

// I/O operations
antlrcpp::Any CodeGenVisitor::visitGetchar_expr(ifccParser::Getchar_exprContext *ctx) {
    std::string temp = currentCFG->create_new_tempvar(INT32_T);
    currentBB->add_IRInstr(IRInstr::call_getchar, INT32_T, {temp});
    currentBB->add_IRInstr(IRInstr::copy, INT32_T, {"%eax", temp});
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitPutchar_stmt(ifccParser::Putchar_stmtContext *ctx) {
    this->visit(ctx->expr());
    currentBB->add_IRInstr(IRInstr::call_putchar, INT32_T, {"%eax"});
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitGetchar_stmt(ifccParser::Getchar_stmtContext *ctx) {
    std::string varName = ctx->ID()->getText();
    currentBB->add_IRInstr(IRInstr::call_getchar, INT32_T, {varName});
    return 0;
}

// Control flow
antlrcpp::Any CodeGenVisitor::visitBreak_stmt(ifccParser::Break_stmtContext *ctx) {
    if (breakLabels.empty()) {
        throw std::runtime_error("`break` used outside of a loop or switch.");
    }
    currentBB->add_IRInstr(IRInstr::jmp, INT32_T, {breakLabels.top()});
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitContinue_stmt(ifccParser::Continue_stmtContext *ctx) {
    if (continueLabels.empty()) {
        throw std::runtime_error("`continue` used outside of a loop.");
    }
    currentBB->add_IRInstr(IRInstr::jmp, INT32_T, {continueLabels.top()});
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitIf_stmt(ifccParser::If_stmtContext *ctx) {
    this->visit(ctx->expr());
    
    std::string falseLabel = currentCFG->new_BB_name();
    std::string endLabel = currentCFG->new_BB_name();
    
    // Create conditional jump
    currentBB->add_IRInstr(IRInstr::je, INT32_T, {falseLabel});
    
    // True branch
    BasicBlock* trueBB = new BasicBlock(currentCFG, currentCFG->new_BB_name());
    currentCFG->add_bb(trueBB);
    currentBB = trueBB;
    for (auto s : ctx->stmt()) {
        this->visit(s);
    }   
    currentBB->add_IRInstr(IRInstr::jmp, INT32_T, {endLabel});
    
    // False branch (if exists)
    if (ctx->else_stmt()) {
        
        BasicBlock* falseBB = new BasicBlock(currentCFG, falseLabel);
        currentCFG->add_bb(falseBB);
        currentBB = falseBB;
        this->visit(ctx->else_stmt());
        currentBB->add_IRInstr(IRInstr::jmp, INT32_T, {endLabel});
        
        } else {
        BasicBlock* falseBB = new BasicBlock(currentCFG, falseLabel);
        currentCFG->add_bb(falseBB);
        currentBB = falseBB;
    }
    
    // End block
    BasicBlock* endBB = new BasicBlock(currentCFG, endLabel);
    currentCFG->add_bb(endBB);
    currentBB = endBB;
    
    return 0;
}
antlrcpp::Any CodeGenVisitor::visitWhile_stmt(ifccParser::While_stmtContext *ctx) {

    // Create labels for the loop blocks
    std::string condLabel = currentCFG->new_BB_name(); // Loop condition
    std::string bodyLabel = currentCFG->new_BB_name(); // Loop body
    std::string endLabel = currentCFG->new_BB_name();  // After loop

    // Unconditional jump to condition check first
    currentBB->add_IRInstr(IRInstr::jmp, INT32_T, {condLabel});

    // Condition block
    BasicBlock* condBB = new BasicBlock(currentCFG, condLabel);
    currentCFG->add_bb(condBB);
    currentBB = condBB;

    // Evaluate the loop condition
    this->visit(ctx->expr());
    currentBB->add_IRInstr(IRInstr::je, INT32_T, {endLabel}); // Jump to end if false

    // Body block
    BasicBlock* bodyBB = new BasicBlock(currentCFG, bodyLabel);
    currentCFG->add_bb(bodyBB);
    currentBB = bodyBB;

    // Visit the loop body
    for (auto s : ctx->stmt()) {
        this->visit(s);
    }    

    // Jump back to condition check
    currentBB->add_IRInstr(IRInstr::jmp, INT32_T, {condLabel});

    // End block (after loop)
    BasicBlock* endBB = new BasicBlock(currentCFG, endLabel);
    currentCFG->add_bb(endBB);
    currentBB = endBB;

    return 0;
}



antlrcpp::Any CodeGenVisitor::visitFunct(ifccParser::FunctContext *ctx) {
    if (ctx->ID() && ctx->OPENPARENT() && ctx->CLOSEPARENT()) {
        std::string functionName = ctx->ID()->getText();
        currentBB->add_IRInstr(IRInstr::call, INT32_T, {functionName, "%eax"});
    }
    return 0;
}


antlrcpp::Any CodeGenVisitor::visitCallfunct(ifccParser::CallfunctContext *ctx) {
    std::string functionName = ctx->ID()->getText();
    std::vector<std::string> params;
    params.push_back(functionName);  // First parameter is function name

    // Handle arguments if they exist
    if (ctx->arg_list()) {
        for (auto constArg : ctx->arg_list()->CONST()) {
            std::string constValue = constArg->getText();
            // For each constant argument, load it directly
            std::string tempVar = currentCFG->create_new_tempvar(INT32_T);
            currentBB->add_IRInstr(IRInstr::ldconst, INT32_T, {tempVar, constValue});
            params.push_back(tempVar);
        }
    }

    // Generate the call instruction
    currentBB->add_IRInstr(IRInstr::call, INT32_T, params);
    
    
    return 0;
}

