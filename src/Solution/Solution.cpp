#include "Solution.h"

Solution::Solution(std::vector<Instruction> instructions)
{
    *Instructions = instructions;
}

std::vector<Instruction> Solution::GetInstructions()
{
    return *Instructions;
}

std::vector<std::string> Solution::GetInstructionStrings()
{
    std::vector<std::string> output;

    for(std::vector<std::string>::size_type i = 0; i < Instructions->size(); i++)
    {
        std::string nextString = "";
        if(Instructions->at(i).direction == Up)
        {
            nextString += "UP: ";
        }
        else if(Instructions->at(i).direction == Right)
        {
            nextString += "Right: ";
        }
        else if(Instructions->at(i).direction == Down)
        {
            nextString += "Down: ";
        }
        else if(Instructions->at(i).direction == Left)
        {
            nextString += "Left: ";
        }

        nextString += std::to_string(Instructions->at(i).distance);
        nextString += "\n";

        output.push_back(nextString);
    }

    return output;
}