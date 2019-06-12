#pragma once

#include "../Interfaces/IMotor.h"

#include <stdint.h>
#include <string>

class Motor
{
    public:
        Motor(std::string port, Point maxDistance);
        ~Motor();

        void Calibrate(Point position);
        std::string GetAddress() const;
        Direction GetDirection() const;
        void MotorOn();
        void MotorOff();
        void SetDirection(Direction newDirection);
        void ToPosition(Point newPosition);
    
    private:
        Direction direction;
        Point position;

        std::string address;

};