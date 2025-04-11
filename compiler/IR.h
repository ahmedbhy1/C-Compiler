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
    INT32_T,
    string
}   Type;

//! The class for one 3-address instruction
class IRInstr {
 
    public:	/** The instructions themselves -- feel free to subclass instead */
    typedef enum {
        ldconst,
        copy,
        add,
        sub,
        mul,
        div,
        mod,
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
        jmp,
        call_getchar,
        call_putchar,
        prologue

    } Operation;


	/**  constructor */
	IRInstr(BasicBlock* bb_, Operation op, Type t, std::vector<std::string> params);
	
	/** Actual code generation */
	void gen_asm(std::ostream &o); /**< x86 assembly code generation for this IR instruction */
	
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
    void GenerateAsmX86(std::ostream & o);
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
	void gen_asm(std::ostream& o);
	std::string IR_reg_to_asm(std::string reg, std::string scope, Type type); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */
	bool gen_asm_prologue(std::ostream& o);
	bool gen_asm_epilogue(std::ostream& o);

	// symbol table methods
	void add_to_symbol_table(std::string name, Type t);
  BasicBlock* get_current_bb();
	std::string create_new_tempvar(Type t);
	int get_var_inde(std::string name);
	Type get_var_type(std::string name);
  int get_var_index(std::string name);

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
    public:
      ~IR();
      void GenerateAsm(std::ostream & o);

      void AddCFG(CFG * newCFG);
      void gen_asm_prologue_global(std::ostream & o);
    
    std::vector<CFG *> allCFG;
  };


class DefFonction {
  public:
      DefFonction(const std::string& name) : name(name) {}
      
      // Get the function name
      std::string getName() const { return name; }
      
      // Set the function name
      void setName(const std::string& newName) { name = newName; }
      
      // Add a parameter to the function
      void addParameter(const std::string& paramName, Type paramType) {
          parameters.push_back({paramName, paramType});
      }
      
      // Get all parameters
      const std::vector<std::pair<std::string, Type>>& getParameters() const {
          return parameters;
      }
      
      // Get return type
      Type getReturnType() const { return returnType; }
      
      // Set return type
      void setReturnType(Type type) { returnType = type; }
      
  private:
      std::string name;
      std::vector<std::pair<std::string, Type>> parameters;
      Type returnType = INT32_T; // Default return type
  };
  
  #endif // DEF_FONCTION_H