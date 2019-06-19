#include "Jsonparser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

Jsonparser::Jsonparser(std::vector<std::string>commands)
{
    Commands = commands;
}

void Jsonparser::getCommands(std::vector<std::string>ReceivedCommands)
{
    int size = ReceivedCommands.size();
    std::string temp;
    for (int i = 0; i < size; i++)
    {
        Commands.push_back(ReceivedCommands[i]);
        ReceivedCommands.erase(ReceivedCommands.begin() + i); 
    }  
}

bool Jsonparser::DoneParsing()
{
    if (Commands.size() > 0)
    {
        return false;
    }
    else
    {
        return true;
    }  
}

std::string Jsonparser::getNextCommand()
{   
    std::string returnValue = Commands[0];
    Commands.erase(Commands.begin());
    return returnValue;
}