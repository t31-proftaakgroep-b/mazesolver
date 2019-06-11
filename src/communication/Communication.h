#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdint.h>
#include <string>
#include <stdlib.h>
#include <exception>
#include <iostream>

#include "../Client/Client.h"
#include "../Interfaces/ICommunication.h"
#include "../Bricktype.h"

class Communication
{
    public:
        Communication(int socketFD);
        ~Communication();
        Bricktype GetBrickType();
        bool SendMessage(std::string message);
        std::string ReceiveMessage();
        Client* WaitForClient();
        bool WaitForAck();

    private:
        Bricktype brickType;
        int socketFd;
        std::string ipAddress;

};

#endif