#pragma once

#include "Instruction.h"

#include <vector>

class Solution
{
    public:
    Solution(std::vector<Instruction> instructions);
    std::vector<Instruction> GetInstructions();

    private:
    std::vector<Instruction> instructions;
};