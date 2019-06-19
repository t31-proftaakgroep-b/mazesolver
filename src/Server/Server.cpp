#include "Server.h"

Server::Server()
{
    communication = new Communication(socketFd);
    communication->InitialiseSocket();
    mazeSolver = new MazeSolver();
}

Server::~Server()
{
    delete communication;
    communication = NULL;
    delete mazeSolver;
    mazeSolver = NULL;
}

int Server::GetNumberOfConnectedClients()
{
    return communication->GetNumberOfClients();
}

void Server::Heartbeat()
{
    //std::cout << "nrSockets: " << nrSockets << std::endl;
    std::cout << "connected clients: " << GetNumberOfConnectedClients() << std::endl;
    int nrSockets = communication->WaitForClient();
    if (nrSockets < 0) // error situation
    {
        perror("error from calling socket");
    }
    else if (nrSockets == 0) // timeout
    {
        std::cout << "still listening\n";
    }
    else if (nrSockets > 0)
    {
        std::cout << "going to connect" << std::endl;
        communication->AcceptConnection();
    }   

    // if (GetNumberOfConnectedClients() > 0)
    // {
    //     std::string message = "";
    //     int activeSocketFd = communication->CheckSocket();
    //     if (activeSocketFd > 0)
    //     {
    //         try
    //         {
    //             message = communication->ReceiveMessage(activeSocketFd);
    //         }
    //         catch (const std::exception &e)
    //         {
    //             std::cerr << e.what() << '\n';
    //             //break;
    //         }

    //         if (!message.empty())
    //         {
    //             std::cout << message;
    //         }
    //     }
    // }
}
void Server::PlotRequest(int number)
{
    SendMessage(number, PlotterReceiveSolution);
    std::string confirm = communication->ReceiveMessage(number);
    if (confirm == AckMessage)
    {
        SendMessage(number, PlotterPrintSolution); //PlotterPrintSolution is default, moet hier niet de oplossing in?
    }
}

void Server::RequestMaze()
{
    //TODO get een maze, voor nu hard coded om te testen
    
    std::vector<MazeField> mazeFields;

    mazeFields.push_back({0, 0, Empty});
    mazeFields.push_back({1, 0, Empty});
    mazeFields.push_back({2, 0, Start});
    mazeFields.push_back({3, 0, Wall});
    mazeFields.push_back({4, 0, Empty});
    mazeFields.push_back({5, 0, Empty});
    
    mazeFields.push_back({0, 1, Empty});
    mazeFields.push_back({1, 1, Wall});
    mazeFields.push_back({2, 1, Empty});
    mazeFields.push_back({3, 1, Wall});
    mazeFields.push_back({4, 1, Wall});
    mazeFields.push_back({5, 1, Empty});

    mazeFields.push_back({0, 2, Empty});
    mazeFields.push_back({1, 2, Wall});
    mazeFields.push_back({2, 2, Empty});
    mazeFields.push_back({3, 2, Empty});
    mazeFields.push_back({4, 2, Empty});
    mazeFields.push_back({5, 2, Empty});

    mazeFields.push_back({0, 3, Wall});
    mazeFields.push_back({1, 3, Wall});
    mazeFields.push_back({2, 3, Wall});
    mazeFields.push_back({3, 3, Wall});
    mazeFields.push_back({4, 3, Wall});
    mazeFields.push_back({5, 3, Empty});

    mazeFields.push_back({0, 4, Empty});
    mazeFields.push_back({1, 4, Empty});
    mazeFields.push_back({2, 4, Empty});
    mazeFields.push_back({3, 4, Empty});
    mazeFields.push_back({4, 4, Empty});
    mazeFields.push_back({5, 4, Empty});

    mazeFields.push_back({0, 5, Wall});
    mazeFields.push_back({1, 5, Wall});
    mazeFields.push_back({2, 5, Empty});
    mazeFields.push_back({3, 5, Wall});
    mazeFields.push_back({4, 5, Wall});
    mazeFields.push_back({5, 5, Empty});

    mazeFields.push_back({0, 6, Empty});
    mazeFields.push_back({1, 6, Empty});
    mazeFields.push_back({2, 6, Empty});
    mazeFields.push_back({3, 6, Finish});
    mazeFields.push_back({4, 6, Wall});
    mazeFields.push_back({5, 6, Empty});

    Maze maze(mazeFields);

    scannedMazes.push_back(maze);
}

std::string Server::GetMazeVisual(int index)
{  
    if(scannedMazes.size() > 0)
    {
        return scannedMazes[index].GetMazeVisual();
    }
    else
    {
        return "Maze not found.";
    }
}

std::vector<std::string> Server::PrintSolution(int index)
{    
    return mazeSolver->SolveMaze(scannedMazes[index]).GetInstructionStrings();
}

void Server::ScanRequest(int number)
{
    SendMessage(number, ScannerScanMaze);
}

void Server::SendMessage(int fd, const std::string &message)
{
    size_t nrBytes = 0;
    while (nrBytes != message.length())
    {
        nrBytes = send(socketFd, message.c_str(), message.length(), 0);
    }
}

void Server::SendSolution(int number)
{
    SendMessage(number, "SOLUTION"); //Solution adding
}

