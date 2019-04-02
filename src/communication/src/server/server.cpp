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
Client* client;

int
main ()
{
  com = new Communication();
  while(untilDoomsday)
  {
    com->StartListening();
    client = com->WaitForClient();
    //Client* client = com->GetClient(0);
    COMMAND command = client->GetMessageReceived();
    std::cout << command << std::endl;
  }

  
  std::cout << "end" << std::endl;
  delete com;
  return 0;
}