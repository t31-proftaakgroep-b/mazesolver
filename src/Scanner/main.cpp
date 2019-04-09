#include "scanner.h"
#include <iostream>
#include <limits> 

static void showMenu( void )
{
  std::cout << ("\n\nScanner menu\n");
  std::cout << ("===============\n");
  std::cout << ("(1) Scan Maze\n");
  std::cout << ("(2) Disconnect\n");
  std::cout << ("(3) Exit\n");
  std::cout << ("Choice : ");
}

int main(void)
{
  Scanner* scanner = new Scanner();
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
        scanner->ScanMaze();
      }
      break;

      case '2':
      scanner->Disconnect();  
      //connect = 0;
      break;

      case '3':
      scanner->Disconnect();
      quit = true;
      delete scanner;
      break;

      default:
      std::cout << "\n\nI did not understand your choice (" << choice << ")" << std::endl;
      break;
    }
  }
  return 0;
}

