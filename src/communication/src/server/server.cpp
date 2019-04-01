#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <csignal>
#include <string>
//#include "ev3dev.h"
#include "Communication.h"

//using namespace ev3dev;

Communication* com;

int
main ()
{
  com = new Communication();
  char bla[] = "Hello, world?";
  com->WaitForClient();
  std::cout << "Number of clients: " << com->GetNumberOfClients() << std::endl;
  //com->Broadcast(msg);
  Client* client = com->GetClient(0);
  std::cout << "Host: " << client->GetHost() << std::endl;

  if(com->GetNumberOfClients()>0)
  {
    std::cout<< com->GetNumberOfClients() << " clients connected" <<std::endl;


    // if(msg2!=NULL)
    // {
    //   std::cout << "New message!" <<std::endl;
    //   com->PrintMessage(msg2);
    //     //std::cout << msg2->Command << std::endl;
    // }
    // std::cout << "Type: " << client->GetType() << std::endl;
    // std::cout << "Msg sent: " + client->SendMessage(msg) << std::endl;

    // msg2 = client->GetMessageReceived();
    // if(msg2!=NULL)
    // {
    //   std::cout << "New message!" <<std::endl;
    //   com->PrintMessage(msg2);
    //     //std::cout << msg2->Command << std::endl;
    // }
  }

  std::cout << "end" << std::endl;
  delete com;
  return 0;

}