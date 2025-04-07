#include "IRBuilder.h"

BasicBlock* IRBuilder::createBlock(const std::string& name) {
    auto* block = new BasicBlock(name);
    blocks.push_back(block);
    return block;
}

void IRBuilder::setCurrentBlock(BasicBlock* block) {
    currentBlock = block;
}

void IRBuilder::emit(Instruction* instr) {
    if (currentBlock) {
        currentBlock->instructions.push_back(instr);
    }
}

void IRBuilder::emitConditionalBranch(Value* condition, BasicBlock* trueBlock, BasicBlock* falseBlock) {
    emit(new ConditionalBranch(condition, trueBlock, falseBlock));
}

void IRBuilder::emitJump(BasicBlock* target) {
    emit(new Jump(target));
}

std::string IRBuilder::generateTemp() {
    return "t" + std::to_string(tempCounter++);
}

std::vector<BasicBlock*>& IRBuilder::getBlocks() {
    return blocks;
}
