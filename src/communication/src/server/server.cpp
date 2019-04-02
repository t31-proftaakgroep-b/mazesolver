#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <csignal>
#include <string>
//#include "ev3dev.h"
#include "Communication.h"

//using namespace ev3dev;

Communication* com;
bool untilDoomsday = true;

int
main ()
{
  com = new Communication();
  while(untilDoomsday)
  {
    com->StartListening();
    com->WaitForClient();
    //Client* client = com->GetClient(0);  
    COMMAND command = com->GetCommandReceived();
    std::cout << command << std::endl;
  }

  
  std::cout << "end" << std::endl;
  delete com;
  return 0;
}