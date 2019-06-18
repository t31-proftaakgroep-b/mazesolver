#include "Solution.h"

Solution::Solution(std::vector<Instruction> instructions)
{
    *this->instructions = instructions;
}

std::vector<Instruction> Solution::GetInstructions()
{
    return *instructions;
}

std::vector<std::string> Solution::GetInstructionStrings()
{
    std::vector<std::string> output;

    for(std::vector<std::string>::size_type i = 0; i < instructions->size(); i++)
    {
        std::string nextString = "";
        if(instructions->at(i).direction == Up)
        {
            nextString += "UP: ";
        }
        else if(instructions->at(i).direction == Right)
        {
            nextString += "Right: ";
        }
        else if(instructions->at(i).direction == Down)
        {
            nextString += "Down: ";
        }
        else if(instructions->at(i).direction == Left)
        {
            nextString += "Left: ";
        }

        nextString += std::to_string(instructions->at(i).distance);
        nextString += "\n";

        output.push_back(nextString);
    }

    return output;
}