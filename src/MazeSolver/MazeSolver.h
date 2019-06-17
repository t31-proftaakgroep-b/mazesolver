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
        std::vector<MazeField> GetSolutionFields(Maze maze);
    private:
        MazeField NextField(std::vector<MazeField> fields, MazeField currentField, Direction &currentDirection); 
        bool FieldsEqual(MazeField a, MazeField b); 
        bool VectorContainsField(MazeField field, std::vector<MazeField> allFields);
};
