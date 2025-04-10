#include "IRBuilder.h"

class IRBuilder {
    private:
        std::vector<BasicBlock*> blocks;
        BasicBlock* currentBlock = nullptr;
        int tempCounter = 0;
    };

    