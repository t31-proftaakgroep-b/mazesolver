#include "Motor.h"

Motor::Motor(std::string port, Point maxDistance)
{

}

Motor::~Motor()
{
    
}

void Motor::Calibrate(Point position)
{

}

std::string Motor::GetAddress() const
{
    return address;
}

Direction Motor::GetDirection() const
{
    return direction;
}

void Motor::MotorOn()
{

}

void Motor::MotorOff()
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