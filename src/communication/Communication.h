#pragma once

#include <algorithm>
#include <stdint.h>
#include <string>
#include <stdlib.h>
#include <exception>
#include <iostream>
#include <vector>

#include "../Client/Client.h"
#include "../Interfaces/ICommunication.h"
#include "../Bricktype.h"

class Communication:ICommunication
{
    public:
        Communication(int socketFD);
        ~Communication();
        bool AcceptConnection();
        int CheckSocket();
        Bricktype GetBrickType();
        int GetNumberOfClients();
        void InitialiseSocket();
        std::string ReceiveMessage();
        std::string ReceiveMessage(int fd);
        bool SendMessage(std::string message);
        bool WaitForAck();
        int WaitForClient();

    private:
        Bricktype brickType;
        std::vector<int> fileDescriptors;
        std::string ipAddress;
        fd_set readFds;
        int socketFd;
        static const int SelectTimeout = 2;
        struct timeval timeout;
};
