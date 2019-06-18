#include "Server.h"

#include <iostream>

/*int main(void)
{
    Server server;
    
    while(true)
    {
        server.Heartbeat();
    }
    return 0;
}*/

static void showMenu(void)
{
    std::cout << ("\n\nServer menu\n");
    std::cout << ("===============\n");
    std::cout << ("(1) Get Scanners\n");
    std::cout << ("(2) Get Plotters\n");
    std::cout << ("(3) Scan Maze\n");
    std::cout << ("(4) Plot Maze\n");
    std::cout << ("(5) Show Scanned Maze\n");
    std::cout << ("(6) Show Solution\n");
    std::cout << ("(7) Exit\n");
    std::cout << ("Choice : ");
}

int main(void)
{
    Server server;
    bool quit = false;

    while (!quit)
    {
        char choice = '\0';
        showMenu();
        std::cin >> choice;
        std::cin.ignore(1000, '\n');

        server.Heartbeat();

        switch (choice)
        {
        case '1':
        {
            //server.GetNumberOfConnectedClients();
            std::cout << server.GetNumberOfConnectedClients() << std::endl;
            break;
        }
        case '2':
        {
            //server.GetNumberOfConnectedClients();
            std::cout << server.GetNumberOfConnectedClients() << std::endl;
            break;
        }
        case '3':
        {
            std::cout << "Select scanner" << std::endl;
            char selected = '\0';
            std::cin >> selected;
            std::cin.ignore(1000, '\n');
            server.ScanRequest(selected);
            break;
        }
        case '4':
        {
            std::cout << "Select plotter" << std::endl;
            char selected = '\0';
            std::cin >> selected;
            std::cin.ignore(1000, '\n');
            server.PlotRequest(selected);
            break;
        }
        case '5':
        {
            std::cout << "Select Maze" << std::endl;
            char selected = '\0';
            std::cin >> selected;
            std::cin.ignore(1000, '\n');
            //TODO
            try
            {
              server.RequestMaze();
            }
            catch(const std::invalid_argument &e)
            {
              std::cerr << e.what() << '\n';
            }
            
            std::cout << server.GetMazeVisual(0);
            break;
        } 
        case '6':
        {
            std::cout << "Select Maze" << std::endl;
            char selected = '\0';
            std::cin >> selected;
            std::cin.ignore(1000, '\n');

            std::vector<std::string> outputStrings = server.PrintSolution(0);
            std::cout << "Solution gotten succesfully\n";

            for (std::vector<std::string>::size_type i = 0; i < outputStrings.size(); i++)
            {
                std::cout << outputStrings[i];
            }

            break;
        }
        case '7':
        {
            quit = true;
            break;
        }
        default:
        {
            std::cout << "\n\nI did not understand your choice (" << choice << ")" << std::endl;
            break;
        }
        }
    }
    return 0;
}
