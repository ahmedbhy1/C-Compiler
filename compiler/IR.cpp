#ifndef IR_H
#define IR_H


#include <iostream>
#include <variant>
#include <vector>
#include <string>
#include <iostream>
#include <initializer_list>
#include <map>
#include <unordered_set>
#include <stack>

class BasicBlock;
class CFG;
class DefFonction;


typedef enum {
    integer,
    string
}   Type;

//! The class for one 3-address instruction
class IRInstr {
 
   public:
	/** The instructions themselves -- feel free to subclass instead */
    typedef enum {
        ldconst,
        copy,
        add,
        sub,
        mul,
        div,
        orB,
        andB,
        xorB,
        opp,
        neg,
        equal,
        nequal,
        greater,
        greatere,
        less,
        lesse,
        cdtAnd,
        cdtOr,
        rmem,
        wmem,
        call,
        cmp_eq,
        cmp_neq,
        cmp_ge,
        cmp_g,
        cmp_l,
        cmp_le,
        ret,
        jmp
    } Operation;


	/**  constructor */
	IRInstr(BasicBlock* bb_, Operation op, Type t, std::vector<std::string> params);
	
	/** Actual code generation */
	void IRInstr::gen_asm(std::ostream & o) {

		std::string p1, p2, p3;
		Type t;
	
		if (this->op == call) {
			p1 = this->params[0];
			p2 = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope, this->t);
		} else if (this->op == jmp) {
			p1 = this->params[0];
		} else {
			switch (this->params.size()) {
				case 3:
					p3 = this->bb->cfg->IR_reg_to_asm(this->params[2], this->bb->scope, this->t);
				case 2:
					p2 = this->bb->cfg->IR_reg_to_asm(this->params[1], this->bb->scope, this->t);
				case 1:
					p1 = this->bb->cfg->IR_reg_to_asm(this->params[0], this->bb->scope, this->t);
				default:
					break;
			}
		}
	
		switch (this->op) {
			case ldconst:
				if (this->t == INT64_T) {
					o << "        movabsq    " << p2 << ", %rax" << endl;
					o << "        movq       %rax, " << p1 << endl;
				} else {
					o << "        " << getMovInstr() << "       " << p2 << ", " << p1 << endl;
				}
				break;
			case copy:
				t = this->t;
				if (p2.at(0) == '%') {
					t = findRegType(p2);
				}
				o << "        " << getMovInstr(t) << "       " << p2 << ", " << getReg1(t) << endl;
				o << "        " << getMovInstr() << "       " << getReg1() << ", " << p1 << endl;
				break;
			case add:
				if (p2 == "%rbp") {
					o << "        movq       " << p2 << ", %rax" << endl;
				} else {
					o << "        " << getMovInstr() << "       " << p2 << ", " << getReg1() << endl;
				}
				o << "        " << getAddInstr() << "       " << p3 << ", " << getReg1() << endl;
				o << "        " << getMovInstr() << "       " << getReg1() << ", " << p1 << endl;
				break;
			case sub:
				o << "        " << getMovInstr() << "       " << p2 << ", " << getReg1() << endl;
				o << "        " << getSubInstr() << "       " << p3 << ", " << getReg1() << endl;
				o << "        " << getMovInstr() << "       " << getReg1() << ", " << p1 << endl;
				break;
			case mul:
				o << "        " << getMovInstr() << "       " << p2 << ", " << getReg1() << endl;
				o << "        " << getMovInstr() << "       " << p3 << ", " << getTmpReg() << endl;
				o << "        " << getMullInstr() << "      " << getTmpReg() << endl;
				o << "        " << getMovInstr() << "       " << getReg1() << ", " << p1 << endl;
				break;
			case div:
				if (p3[0] == '$') {
					o << "        " << getMovInstr() << "       " << p3 << ", " << getTmpReg() << endl;
					p3 = getTmpReg();
				}
				o << "        " << getMovInstr() << "       " << p2 << ", " << getReg1() << endl;
				o << "        cltd" << endl;
				o << "        " << getDivInstr() << "       " << p3 << endl;
				o << "        " << getMovInstr() << "       " << getReg1() << ", " << p1 << endl;
				break;
			case orB:
				o << "        " << getMovInstr() << "       " << p2 << ", " << getReg1() << endl;
				o << "        " << getOrInstr() << "       " << p3 << ", " << getReg1() << endl;
				o << "        " << getMovInstr() << "       " << getReg1() << ", " << p1 << endl;
				break;
			case andB:
				o << "        " << getMovInstr() << "       " << p2 << ", " << getReg1() << endl;
				o << "        " << getAndInstr() << "       " << p3 << ", " << getReg1() << endl;
				o << "        " << getMovInstr() << "       " << getReg1() << ", " << p1 << endl;
				break;
			case xorB:
				o << "        " << getMovInstr() << "       " << p2 << ", " << getReg1() << endl;
				o << "        " << getXorInstr() << "       " << p3 << ", " << getReg1() << endl;
				o << "        " << getMovInstr() << "       " << getReg1() << ", " << p1 << endl;
				break;
			case neg:
				o << "        " << getCmpInstr() << "       $0, " << p2 << endl;
				o << "        sete       %al" << endl;
				o << "        movzbl    %al, %eax" << endl;
				o << "        " << getMovInstr() << "       " << getReg1() << ", " << p1 << endl;
				break;
			case opp:
				o << "        " << getMovInstr() << "       " << p2 << ", " << getReg1() << endl;
				o << "        " << getNegInstr() << "       " << getReg1() << endl;
				o << "        " << getMovInstr() << "       " << getReg1() << ", " << p1 << endl;
				break;
			case call: {
				// lets see how we should do the functions
			}
			case cmp_eq:
				o << "        " << getMovInstr() << "       " << p2 << ", " << getReg1() << endl;
				o << "        " << getCmpInstr() << "       " << p3 << ", " << getReg1() << endl;
				o << "        sete       %al" << endl;
				o << "        movzbq    %al, %rax" << endl;
				o << "        movq       %rax, " << p1 << endl;
				break;
			case cmp_neq:
				o << "        " << getMovInstr() << "       " << p2 << ", " << getReg1() << endl;
				o << "        " << getCmpInstr() << "       " << p3 << ", " << getReg1() << endl;
				o << "        setne      %al" << endl;
				o << "        movzbq     %al, %rax" << endl;
				o << "        movq       %rax, " << p1 << endl;
				break;
			case cmp_g:
				o << "        " << getMovInstr() << "       " << p2 << ", " << getReg1() << endl;
				o << "        " << getCmpInstr() << "       " << p3 << ", " << getReg1() << endl;
				o << "        setg       %al" << endl;
				o << "        movzbq     %al, %rax" << endl;
				o << "        movq       %rax, " << p1 << endl;
				break;
			case cmp_ge:
				o << "        " << getMovInstr() << "       " << p2 << ", " << getReg1() << endl;
				o << "        " << getCmpInstr() << "       " << p3 << ", " << getReg1() << endl;
				o << "        setge      %al" << endl;
				o << "        movzbq     %al, %rax" << endl;
				o << "        movq       %rax, " << p1 << endl;
				break;
			case cmp_l:
				o << "        " << getMovInstr() << "       " << p2 << ", " << getReg1() << endl;
				o << "        " << getCmpInstr() << "       " << p3 << ", " << getReg1() << endl;
				o << "        setl       %al" << endl;
				o << "        movzbq     %al, %rax" << endl;
				o << "        movq       %rax, " << p1 << endl;
				break;
			case cmp_le:
				o << "        " << getMovInstr() << "       " << p2 << ", " << getReg1() << endl;
				o << "        " << getCmpInstr() << "       " << p3 << ", " << getReg1() << endl;
				o << "        setle      %al" << endl;
				o << "        movzbq     %al, %rax" << endl;
				o << "        movq       %rax, " << p1 << endl;
				break;
	
			case cdtAnd:
				o << "        " << getMovInstr() << "       " << p2 << ", " << getReg1() << endl;
				o << "        and        " << p3 << ", " << getReg1() << endl;
				o << "        movl       %eax, " << p1 << endl;
				break;
			case cdtOr:
				o << "        " << getMovInstr() << "       " << p2 << ", " << getReg1() << endl;
				o << "        or         " << p3 << ", " << getReg1() << endl;
				o << "        movl       %eax, " << p1 << endl;
				break;
			case ret:
				o << "        " << getMovInstr() << "       " << p1 << ", " << getReg1() << endl;
				o << "        jmp        " << bb->cfg->bb_epilogue->label << endl;
				break;
			case jmp:
				o << "        jmp        " << p1 << endl;
	
			default:
				break;
		}
	} //fin de gen_asm(Ir_Instr)
	
 private:
	BasicBlock* bb; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
	Operation op;
	Type t;
	std::vector<std::string> params; /**< For 3-op instrs: d, x, y; for ldconst: d, c;  For call: label, d, params;  for wmem and rmem: choose yourself */
	// if you subclass IRInstr, each IRInstr subclass has its parameters and the previous (very important) comment becomes useless: it would be a better design. 
};






/**  The class for a basic block */

/* A few important comments.
	 IRInstr has no jump instructions.
	 cmp_* instructions behaves as an arithmetic two-operand instruction (add or mult),
	  returning a boolean value (as an int)

	 Assembly jumps are generated as follows:
	 BasicBlock::gen_asm() first calls IRInstr::gen_asm() on all its instructions, and then 
		    if  exit_true  is a  nullptr, 
            the epilogue is generated
        else if exit_false is a nullptr, 
          an unconditional jmp to the exit_true branch is generated
				else (we have two successors, hence a branch)
          an instruction comparing the value of test_var_name to true is generated,
					followed by a conditional branch to the exit_false branch,
					followed by an unconditional branch to the exit_true branch
	 The attribute test_var_name itself is defined when converting 
  the if, while, etc of the AST  to IR.

Possible optimization:
     a cmp_* comparison instructions, if it is the last instruction of its block, 
       generates an actual assembly comparison 
       followed by a conditional jump to the exit_false branch
*/

class BasicBlock {
 public:
	BasicBlock(CFG* cfg, std::string entry_label);

	void gen_asm(std::ostream &o); /**< x86 assembly code generation for this basic block (very simple) */

	void add_IRInstr(IRInstr::Operation op, Type t, std::vector<std::string> params);

	// No encapsulation whatsoever here. Feel free to do better.
	BasicBlock* exit_true;  /**< pointer to the next basic block, true branch. If nullptr, return from procedure */ 
	BasicBlock* exit_false; /**< pointer to the next basic block, false branch. If null_ptr, the basic block ends with an unconditional jump */
	std::string label; /**< label of the BB, also will be the label in the generated code */
	CFG* cfg; /** < the CFG where this block belongs */
	std::vector<IRInstr*> instrs; /** < the instructions themselves. */
    std::string test_var_name;  /** < when generating IR code for an if(expr) or while(expr) etc,
													 store here the name of the variable that holds the value of expr */
 protected:

 
};




/** The class for the control flow graph, also includes the symbol table */

/* A few important comments:
	 The entry block is the one with the same label as the AST function name.
	   (it could be the first of bbs, or it could be defined by an attribute value)
	 The exit block is the one with both exit pointers equal to nullptr.
     (again it could be identified in a more explicit way)

 */
class CFG {
 public:
	CFG(DefFonction* ast);

	DefFonction* ast; /**< The AST this CFG comes from */
	
	void add_bb(BasicBlock* bb){
		bbs.push_back(bb);
	}; 



	// x86 code generation: could be encapsulated in a processor class in a retargetable compiler
	
	void CFG::gen_asm(std::ostream & o) {
		bool delete_jump = gen_asm_prologue(o);

		std::vector<BasicBlock *>::iterator it;
		std::vector<BasicBlock *>::iterator it2;

		bool use_block_label = false;

		std::unordered_set<std::string> labelsToKeep;
		for (it = this->bbs.begin() + 1; it != (this->bbs.end() - 1); it++) {
			for (IRInstr * instr : (*it)->instrs) {
				std::string label = instr->fake_gen_asm_X86();
				if (label != "") {
					labelsToKeep.insert(label);
				}
			}
		}

		for (it = this->bbs.begin() + 1; it != (this->bbs.end() - 1); it++) {

			if (delete_jump == false) {
				o << (*it)->label << ":" << std::endl;
			} else {
				delete_jump = false;
			}

			for (IRInstr * instr : (*it)->instrs) {
				instr->gen_asm(o);
			}

			use_block_label = false;

			if (labelsToKeep.find((*it)->exit_true->label) != labelsToKeep.end()) {
				use_block_label = true;

			} else {
				for (it2 = this->bbs.begin() + 1; it2 != (it); it2++) {
					if ((*it2)->exit_true == (*it)->exit_true || (*it2)->exit_false == (*it)->exit_true) {
						use_block_label = true;
						break;
					}
				}

				for (it2 = it + 1; it2 != (this->bbs.end() - 1); it2++) {
					if ((*it2)->exit_true == (*it)->exit_true || (*it2)->exit_false == (*it)->exit_true) {
						use_block_label = true;
						break;
					}
				}
			}

			if ((*it)->exit_false == nullptr) {

				if ((*(it + 1))->label != (*it)->exit_true->label || use_block_label) {
					o << "        jmp        " << (*it)->exit_true->label << std::endl;

				} else {
					delete_jump = true;
				}

			} else {
				Type type = (*it)->cfg->GetSymbolTable()->GetVariableType((*it)->cfg->GetName(), (*it)->test_var_name, (*it)->scope);
				std::string cmpInstr = "cmpl";
				
				o << "        " << cmpInstr << "       $0, " << (*it)->cfg->IR_reg_to_asm_X86((*it)->test_var_name, (*it)->scope, type) << endl;
				o << "        je         " << (*it)->exit_false->label << endl;

				if ((*(it + 1))->label != (*it)->exit_true->label || use_block_label) {
					o << "        jmp        " << (*it)->exit_true->label << endl;
				} else {
					delete_jump = true;
				}
			}
		}

		gen_asm_epilogue(o);
	} //fin de gen_asm
	
	
	
	std::string CFG::IR_reg_to_asm(std::string reg, std::string scope, Type type) {

		std::string ret;
	
		if (reg == "reg1") {
			
			ret = "%eax";
		} else if (reg == "reg2") {
			
			ret = "%ebx";
		
		} else {
			// a completer
		}
	
		return ret;
	} //fin de IR_reg_to_asm_X86

	bool gen_asm_prologue(std::ostream& o);
	bool gen_asm_epilogue(std::ostream& o);

	// symbol table methods
	void add_to_symbol_table(std::string name, Type t);
	std::string create_new_tempvar(Type t);
	int get_var_inde(std::string name);
	Type get_var_type(std::string name);

	// basic block management
	std::string new_BB_name();
	BasicBlock* current_bb;

 protected:
 
    std::map<std::string, std::pair<int,int>> symbolTable;
    std::unordered_set<std::string> usedVariables;
    int stackOffset = 0;
    int tempCounter = 0;
    std::string newTemp() {
         return "#temp_" + std::to_string(tempCounter++);
    }
    std::stack<std::string> breakLabels; 
    std::stack<std::string> continueLabels;
    std::map<std::string, Type> SymbolType; /**< part of the symbol table  */
	std::map<std::string, int> SymbolIndex; /**< part of the symbol table  */
	int nextFreeSymbolIndex; /**< to allocate new symbols in the symbol table */
	int nextBBnumber; /**< just for naming */
	
	std::vector<BasicBlock*> bbs; /**< all the basic blocks of this CFG*/
};
class IR {

	void GenerateAsm(std::ostream & o) {
		//gen_asm_prologue_global_X86(o);

		for (auto cfg : this->allCFG) {
			cfg->gen_asm(o);
			o << std::endl;
		}
	} //----- Fin de GenerateAsmX86

	
	void IR::AddCFG(CFG * newCFG) {
		this->allCFG.push_back(newCFG);
	}

};

#endif