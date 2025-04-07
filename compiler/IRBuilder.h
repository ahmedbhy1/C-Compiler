#pragma once

#include <vector>
#include <string>
#include "IR.h" // You’ll define Instruction, BasicBlock, etc. here

class IRBuilder {
private:
    std::vector<BasicBlock*> blocks;
    BasicBlock* currentBlock = nullptr;
    int tempCounter = 0;

public:
    BasicBlock* createBlock(const std::string& name);
    void setCurrentBlock(BasicBlock* block);
    void emit(Instruction* instr);
    void emitConditionalBranch(Value* condition, BasicBlock* trueBlock, BasicBlock* falseBlock);
    void emitJump(BasicBlock* target);
    std::string generateTemp();
    std::vector<BasicBlock*>& getBlocks();
};
