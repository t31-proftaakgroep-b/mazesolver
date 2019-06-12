#include "Server.h"

Server::Server()
{
    communication = new Communication(socketFd);
    communication->InitialiseSocket();
}

Server::~Server()
{
    delete communication;
    communication = NULL;
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

    if (GetNumberOfConnectedClients() > 0)
    {
        std::string message = "";
        int activeSocketFd = communication->CheckSocket();
        if (activeSocketFd > 0)
        {
            try
            {
                message = communication->ReceiveMessage(activeSocketFd);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
                //break;
            }

            if (!message.empty())
            {
                std::cout << message;
            }
        }
    }
}

void Server::SendMessage(int fd, const std::string &message)
{
    size_t nrBytes = 0;
    while (nrBytes != message.length())
    {
        nrBytes = send(socketFd, message.c_str(), message.length(), 0);
    }
}
