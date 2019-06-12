#pragma once

#include "../Protocol.h"
#include "../communication/Communication.h"

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
        ~Server();
        int GetNumberOfConnectedClients();
        void Heartbeat();

    private:
        Communication* communication;
        int socketFd;   // ------v
        int connectFd;  // these 2 needs to be changed. We shoud've created theses in the main and used them as parameters and returns instead of global variable
        const std::string FileLocation = "/tmp/server";

        //std::string ReceiveMessage();
        void SendMessage(int fd, const std::string &message);
        //bool WaitForAck();

};
