#pragma once

#include "MazeField.h"

#include <stdexcept>
#include <vector>

class Maze
{
    public:
    Maze(std::vector<MazeField> fields);
    std::vector<MazeField> GetFields(); 

    private:
    std::vector<MazeField> fields;
};