#pragma once

#include <string>
#include "../Client/Client.h"

class ICommunication
{
    public:
    virtual ~ICommunication(){};
    virtual bool SendMessage(std::string message) = 0;
    virtual std::string ReceiveMessage() = 0;
    virtual int WaitForClient() = 0;
};
