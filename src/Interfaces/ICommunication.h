#ifndef ICOMMUNICATION_H
#define ICOMMUNICATION_H

#include <string>
#include "Client.h"

class ICommunication
{
    public:
    virtual ~ICommunication(){};
    virtual void SendMessage(std::string message) = 0;
    virtual std::string ReceiveMessage() = 0;
    virtual Client WaitForClient() = 0;
};

#endif