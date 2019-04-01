#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <vector>
#include <iostream>
#include <Structs.h>
#include "PTSocket.h"


class Client
{
private:
    PTSocket* socket;
    BRICKTYPE type;

public:
	Client(PTSocket* socket);
    
    int SendMessage(COMMAND command);
    COMMAND GetMessageReceived();
	BRICKTYPE GetType();
    void Disconnect();
	~Client();
	std::string GetHost();
};
#endif