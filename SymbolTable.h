#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class SymbolTable {
private:
    std::vector<std::unordered_map<std::string, std::string>> scopes;

public:
    SymbolTable() {
        enterScope(); 
    }

    void enterScope() {
        scopes.push_back({});
    }

    void exitScope() {
        if (!scopes.empty()) {
            scopes.pop_back();
        }
    }

    bool declare(const std::string& name, const std::string& type) {
        auto& current = scopes.back();
        if (current.count(name)) return false; 
        current[name] = type;
        return true;
    }

    std::string lookup(const std::string& name) {
        for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
            if (it->count(name)) {
                return it->at(name);
            }
        }
        return ""; // not found
    }
};
