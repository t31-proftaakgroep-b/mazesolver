#pragma once

#include <stdint.h>
#include <string>
#include <vector>

#include "../Maze/Maze.h"
#include "../Solution/Solution.h"

class MazeSolver
{
    public:
        MazeSolver();
        ~MazeSolver();
        Solution SolveMaze(Maze maze);

    

};
