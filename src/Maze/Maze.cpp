#include "Maze.h"

Maze::Maze(std::vector<MazeField> fields)
{
    bool containsStart = false;
    bool containsFinish = false;

    for(std::vector<MazeField>::size_type i = 0; i < fields.size(); i++)
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

    *Fields = fields;
}

std::vector<MazeField> *Maze::GetFields()
{
    return Fields;
}

std::string Maze::GetMazeVisual()
{
    int maxX = 0;
    int maxY = 0;

    int i = 0;
    

    for(std::vector<MazeField>::iterator it = Fields->begin(); it != Fields->end(); ++it)
    {
        if(Fields->at(i).X > maxX)
        {
            maxX = Fields->at(i).X;
        }
        if(Fields->at(i).Y > maxY)
        {
            maxY = Fields->at(i).Y;
        }
        i++;
    }
   

    std::string output = "";

    for(int y = 0; y < maxY + 1; y++)
    {
        for(int x = 0; x < maxX + 1; x++)
        {
            MazeField mazeField = GetFieldAtCoordinate(x, y);
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
    if(Fields->size() > 0)
    {
        for(std::vector<MazeField>::size_type i = 0; i < Fields->size(); i++)
        {
            if(Fields->at(i).X == x && Fields->at(i).Y == y)
            {           
                return Fields->at(i);
            }
        }

    return Fields->at(0);
    }
    throw std::invalid_argument("fields isnt populated");
}