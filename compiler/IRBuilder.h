#pragma once

#include <vector>
#include <string>
#include "IR.h" // You’ll define Instruction, BasicBlock, etc. here

class IRBuilder {
private:
    std::vector<BasicBlock*> blocks;
    BasicBlock* currentBlock = new BasicBlock("startBlock");
    int tempCounter = 0;

    public:
        BasicBlock* createBlock(const std::string& name){
            BasicBlock* newBlock = new BasicBlock(name);
            blocks.push_back(newBlock);
            return newBlock;
    }

    void setCurrentBlock(BasicBlock* block) {
        currentBlock = block;
    }

    void emit(Instruction* instr) {
        currentBlock -> instructions.push_back(instr);
    }

    void emitConditionalBranch(Value* condition, BasicBlock* trueBlock, BasicBlock* falseBlock) {
        emit(new ConditionalBranch(condition, trueBlock, falseBlock));
    }

    void emitJump(BasicBlock* target) {
        emit(new Jump(target));
    }

    std::string generateTemp() {
        return "t" + std::to_string(tempCounter++);
    }

    std::vector<BasicBlock*>& getBlocks() {
        return blocks;
    }

    // New method to handle the if-else statement
    void emitIfElse(Value* condition, BasicBlock* trueBlock, BasicBlock* falseBlock) {
        // Create the "after" block where control should go after the if-else
        BasicBlock* afterBlock = createBlock("after_" + generateTemp());

        // Emit the conditional branch (if condition is true, jump to trueBlock; else, jump to falseBlock)
        emitConditionalBranch(condition, trueBlock, falseBlock);

        // Emit jump to the after block from both trueBlock and falseBlock to avoid fall-through
        emitJump(afterBlock);

        // Now handle the true block
        setCurrentBlock(trueBlock);
        // (Emit instructions for the true block)
        emitJump(afterBlock); // Jump to after block once done

        // Now handle the false block
        setCurrentBlock(falseBlock);
        // (Emit instructions for the false block)
        emitJump(afterBlock); // Jump to after block once done

        // Finally, set the current block to the after block
        setCurrentBlock(afterBlock);

    }
};