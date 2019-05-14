#ifndef MOTOR_H
#define MOTOR_H

#include "IMotor.h"

#include <stdint.h>
#include <string>

class Motor
{
    public:
        Motor(std::string port, Point maxDistance);
    
    private:
        Direction direction;
        Point position;

};

#endif