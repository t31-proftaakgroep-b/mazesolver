#include "Motor.h"

Motor::Motor(std::string port, Point maxDistance)
{

}

Direction Motor::GetDirection() const
{
    return direction;
}

Point Motor::GetPosition() const
{
    return position;
}

void Motor::SetDirection(Direction newDirection)
{
    direction = newDirection;
}

void Motor::SetPosition(int newPosition)
{
    position = newPosition;
}