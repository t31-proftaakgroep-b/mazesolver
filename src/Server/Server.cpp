#include "Server.h"
#include <iostream> //ewl

Server::Server() :
FileLocation("/tmp/server")
{
    InitialiseSocket();
}

Server::~Server()
{

}


void Server::InitialiseSocket()
{
    socketFd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketFd < 0)
    {
        perror("cannot create socket");
        exit(EXIT_FAILURE);
    }   

    struct sockaddr_in sa;
    memset(&sa, 0, sizeof sa);
    sa.sin_family = AF_INET;
    sa.sin_port = htons(PortNumber);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(socketFd, (struct sockaddr*)&sa, sizeof sa) < 0)
    {
        perror("bind failed");
        close(socketFd);
        exit(EXIT_FAILURE);
    }

    if (listen(socketFd, 10) < 0)
    {
        perror("listen failed");
        close(socketFd);
        exit(EXIT_FAILURE);
    }

    fileDescriptors.push_back(socketFd);
    
    //return connectFd;
}

std::string Server::ReceiveMessage(int fd)
{
    char buffer[BufferSize];
    int nrBytes = read(fd, buffer, BufferSize - 1);
    if (nrBytes > 0)
    {
        buffer[nrBytes] = '\0';      
        return buffer;
    }

    else if (nrBytes == 0)
    {
        //return "CLOSED";
        throw std::invalid_argument("Connection closed");
    }

    else if (nrBytes == -1)
    {
        //TODO: Throw exception
    }

    return "";
}


void Server::SendMessage(int fd, std::string message)
{
    size_t nrBytes = send(fd, message.c_str(), message.length(), 0);
    
    if (nrBytes != message.length())
    {
        //std::cout << "not everything is sent (" << nrBytes << "/" << text.length() << " bytes sent)\n";
    }
}

bool Server::AcceptConnection()
{
    int newFd = accept(socketFd, NULL, NULL);
    if (newFd < 0)
    {
        perror("accept failed");
        close(newFd);
        exit(EXIT_FAILURE);
    }
    fileDescriptors.push_back(newFd);
    return true;
}

int Server::checkConnection()
{
    int returnval = CheckSocket();
    if (returnval != socketFd)
    {
        returnval = 0;
    }
    return returnval;

}

int Server::GetAmountOfConnectedClients()
{
    return fileDescriptors.size() -1;
}

int Server::CheckSocket()
{
    timeout.tv_sec = SelectTimeout;
    timeout.tv_usec = 0;

    FD_ZERO(&readFds);
    

    for(unsigned int i = 0; i < fileDescriptors.size(); i++)
    {
        FD_SET(fileDescriptors[i], &readFds);
    }

    if (select(FD_SETSIZE, &readFds, NULL, NULL, &timeout) > 0)
    {
        for(unsigned int i = 0; i < fileDescriptors.size(); i++)
        {
            int set = FD_ISSET(fileDescriptors[i], &readFds);
            if(set > 0)
            {
                return fileDescriptors[i];
            }
        }

        //returnval = FD_ISSET(fd, &readFds);
    }
    return 0;
}

