#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <csignal>
#include <stdexcept>

//#include "ev3dev.h"
#include "Communication.h"

//using namespace ev3dev;

Communication* com;




int
main ()
{
  try
  {
    com = new Communication("127.0.0.1");
    //MESSAGE* msg = new MESSAGE();
    //BRICKTYPE type;
    //char bla[] = "Hello, world!";


  }catch(std::runtime_error e)
  {
    std::cout<<"error" << std::endl;
  }

  // while(true)
  // {

  //usleep(10000000);

  // }
  return 0;

}










