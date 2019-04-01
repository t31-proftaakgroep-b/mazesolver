#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <csignal>
#include <stdexcept>

#include "ev3dev.h"
#include "Communication.h"

using namespace ev3dev;

Communication* com;




/*TYPE type;  
    uint16_t ModuleID;
    uint16_t RGBOrColor;
    RGBCOLOR RGBValue;
    uint16_t Color;
    SendingCommandOrReturnValue CommandOrResponse;
    std::string Command;
    std::string ReturnValue;*/
int
main ()
{
  try
  {
    com = new Communication("127.0.0.1");
    MESSAGE* msg = new MESSAGE();
    msg->type=SensorBrick;
    char bla[] = "Hello, world!";
    msg->Color = 38;
    strcpy(msg->ReturnValue, bla);
    com->SendMessage(msg);
    MESSAGE* msg2;

    msg2 = com->GetMessageReceived();
    if(msg2!=NULL)
    {
      std::cout << "New message!" <<std::endl;
      com->PrintMessage(msg2);
            com->SendMessage(msg);

        //std::cout << msg2->Command << std::endl;
    }
  }catch(std::runtime_error e)
  {
    std::cout<<"error" << std::endl;
  }

  // while(true)
  // {

  usleep(10000000);

  // }
  return 0;

}










