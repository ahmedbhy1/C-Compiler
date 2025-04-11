#include "IR.h"
#include <iostream>
#include <sstream>

// IRInstr implementation
IRInstr::IRInstr(BasicBlock* bb_, Operation op, Type t, std::vector<std::string> params)
    : bb(bb_), op(op), t(t), params(params) {}

void IRInstr::gen_asm(std::ostream &o) {
	
    switch(op) {
        case ldconst:
            o << "    movl $" << params[1] << ", -" << bb->cfg->get_var_index(params[0]) << "(%rbp)\n";
            break;
        case copy:
            o << "    movl -" << bb->cfg->get_var_index(params[1]) << "(%rbp), %eax\n";
            o << "    movl %eax, -" << bb->cfg->get_var_index(params[0]) << "(%rbp)\n";
            break;
        case add:
            o << "    movl -" << bb->cfg->get_var_index(params[1]) << "(%rbp), %eax\n";
            o << "    addl -" << bb->cfg->get_var_index(params[2]) << "(%rbp), %eax\n";
            o << "    movl %eax, -" << bb->cfg->get_var_index(params[0]) << "(%rbp)\n";
            break;
        case sub:
            o << "    movl -" << bb->cfg->get_var_index(params[1]) << "(%rbp), %eax\n";
            o << "    subl -" << bb->cfg->get_var_index(params[2]) << "(%rbp), %eax\n";
            o << "    movl %eax, -" << bb->cfg->get_var_index(params[0]) << "(%rbp)\n";
            break;
        case mul:
            o << "    movl -" << bb->cfg->get_var_index(params[1]) << "(%rbp), %eax\n";
            o << "    imull -" << bb->cfg->get_var_index(params[2]) << "(%rbp), %eax\n";
            o << "    movl %eax, -" << bb->cfg->get_var_index(params[0]) << "(%rbp)\n";
            break;
        case div:
            o << "    movl -" << bb->cfg->get_var_index(params[1]) << "(%rbp), %eax\n";
            o << "    cltd\n";
            o << "    idivl -" << bb->cfg->get_var_index(params[2]) << "(%rbp)\n";
            o << "    movl %eax, -" << bb->cfg->get_var_index(params[0]) << "(%rbp)\n";
            break;
        case cmp_eq:
            o << "    movl -" << bb->cfg->get_var_index(params[1]) << "(%rbp), %eax\n";
            o << "    cmpl -" << bb->cfg->get_var_index(params[2]) << "(%rbp), %eax\n";
            o << "    sete %al\n";
            o << "    movzbl %al, %eax\n";
            o << "    movl %eax, -" << bb->cfg->get_var_index(params[0]) << "(%rbp)\n";
            break;
        case cmp_neq:
            o << "    movl -" << bb->cfg->get_var_index(params[1]) << "(%rbp), %eax\n";
            o << "    cmpl -" << bb->cfg->get_var_index(params[2]) << "(%rbp), %eax\n";
            o << "    setne %al\n";
            o << "    movzbl %al, %eax\n";
            o << "    movl %eax, -" << bb->cfg->get_var_index(params[0]) << "(%rbp)\n";
            break;
        case cmp_ge:
            o << "    movl -" << bb->cfg->get_var_index(params[1]) << "(%rbp), %eax\n";
            o << "    cmpl -" << bb->cfg->get_var_index(params[2]) << "(%rbp), %eax\n";
            o << "    setge %al\n";
            o << "    movzbl %al, %eax\n";
            o << "    movl %eax, -" << bb->cfg->get_var_index(params[0]) << "(%rbp)\n";
            break;
        case cmp_g:
            o << "    movl -" << bb->cfg->get_var_index(params[1]) << "(%rbp), %eax\n";
            o << "    cmpl -" << bb->cfg->get_var_index(params[2]) << "(%rbp), %eax\n";
            o << "    setg %al\n";
            o << "    movzbl %al, %eax\n";
            o << "    movl %eax, -" << bb->cfg->get_var_index(params[0]) << "(%rbp)\n";
            break;
        case cmp_l:
            o << "    movl -" << bb->cfg->get_var_index(params[1]) << "(%rbp), %eax\n";
            o << "    cmpl -" << bb->cfg->get_var_index(params[2]) << "(%rbp), %eax\n";
            o << "    setl %al\n";
            o << "    movzbl %al, %eax\n";
            o << "    movl %eax, -" << bb->cfg->get_var_index(params[0]) << "(%rbp)\n";
            break;
        case cmp_le:
            o << "    movl -" << bb->cfg->get_var_index(params[1]) << "(%rbp), %eax\n";
            o << "    cmpl -" << bb->cfg->get_var_index(params[2]) << "(%rbp), %eax\n";
            o << "    setle %al\n";
            o << "    movzbl %al, %eax\n";
            o << "    movl %eax, -" << bb->cfg->get_var_index(params[0]) << "(%rbp)\n";
            break;
        case neg:
            o << "    movl -" << bb->cfg->get_var_index(params[1]) << "(%rbp), %eax\n";
            o << "    negl %eax\n";
            o << "    movl %eax, -" << bb->cfg->get_var_index(params[0]) << "(%rbp)\n";
            break;
        case call:
            o << "    call " << params[0] << "\n";
            if (params.size() > 1) {
                o << "    movl %eax, -" << bb->cfg->get_var_index(params[1]) << "(%rbp)\n";
            }
            break;
        case ret:
            if (!params.empty()) {
                o << "    movl -" << bb->cfg->get_var_index(params[0]) << "(%rbp), %eax\n";
            }
            o << "    leave\n";
            o << "    ret\n";
            break;
        case jmp:
            o << "    jmp " << params[0] << "\n";
            break;
        default:
            throw std::runtime_error("Unsupported IR operation");
    }
}

// BasicBlock implementation
BasicBlock::BasicBlock(CFG* cfg, std::string entry_label)
    : exit_true(nullptr), exit_false(nullptr), label(entry_label), cfg(cfg) {}

void BasicBlock::add_IRInstr(IRInstr::Operation op, Type t, std::vector<std::string> params) {
    instrs.push_back(new IRInstr(this, op, t, params));
}

void BasicBlock::gen_asm(std::ostream &o) {
    o << label << ":\n";
    for (IRInstr* instr : instrs) {
        instr->gen_asm(o);
    }
    
    if (exit_true == nullptr) {
        // Epilogue will be generated by CFG
    } else if (exit_false == nullptr) {
        o << "    jmp " << exit_true->label << "\n";
    } else {
        o << "    cmpl $0, -" << cfg->get_var_index(test_var_name) << "(%rbp)\n";
        o << "    je " << exit_false->label << "\n";
        o << "    jmp " << exit_true->label << "\n";
    }
}

void BasicBlock::GenerateAsmX86(std::ostream &o) {
    gen_asm(o);
}

// CFG implementation
CFG::CFG(DefFonction* ast) : ast(ast), nextFreeSymbolIndex(0), nextBBnumber(0) {
    current_bb = new BasicBlock(this, new_BB_name());
    add_bb(current_bb);
}

std::string CFG::new_BB_name() {
    return ast->getName() + "_" + std::to_string(nextBBnumber++);
}

void CFG::add_to_symbol_table(std::string name, Type t) {
    if (SymbolIndex.find(name) != SymbolIndex.end()) {
        throw std::runtime_error("Variable '" + name + "' already declared");
    }
    SymbolIndex[name] = nextFreeSymbolIndex;
    SymbolType[name] = t;
    nextFreeSymbolIndex += 4; // 4 bytes for integers
}

std::string CFG::create_new_tempvar(Type t) {
    std::string temp = "temp_" + std::to_string(tempCounter++);
    add_to_symbol_table(temp, t);
    return temp;
}

int CFG::get_var_index(std::string name) {
    if (SymbolIndex.find(name) == SymbolIndex.end()) {
        throw std::runtime_error("Variable '" + name + "' not declared");
    }
    return SymbolIndex[name];
}

Type CFG::get_var_type(std::string name) {
    if (SymbolType.find(name) == SymbolType.end()) {
        throw std::runtime_error("Variable '" + name + "' not declared");
    }
    return SymbolType[name];
}

std::string CFG::IR_reg_to_asm(std::string reg, std::string scope, Type type) {
    if (SymbolIndex.find(reg) != SymbolIndex.end()) {
        return "-" + std::to_string(SymbolIndex[reg]) + "(%rbp)";
    }
    return reg; // For constants or other cases
}

bool CFG::gen_asm_prologue(std::ostream& o) {
    o << ast->getName() << ":\n";
    o << "    pushq %rbp\n";
    o << "    movq %rsp, %rbp\n";
    o << "    subq $" << nextFreeSymbolIndex << ", %rsp\n";
    return true;
}

bool CFG::gen_asm_epilogue(std::ostream& o) {
    o << "    movq %rbp, %rsp\n";
    o << "    popq %rbp\n";
    o << "    ret\n";
    return true;
}

void CFG::gen_asm(std::ostream& o) {
    gen_asm_prologue(o);
    for (BasicBlock* bb : bbs) {
        bb->gen_asm(o);
    }
    gen_asm_epilogue(o);
}

BasicBlock* CFG::get_current_bb(){
	return current_bb;
}


// IR implementation
void IR::AddCFG(CFG * newCFG) {
    allCFG.push_back(newCFG);
}

void IR::gen_asm_prologue_global(std::ostream & o) {
    o << ".globl main\n";
}

void IR::GenerateAsm(std::ostream & o) {
    gen_asm_prologue_global(o);
    for (CFG* cfg : allCFG) {
        cfg->gen_asm(o);
    }
}

IR::~IR() {
    for (CFG* cfg : allCFG) {
        delete cfg;
    }
}