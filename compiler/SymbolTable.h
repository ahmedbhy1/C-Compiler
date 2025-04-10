#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>

class SymbolTable {
private:
    std::vector<std::unordered_map<std::string, std::string>> scopes;
    std::unordered_map<std::string, std::stack<int>> stackOffsets;

public:
    SymbolTable() {
        enterScope();  // Initialize with global scope
    }

    void enterScope() {
        scopes.push_back({});
    }

    void exitScope() {
        if (!scopes.empty()) {
            scopes.pop_back();
            stackOffsets.clear();  
        }
    }

    bool declare(const std::string& name, const std::string& type) {
        auto& current = scopes.back();
        if (current.count(name)) {
            return false;  // Variable already declared in this scope
        }
        current[name] = type;
        return true;
    }

    std::string lookup(const std::string& name) {
        for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
            if (it->count(name)) {
                return it->at(name);  // Found variable in current scope
            }
        }
        return "";  // Variable not found
    }

    void addStackOffset(const std::string& name, int offset) {
        stackOffsets[name].push(offset);
    }

    int getStackOffset(const std::string& name) {
        return stackOffsets[name].top();
    }

    void removeStackOffset(const std::string& name) {
        if (!stackOffsets[name].empty()) {
            stackOffsets[name].pop();
        }
    }
};
