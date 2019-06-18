#include "MazeSolver.h"

MazeSolver::MazeSolver()
{
}

MazeSolver::~MazeSolver()
{
}

Solution MazeSolver::SolveMaze(Maze maze)
{
    //std::vector<MazeField> solutionFields = GetSolutionFields(maze);
    std::vector<MazeField> solutionFields;
    solutionFields.push_back({0, 0, Empty});
    solutionFields.push_back({0, 1, Empty});
    solutionFields.push_back({0, 2, Empty});
    solutionFields.push_back({1, 2, Empty});
    std::vector<Instruction> instructionVector;

    MazeField previousField = solutionFields[0];
    Direction previousDirection = Up;
    int straightAmount = 0;

    for(std::vector<MazeField>::size_type i = 1; i < solutionFields.size(); i++)
    {
        Direction newDirection;
        if(solutionFields[i].X == previousField.X + 1 && solutionFields[i].Y == previousField.Y)
        {
            newDirection = Right;
        }
        else if(solutionFields[i].X == previousField.X - 1 && solutionFields[i].Y == previousField.Y)
        {
            newDirection = Left;
        }
        else if(solutionFields[i].X == previousField.X && solutionFields[i].Y == previousField.Y + 1)
        {
            newDirection = Up;
        }
        else if(solutionFields[i].X == previousField.X && solutionFields[i].Y == previousField.Y - 1)
        {
            newDirection = Down;
        }

        if(newDirection == previousDirection)
        {
            straightAmount++;
        }
        else if(straightAmount > 0)
        {
            instructionVector.push_back(Instruction({straightAmount, previousDirection}));
            straightAmount = 1;
        }
        else
        {
            straightAmount = 1;
        }

        previousDirection = newDirection;
        previousField = solutionFields[i];
    }
    instructionVector.push_back(Instruction({straightAmount, previousDirection}));

    return instructionVector;
}

std::vector<MazeField> MazeSolver::GetSolutionFields(Maze maze)
{
    std::vector<MazeField> fields = *maze.GetFields();
    MazeField start;
    Direction currentDirection = Up;

    int i = 0; //counter

    for(std::vector<MazeField>::iterator it = fields.begin(); it != fields.end(); it++, i++)
    {
        if(fields[i].Type == Start)
        {
            start = fields[i];
        }
    }

    std::vector<MazeField> currentPath;

    currentPath.push_back(start);

    bool mazeSolved = false;
    bool retreading = false;
    int retreadCounter = 1;

    while(!mazeSolved)
    {
        MazeField nextField = NextField(fields, currentPath.back(), currentDirection);

        if(nextField.Type == Finish)
        {
            mazeSolved = true;
        }

        if(retreading)
        {
            if(VectorContainsField(nextField, fields))
            {
                retreadCounter += 2;
            }
            else
            {
                //currentPath[currentPath.end - 1].Type = Wall;
                currentPath.erase(currentPath.end() - retreadCounter, currentPath.end() - 1);
                retreading = false;
                retreadCounter = 1;
            }
        }

        if(FieldsEqual(nextField, currentPath.end()[-1]))
        {
            retreading = true;
        }

        currentPath.push_back(nextField);
    }

    return currentPath;

    /*std::vector<MazeField> finalPath;
    bool deadEndsRemoved;
    while(!deadEndsRemoved)
    {
        MazeField nextField = NextField(fields, finalPath.end, &currentDirection);

        if(nextField.X == finish.X && nextField.Y == finish.Y)
        {
            deadEndsRemoved = true;
        }
    }*/

}

MazeField MazeSolver::NextField(std::vector<MazeField> fields, MazeField currentField, Direction &currentDirection)
{
    MazeField topField;
    MazeField rightField;
    MazeField bottomField;
    MazeField leftField;

    int i = 0;

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

    std::vector<MazeField> possibleNextFields= {topField, rightField, bottomField, leftField};
  
    for(int j = 0; j < 4; j++)
    {
        Direction relativeDirection = Direction(currentDirection + j);

        currentDirection = Direction(j);

        if(relativeDirection == Left)
        {
            return possibleNextFields[j];
        }
        else if(relativeDirection == Up)
        {
            return possibleNextFields[j];
        }
        else if(relativeDirection == Right)
        {
            return possibleNextFields[j];
        }
        else if(relativeDirection == Down)
        {
            return possibleNextFields[j];
        }
    }

    return possibleNextFields[3];
}

bool MazeSolver::FieldsEqual(MazeField a, MazeField b)
{
    if(a.X == b.X && a.Y == b.Y && a.Type == b.Type)
    {
        return true;
    }
    else
    {
        return false;
    }
} 

bool MazeSolver::VectorContainsField(MazeField field, std::vector<MazeField> allFields)
{
    int i = 0;

    for(std::vector<MazeField>::iterator it = allFields.begin(); it != allFields.end(); it++, i++)
    {
        if(FieldsEqual(allFields[i], field))
        {
            return true;
        }
    }

    return false;
}