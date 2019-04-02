#ifndef CLIENT_H
#define CLIENT_H

#include "../Protocol.h"

#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unistd.h>

class Client
{
    public:
    Client();
    ~Client();
    //int Connect(std::string address);
    int InitialiseSocket(std::string address); 
    bool SendMessage(std::string message);
    std::string ReceiveMessage();
    void SendFile(std::string file, int fileSize);
    std::string ReceiveFile(std::string fileName, int fileSize);
    bool RequestSave(int fileSize);
    int GetFileSize(std::string fileName);

    bool Disconnect();

    private:
    const std::string AckMessage;
    const std::string NackMessage;
    const std::string FileLocation;

    bool WaitForAck();


    int connectFd;
    int socketFd;

};
    




#endif