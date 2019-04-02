#ifndef SERVER_H
#define SERVER_H

#include "../Protocol.h"
#include "tinyxml2.h"

#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <sys/select.h>
#include <unistd.h>
#include <vector>



class Server
{  
    public:
    Server();
    ~Server();
       
    void InitialiseSocket();
    bool HandleMessage(int fd, std::string message);
    std::string ReceiveMessage(int fd);
    bool Connect();
    int checkConnection();
    int GetAmountOfConnectedClients();
    int CheckSocket();
    std::string ReceiveFile(int fd, int fileSize);

    private:
    //SendMessage(std::string message);
    int socketFd;   // ------v
    int connectFd;  // these 2 needs to be changed. We shoud've created theses in the main and used them as parameters and returns instead of global variable
    const std::string AckMessage;
    const std::string NackMessage;
    const std::string FileLocation;
    fd_set readFds;
    std::vector<int> fileDescriptors;

    static const int SelectTimeout = 2;
    struct timeval timeout;
    void SendMessage(int fd, std::string message);
    bool CheckKey(std::string key);
    void SendFile(int fd, std::string key);
    void DeleteFile(int fd, std::string key);
    std::string GetRandomKey();
    std::string GenerateRandomString();

};

#endif