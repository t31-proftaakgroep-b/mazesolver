#include "Motor.h"
#include <fstream>
#include <sstream>
#include <iostream>

const int maxMotorFiles = 30;
	
Motor::Motor(std::string portName, int maxDistance, char as)
{	
	motorFilePath = findMotorPath(portName);

	MaxDistance = maxDistance;
	MotorAs = as;
	
	if (MotorAs == 'Y' || MotorAs == 'Z')
	{	
		inverseMotor(true);
	}
	else
	{
		inverseMotor(false);
	}
}
char Motor::getMotorAs()
{
	return MotorAs;
}

Motor::~Motor(){}
void Motor::inverseMotor(bool inversed)
{
	std::string folder = "/polarity";
	if(inversed)
	{
		writeToFile(folder, "inversed");
	}else
	{
		writeToFile(folder, "normal");
	}	
}
void Motor::moveForDistance(int distance)
{

	writeToFile("/position_sp", distance);
	writeToFile("/command","run-to-rel-pos");
}	
	
void Motor::moveToPosition(int newPosition)
{
	int position = 0;
	int setPosition = 0;
	position = getPosition();
	
	setPosition = newPosition - position;

	moveForDistance(setPosition);
}

int Motor::getPosition()
{
	int position = 0;
	
	readFromFile("/position", &position);
	
	return position;
}

int Motor::getSpeed()
{
	int speed = 0;
	
	readFromFile("/speed", &speed);
	
	return speed;
}

bool Motor::stopMotor()
{
	writeToFile("/command", "stop");
	return true;
}

void Motor::setPosition(int newPosition)
{
	writeToFile("/position", newPosition);
}
	
void Motor::resetPosition()
{
	setPosition(0);
}
	
void Motor::goToMax()
{
	moveToPosition(MaxDistance);
}
	
void Motor::setSpeed(int newSpeed)
{
	writeToFile("/speed_sp",newSpeed);
}

void Motor::readFromFile(std::string folder, int* returnValue)
{
	std::ifstream MyMotor;
	std::stringstream FilePath;

	FilePath << motorFilePath << folder;
	std::string stringFilePath = FilePath.str();
	
	MyMotor.open (stringFilePath.c_str());
	MyMotor >> *returnValue;
	MyMotor.close();
}

void Motor::writeToFile(std::string folder, int writeValue)
{
	std::stringstream stringwriteValue;
	stringwriteValue << writeValue;
	writeToFile(folder, stringwriteValue.str());
}

void Motor::writeToFile(std::string folder, std::string writeValue)
{
	std::ofstream MyMotor;
	std::stringstream FilePath;

	FilePath << motorFilePath << folder;
	std::string stringFilePath = FilePath.str();
	
	MyMotor.open (stringFilePath.c_str());
	MyMotor << writeValue;
	MyMotor.close();
}

std::string Motor::findMotorPath(std::string port)
{
	std::ifstream myFile;
	std::string motorClassFilePath = "/sys/class/tacho-motor/motor";
	//std::string portNamePath = "/port_name";
	//std::string foundMotorPath ="";
	//bool pathFound = false;

	if(port == "outA")
	{
		motorClassFilePath += '0';
	}
	else if(port == "outB")
	{
		motorClassFilePath += '1';
	}
	else if (port == "outC")
	{
		motorClassFilePath += '3';
	}
	
	
	return motorClassFilePath;
}

int Motor::getMaxDistance()
{
	return MaxDistance;
}

std::string Motor::getMotorFilePath()
{
	return motorFilePath;
}