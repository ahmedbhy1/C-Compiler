#pragma once
#include <string>
#include <vector>

struct Value {
    std::string name;
    Value(const std::string& n) : name(n) {}
    virtual ~Value() = default;
};

struct Instruction {
    virtual std::string toString() const = 0;
    virtual ~Instruction() = default;
};

struct BasicBlock {
    std::string name;
    std::vector<Instruction*> instructions;

    BasicBlock(const std::string& n) : name(n) {}
};

struct Jump : Instruction {
    BasicBlock* target;
    Jump(BasicBlock* t) : target(t) {}

    std::string toString() const override {
        return "jump " + target->name;
    }
};

struct ConditionalBranch : Instruction {
    Value* condition;
    BasicBlock* thenBlock;
    BasicBlock* elseBlock;

    ConditionalBranch(Value* c, BasicBlock* t, BasicBlock* e)
        : condition(c), thenBlock(t), elseBlock(e) {}

    std::string toString() const override {
        return "br " + condition->name + ", " + thenBlock->name + ", " + elseBlock->name;
    }
};
