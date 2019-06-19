#pragma once

#include <stdbool.h>
#include <string>
#include <vector>

class Jsonparser
{
private:
    std::vector<std::string> Commands; 
public:
    Jsonparser(std::vector<std::string>Commands);
    void getCommands(std::vector<std::string>ReceivedCommands);
    bool DoneParsing(); 
    std::string getNextCommand();
};