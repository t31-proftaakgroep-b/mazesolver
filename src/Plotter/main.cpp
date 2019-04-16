#include "plotter.h"
#include <iostream>
#include <limits> 

static void showMenu( void )
{
  std::cout << ("\n\nPlotter menu\n");
  std::cout << ("===============\n");
  std::cout << ("(1) Plot Maze\n");
  std::cout << ("(2) Disconnect\n");
  std::cout << ("(3) Exit\n");
  std::cout << ("Choice : ");
}

int main(void)
{
  Plotter plotter;
  //int socketFd;
  bool quit = false;
  //bool connect = 0;

  while (!quit)
  {
    char choice = '\0';
    showMenu();
    std::cin >> choice;
    std::cin.ignore(1000, '\n');

    switch (choice)
    {
      case '1':
      {
        plotter.PlotMaze();
      }
      break;

      case '2':
      plotter.Disconnect();  
      //connect = 0;
      break;

      case '3':
      plotter.Disconnect();
      quit = true;
      break;

      default:
      std::cout << "\n\nI did not understand your choice (" << choice << ")" << std::endl;
      break;
    }
  }
  return 0;
}

