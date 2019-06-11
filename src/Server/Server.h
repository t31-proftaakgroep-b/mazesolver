#ifndef SERVER_H
#define SERVER_H

#include "../Protocol.h"

#include <algorithm>  
#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <sys/select.h>
#include <unistd.h>
#include <vector>

class Server
{  
    public:
    Server();
    
    //bool HandleMessage(int fd, std::string message);
    std::string ReceiveMessage(int fd);
    bool AcceptConnection();
    int checkConnection();
    int GetNumberOfConnectedClients();
    int CheckSocket();

    private:
    //SendMessage(std::string message);
    int socketFd;   // ------v
    int connectFd;  // these 2 needs to be changed. We shoud've created theses in the main and used them as parameters and returns instead of global variable
    const std::string FileLocation;
    fd_set readFds;
    std::vector<int> fileDescriptors;

    static const int SelectTimeout = 2;
    struct timeval timeout;
    void InitialiseSocket();
    std::string ReceiveMessage();
    void SendMessage(int fd, const std::string &message);
    bool WaitForAck();
};

#endif