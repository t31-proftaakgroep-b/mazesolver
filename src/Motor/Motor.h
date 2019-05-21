#ifndef MOTOR_H
#define MOTOR_H

#include "IMotor.h"

#include <stdint.h>
#include <string>

class Motor
{
    public:
        Motor(std::string port, Point maxDistance);
        ~Motor();

        void MotorOn();
        void MotorOff();
        void Calibrate(Point position);
        std::string GetAddress() const;
        void SetDirection(Direction newDirection);
        Direction GetDirection() const;
        void ToPosition(Point newPosition);
    
    private:
        Direction direction;
        Point position;

        std::string address;

};

#endif