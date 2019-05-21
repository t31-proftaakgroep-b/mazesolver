#include "Motor.h"

Motor::Motor(std::string port, Point maxDistance)
{

}

Motor::~Motor()
{
    
}

Direction Motor::GetDirection() const
{
    return direction;
}

std::string Motor::GetAddress() const
{
    return address;
}

void Motor::MotorOn()
{

}

void Motor::MotorOff()
{

}

void Motor::Calibrate(Point position)
{

}

void Motor::SetDirection(Direction newDirection)
{
    direction = newDirection;
}

void Motor::ToPosition(Point newPosition)
{
    //Is this stil the same action?
    //position = newPosition;
    //Motor controlls
}