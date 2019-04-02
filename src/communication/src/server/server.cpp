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
  com->WaitForClient();
  //Client* client = com->GetClient(0);
  

  std::cout << "end" << std::endl;
  delete com;
  return 0;
}