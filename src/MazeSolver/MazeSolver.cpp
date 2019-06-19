#include "MazeSolver.h"

MazeSolver::MazeSolver()
{
}

MazeSolver::~MazeSolver()
{
}

Solution MazeSolver::SolveMaze(Maze maze)
{
    std::vector<MazeField> solutionFields = GetSolutionFields(maze);

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

    Solution outputSolution = Solution(instructionVector);

    return outputSolution;
}

std::vector<MazeField> MazeSolver::GetSolutionFields(Maze maze)
{
    std::vector<MazeField> fields = *maze.GetFields();
    MazeField start;
    Direction currentDirection = Up;

    for(std::vector<MazeField>::size_type i = 1; i < fields.size(); i++)
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

}

MazeField MazeSolver::NextField(std::vector<MazeField> fields, MazeField currentField, Direction &currentDirection)
{
    MazeField topField;
    MazeField rightField;
    MazeField bottomField;
    MazeField leftField;

    for(std::vector<MazeField>::size_type i = 1; i < fields.size(); i++)
    {
        if(fields[i].X == currentField.X + 1 && fields[i].Y == currentField.Y)
        {
            rightField = fields[i];
        }
        else if (fields[i].X == currentField.X - 1 && fields[i].Y == currentField.Y)
        {
            leftField = fields[i];
        }
        else if (fields[i].X == currentField.X && fields[i].Y == currentField.Y + 1)
        {
            topField = fields[i];
        }
        else if (fields[i].X == currentField.X && fields[i].Y == currentField.Y - 1)
        {
            bottomField = fields[i];
        }
    }

    std::vector<MazeField> possibleNextFields= {topField, rightField, bottomField, leftField};
  
    for(int j = 0; j < 4; j++)
    {
        Direction relativeDirection = Direction(j - currentDirection);

        currentDirection = Direction(j);
        if(possibleNextFields[j].Type != Wall)
        {
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
    for(std::vector<MazeField>::size_type i = 1; i < allFields.size(); i++)
    {
        if(FieldsEqual(allFields[i], field))
        {
            return true;
        }
    }

    return false;
}