#include "IR.h"
#include <iostream>
#include <sstream>

const char* param_regs[] = {"%edi", "%esi", "%edx", "%ecx", "%r8d", "%r9d"};
Type getTypes(std::string typeStr) {
    if (typeStr == "int")return INT32_T;
    else if (typeStr == "string")return STRING;
    else throw std::invalid_argument("Unknown type: " + typeStr);
}

// IRInstr implementation
IRInstr::IRInstr(BasicBlock* bb_, Operation op, Type t, std::vector<std::string> params)
    : bb(bb_), op(op), t(t), params(params) {}

    void IRInstr::gen_asm(std::ostream &o) {
        std::string first;
        std::string second;
        std::string third;
        //o<< "params size"<<params.size()<<" op: "<< op <<"\n";
        
        if (params.size()){
            //o << "params[0]=" << params[0] << "\n";
            if (!bb->cfg->isitin_index_table(params[0])) {
                first = params[0];
            } else {
                first = "-" + std::to_string(bb->cfg->get_var_index(params[0])) + "(%rbp)";
            }
        }
        if (params.size() > 1 ){
            //o << "params[1]=" << params[1] << "\n";
            if (!bb->cfg->isitin_index_table(params[1])){
                second = params[1];
            }else{
                second = "-" + std::to_string(bb->cfg->get_var_index(params[1])) + "(%rbp)";
            }
        }
        
        if (params.size() > 2 ){
            //o << "params[2]=" << params[2] << "\n";
            if(!bb->cfg->isitin_index_table(params[2])){
                third = params[2];
            }else{
                third = "-" + std::to_string(bb->cfg->get_var_index(params[2])) + "(%rbp)";
            }
        }
        
        int x;
    
        switch(op) {
            case andB:
                o << "    andl " << second << ", " << first << "\n";
                break;
            case call_putchar:
                o << "    subq $4, %rsp\n"; 
                o << "    movl " << first << ", %edi\n";
                o << "    call putchar\n";
                o << "    movl %eax, " << first << "\n";
                break;
            case xorB:
                o << "    xorl " << second << ", " << first << "\n";
            break;
            case orB:
                o << "    orl " << second << ", " << first << "\n";
                break;
            case ldconst:
                o << "    movl $" << second << ", " << first << "\n";
                break;
            case copy:
                o << "    movl " << second << ", " << first << "\n";
                break;
            case add:
                o << "    movl " << second << ", %eax\n";
                o << "    addl " << third << ", %eax\n";
                o << "    movl %eax, " << first << "\n";
                break;
            case sub:
                o << "    subl " << third << ", "+second+"\n";
                o << "    movl "+second << ", %eax\n";
                break;
            case mul:
                o << "    movl " << second << ", %eax\n";
                o << "    imull " << third << ", %eax\n";
                o << "    movl %eax, " << first << "\n";
                break;
            case div:
                o << "    movl " << "%eax" << ", %ecx\n";
                o << "    movl " << second << ", %eax\n";
                o << "    cltd\n";
                o << "    idivl " << "%ecx" << "\n";
                o << "    movl %eax, " << first << "\n";
                break;
            case mod:
                o << "    movl " << "%eax" << ", %ecx\n";
                o << "    movl " << second << ", %eax\n";
                o << "    cltd\n";
                o << "    idivl " << "%ecx" << "\n";
                o << "    movl %edx, " << first << "\n";  // The remainder is in %edx
                break;
            case cmp_eq:
                o << "    movl " << second << ", %eax\n";
                o << "    cmpl " << third << ", %eax\n";
                o << "    sete %al\n";
                o << "    movzbl %al, %eax\n";
                o << "    movl %eax, " << first << "\n";
                break;
            case cmp_neq:
                o << "    movl " << second << ", %eax\n";
                o << "    cmpl " << third << ", %eax\n";
                o << "    setne %al\n";
                o << "    movzbl %al, %eax\n";
                o << "    movl %eax, " << first << "\n";
                break;
            case cmp_ge:
                o << "    movl " << second << ", %eax\n";
                o << "    cmpl " << third << ", %eax\n";
                o << "    setge %al\n";
                o << "    movzbl %al, %eax\n";
                o << "    movl %eax, " << first << "\n";
                break;
            case cmp_g:
                o << "    movl " << second << ", %eax\n";
                o << "    cmpl " << third << ", %eax\n";
                o << "    setg %al\n";
                o << "    movzbl %al, %eax\n";
                o << "    movl %eax, " << first << "\n";
                break;
            case cmp_l:
                o << "    movl " << second << ", %eax\n";
                o << "    cmpl " << third << ", %eax\n";
                o << "    setl %al\n";
                o << "    movzbl %al, %eax\n";
                o << "    movl %eax, " << first << "\n";
                break;
            case cmp_le:
                o << "    movl " << second << ", %eax\n";
                o << "    cmpl " << third << ", %eax\n";
                o << "    setle %al\n";
                o << "    movzbl %al, %eax\n";
                o << "    movl %eax, " << first << "\n";
                break;
            case neg:
                o << "    movl " << second << ", %eax\n";
                o << "    negl %eax\n";
                o << "    movl %eax, " << first << "\n";
                break;
            case call:
                if (params.size()>1){
                    for (int i =1;i<params.size();i++){
                        std::string nthparam;
                        if(!bb->cfg->isitin_index_table(params[i])){
                            nthparam = params[i];
                        }else{
                            nthparam = "-" + std::to_string(bb->cfg->get_var_index(params[i])) + "(%rbp)";
                        }
                        
                        o << "    movl " << nthparam <<", "<< param_regs[i-1] << "\n";        
                    }
                }
                o << "    call " << params[0] << "\n";
                break;
            case ret:
                if (!params.empty()) {
                    o << "    movl " << first << ", %eax\n";
                }
                o << "    leave\n";
                o << "    ret\n";
                break;
            case jmp:
                o << "    jmp " << params[0] << "\n";
                break;
            case je:
                o << "    cmp $0, %eax \n"; 
                o << "    je " << params[0] << "\n";
                break;
            case prologue:
                x = 1;
                break;
            default:
                x = 1;
                //throw std::runtime_error("Unsupported IR operation");
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

bool CFG::isitin_index_table(std::string name) {
    if (SymbolIndex.find(name) == SymbolIndex.end()) {
        return false;
    }
    return true;
}

int CFG::get_var_index(std::string name) {
    if (SymbolIndex.find(name) == SymbolIndex.end()) {
        throw std::runtime_error("Variable index'" + name + "' not declared");
    }
    return SymbolIndex[name]+4;
}

Type CFG::get_var_type(std::string name) {
    if (SymbolType.find(name) == SymbolType.end()) {
        throw std::runtime_error("Variable type'" + name + "' not declared");
    }
    return SymbolType[name];
}

std::string CFG::IR_reg_to_asm(std::string reg, std::string scope, Type type) {
    if (SymbolIndex.find(reg) != SymbolIndex.end()) {
        int offset = SymbolIndex[reg];
        if (offset < 0) {
            // Parameter (stored above RBP)
            return std::to_string(abs(offset)) + "(%rbp)";
        } else {
            // Local variable (stored below RBP)
            return "-" + std::to_string(offset) + "(%rbp)";
        }
    }
    return reg; // For constants or registers
}

bool CFG::gen_asm_prologue(std::ostream& o) {
    o << ast->getName() << ":\n";
    o << "    pushq %rbp\n";
    o << "    movq %rsp, %rbp\n";
    
    // Save parameter registers to stack
    int reg_idx = 0;
    for (const auto& param : params) {
        if (reg_idx < 6) {  // First 6 params in registers
            o << "    movl " << param_regs[reg_idx] << ", -" 
              << get_var_index(param.first) << "(%rbp)\n";
            reg_idx++;
        }
        // Additional params would be on stack at positive RBP offsets
    }
    
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

void CFG::add_param_to_symbol_table(std::string name, Type t) {
    if (SymbolIndex.find(name) != SymbolIndex.end()) {
        throw std::runtime_error("Parameter '" + name + "' already declared");
    }
    // Parameters are stored at positive offsets from RBP
    SymbolIndex[name] =  nextFreeSymbolIndex + 8 + paramOffset;
    SymbolType[name] = t;
    paramOffset += 4;  // 4 bytes per parameter
    params.emplace_back(name, t);
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

//defFonction
void DefFonction::addParameter(std::string paramName, std::string  paramType) {
    parameters.push_back({paramName, getTypes(paramType)});
  }