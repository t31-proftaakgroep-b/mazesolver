#ifndef IMOTOR_H
#define IMOTOR_H

#include "Direction.h"
#include "Point.h"
#include <string>

class IMotor
{
    public:
    virtual ~IMotor(){};
    virtual void MotorOn() = 0;
    virtual void MotorOff() = 0;
    virtual void Calibrate(Point position) = 0;
    virtual std::string GetAddress() const = 0;
    virtual void SetDirection(Direction newDirection) = 0;
    virtual Direction GetDirection() const = 0;
    virtual void ToPosition(Point newPosition) = 0;
};



#endif