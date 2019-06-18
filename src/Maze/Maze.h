#pragma once

#include "MazeField.h"

#include <stdexcept>
#include <vector>

class Maze
{
    public:
    Maze(std::vector<MazeField> fields);
    std::vector<MazeField> *GetFields(); 
    std::string GetMazeVisual();

    private:
    std::vector<MazeField> *Fields;
    MazeField GetFieldAtCoordinate(int x, int y);
};