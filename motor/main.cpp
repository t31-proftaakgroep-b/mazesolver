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

int main()
{
    // Motor* MotorY = new Motor("outA", 4600, 'Y');
    Motor* MotorX = new Motor("outB", 2600, 'X');	
	// Motor* MotorZ = new Motor("outC", 1000, 'Z');
    
    std::cout << MotorX->getMaxDistance() << std::endl;
    MotorX->setSpeed(45);
    MotorX->setPosition(4600);
    MotorX->moveToPosition(1300);
	std::cout<<"Motor done"<<std::endl;

    return 0;
}