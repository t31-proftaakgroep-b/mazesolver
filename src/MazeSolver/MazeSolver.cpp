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
        else if(fields[i].Type == Finish)
        {
            finish = fields[i];
        }
    }

    std::vector<MazeField> currentPath;
    std::vector<MazeField> previousIntersections;

    currentPath.push_back(start);
}

MazeField MazeSolver::NextField(std::vector<MazeField> fields, MazeField currentField, Direction currentDirection)
{
    int i = 0;

    MazeField topField;
    MazeField rightField;
    MazeField bottomField;
    MazeField leftField;

    std::vector<MazeField> possibleNextFields;

    for(std::vector<MazeField>::iterator it = fields.begin(); it != fields.end(); it++, i++)
    {
        if(fields[i].X == currentField.X + 1 && fields[i].Y == currentField.Y && fields[i].Type == Empty)
        {
            rightField = fields[i];
        }
        else if (fields[i].X == currentField.X - 1 && fields[i].Y == currentField.Y && fields[i].Type == Empty)
        {
            leftField = fields[i];
        }
        else if (fields[i].X == currentField.X && fields[i].Y == currentField.Y + 1 && fields[i].Type == Empty)
        {
            topField = fields[i];
        }
        else if (fields[i].X == currentField.X && fields[i].Y == currentField.Y - 1 && fields[i].Type == Empty)
        {
            bottomField = fields[i];
        }
    }

    MazeField relativeLeft;
    MazeField relativeForward;
    MazeField relativeRight;
    
    if(FieldDirection(currentDirection, Right) == Right)
    {

    }
}

Direction MazeSolver::FieldDirection(Direction currentDirection, Direction nextDirection)
{
    return Direction(currentDirection + nextDirection % 4);
}