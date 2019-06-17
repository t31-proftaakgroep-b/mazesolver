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

    this->fields = fields;
}

std::vector<MazeField> Maze::GetFields()
{
    return fields;
}

std::string Maze::GetMazeVisual()
{
    int maxX = 3;
    int maxY = 3;

    /*int i = 0;

    for(std::vector<MazeField>::iterator it = fields.begin(); it != fields.end(); ++it)
    {
        if(fields[i].X > maxX)
        {
            maxX = fields[i].X;
        }
        if(fields[i].Y > maxY)
        {
            maxY = fields[i].Y;
        }
        //i++;
    }
   */


    std::string output = "test3";

    for(int y = 0; y < maxY; y++)
    {
        for(int x = 0; x < maxX; x++)
        {
            MazeField mazeField = GetFieldAtCoordinate(0, 0);
            if(mazeField.Type == Empty)
            {
                output += "E";
            }
            else if(mazeField.Type == Wall)
            {
                output += "W";
            }
            else if(mazeField.Type == Start)
            {
                output += "S";
            }
            else if(mazeField.Type == Finish)
            {
                output += "F";
            }
        }
        output += "\n";
    }

    return output;
}

MazeField Maze::GetFieldAtCoordinate(int x, int y)
{
    int i = 0;

    if(fields.size() > 0)
    {
        for(std::vector<MazeField>::iterator it = fields.begin(); it != fields.end(); ++it, i++)
        {
            if(it->X == x && it->Y == y)
            {           
                return *it;
            }
        }

    return fields[0];
    }
    throw std::invalid_argument("fields isnt populated");
}