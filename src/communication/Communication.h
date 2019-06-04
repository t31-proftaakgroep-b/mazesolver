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
        Communication(std::string ip, int* socketFD);
        ~Communication();
        Bricktype GetBrickType();
        void SendMessage(std::string message);
        std::string ReceiveMessage();
        Client* WaitForClient();

    private:
        Bricktype brickType;

};

#endif