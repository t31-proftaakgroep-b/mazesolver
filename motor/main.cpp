#include "Motor.h"

#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <stdbool.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <chrono>
#include <thread>

int main()
{
    bool delayed = true;
    bool breakX = false;
    bool breakY = false;

    int speed = 500;
    int speedMinX = speed/100*95;
    int speedMaxX = speed/100*105;

    int speedMinY = speed/100*90;
    int speedMaxY = speed/100*110;

    Motor* MotorY = new Motor("outA", 10000, 'Y');
    Motor* MotorX = new Motor("outB", 10000, 'X');	
	// Motor* MotorZ = new Motor("outC", 1000, 'Z');
    
    MotorX->setSpeed(speed);
    MotorX->resetPosition();
    MotorX->goToMax();

    MotorY->setSpeed(speed);
    MotorY->resetPosition();
    MotorY->goToMax();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    while(true)
    {
        if(MotorX->getSpeed() < speedMinX || MotorX->getSpeed() > speedMaxX)
        {
            //std::cout << MotorX->getSpeed() << std::endl;
            MotorX->stopMotor();
            breakX = true;
        }
        
        if(delayed == true)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            delayed = false;
        }

        if((MotorY->getSpeed() < speedMinY || MotorY->getSpeed() > speedMaxY))
        {
            //std::cout << MotorY->getSpeed() << std::endl;
            MotorY->stopMotor();
            breakY = true;
        }
        
        if(breakX == true && breakY == true)
        {
            break;
        }
    }

	std::cout<<"Motor done"<<std::endl;

    return 0;
}

/*
Stappenplan: 

Start programma (UNINITIALIZED)

Caliberen (CALIBRATING)

Gecalibreerd, wachten op opdracht. (CALIBRATED, IDLE)

Daarna x, y motors aansturen om naar de startlocatie van de oplossing te gaan. (BUSY)

Motor z omlaag zodat deze op het papier staat. (BUSY)

Daarna x, y motors het pad laten volgen. (BUSY)

Programma onthoud positie en wacht op volgende opdracht (en z motor moet weer omhoog) (IDLE).

Als programma crasht of afgesloten wordt moet er opnieuw gecalibreerd worden. (UNINITIALIZED, IDLE)
*/