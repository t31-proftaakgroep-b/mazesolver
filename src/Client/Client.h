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
    bool Disconnect();
    int InitialiseSocket(std::string address); 
    std::string ReceiveMessage();
    bool SendMessage(std::string message);

    private:
    const std::string AckMessage;
    const std::string NackMessage;
    bool WaitForAck();


    int connectFd;
    int socketFd;

};
    

#endif