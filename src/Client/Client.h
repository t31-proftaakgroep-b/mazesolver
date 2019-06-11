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
    Client(std::string Address);
    ~Client();
    bool Disconnect();
    bool InitialiseSocket(std::string address);
    std::string ReceiveMessage();
    bool ReceiveMessage(std::string& receivedMessage);
    bool SendMessage(std::string message);

    private:
    bool WaitForAck();
    std::string Address;

    int connectFd;
    int socketFd;

};
    

#endif