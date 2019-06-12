#include "Solution.h"

Solution::Solution(std::vector<Instruction> instructions)
{
    instructions = instructions;
}

std::vector<Instruction> Solution::GetInstructions()
{
    return instructions;
}