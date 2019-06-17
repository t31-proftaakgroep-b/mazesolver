#include "Solution.h"

Solution::Solution(std::vector<Instruction> instructions)
{
    instructions = instructions;
}

std::vector<Instruction> Solution::GetInstructions()
{
    return instructions;
}

std::vector<std::string> Solution::GetInstructionStrings()
{
    int i = 0;

    std::vector<std::string> output;

    for(std::vector<Instruction>::iterator it = instructions.begin(); it != instructions.end(); it++, i++)
    {
        std::string nextString = "";
        if(instructions[i].direction == Up)
        {
            nextString += "UP: ";
        }
        else if(instructions[i].direction == Right)
        {
            nextString += "Right: ";
        }
        else if(instructions[i].direction == Down)
        {
            nextString += "Down: ";
        }
        else if(instructions[i].direction == Left)
        {
            nextString += "Left: ";
        }

        nextString += std::to_string(instructions[i].distance);

        output.push_back(nextString);
    }

    return output;
}