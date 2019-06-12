#include "Maze.h"

Maze::Maze(std::vector<MazeField> fields)
{
    bool containsStart = false;
    bool containsFinish = false;

    int i = 0; //counter

    for(std::vector<MazeField>::iterator it = fields.begin(); it != fields.end(); it++, i++)
    {
        if(fields[i].Type == Start)
        {
            if(!containsStart)
            {
                containsStart = true;  
            }
            else
            {
                throw std::invalid_argument("Maze has two Starts");
            }
        }
        else if(fields[i].Type == Finish)
        {
            if(!containsFinish)
            { 
                containsFinish = true;
            }
            else
            {
                throw std::invalid_argument("Maze has two Finishes");
            }
        }
    }

    if(!containsStart || !containsFinish)
    {
        throw std::invalid_argument("Maze needs a start and finish");
    }

    fields = fields;
}

std::vector<MazeField> Maze::GetFields()
{
    return fields;
}