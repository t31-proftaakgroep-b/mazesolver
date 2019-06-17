#pragma once

#include "Instruction.h"

#include <string>
#include <vector>

class Solution
{
    public:
    Solution(std::vector<Instruction> instructions);
    std::vector<Instruction> GetInstructions();
    std::vector<std::string> GetInstructionStrings();

    private:
    std::vector<Instruction> instructions;
};