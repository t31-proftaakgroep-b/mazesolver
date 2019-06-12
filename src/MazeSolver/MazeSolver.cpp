#include "MazeSolver.h"

MazeSolver::MazeSolver()
{
}

MazeSolver::~MazeSolver()
{
}

Solution MazeSolver::SolveMaze(Maze maze)
{
    maze = maze;
    std::vector<Instruction> solutionVector;
    Solution solution(solution);
    return solution;

    std::vector<MazeField> fields = maze.GetFields();
    MazeField start;
    MazeField finish;

    int i = 0; //counter

    for(std::vector<MazeField>::iterator it = fields.begin(); it != fields.end(); it++, i++)
    {
        if(fields[i].Type == Start)
        {
            start = fields[i];
        }
        /*else if()
        {
            
        }*/
    }
}