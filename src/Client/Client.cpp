#include "Client.h"

Client::Client(ICommunication* communication):
    communication(communication)
{
    
}

Client::~Client()
{
    
}

ICommunication* Client::GetCommunication()
{
    return communication;
}
