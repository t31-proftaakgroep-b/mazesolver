#ifndef MOTOR_H
#define MOTOR_H 

#include <stdbool.h>
#include <string>

class Motor
{
private:
    int MaxDistance;
    char MotorAs;
    std::string motorFilePath;
    
	void inverseMotor(bool inversed);
	std::string findMotorPath(std::string port);
	void readFromFile(std::string folder, int* Value);
	void writeToFile(std::string folder, int writeValue);
	void writeToFile(std::string folder, std::string writeValue);

public:
    Motor(std::string portName, int maxDistance, char as);
	virtual ~Motor();

	char getMotorAs();
	
	void setPosition(int nextPosition);
	
	void moveForDistance(int distance);
	
	void moveToPosition(int nextPosition);
	
	int getPosition();
	
	void resetPosition();
	
	void goToMax();
	
	bool stopMotor();
	
	void setSpeed(int newSpeed);
	
	int getSpeed();
	
	int getMaxDistance();
	
	std::string getMotorFilePath();
};

#endif

