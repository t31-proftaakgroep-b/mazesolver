#include <stdlib.h>
#include <string.h>
#include <exception>
#include <iostream>

#include "Client.h"



Client::Client(PTSocket* socket)
{
	this->socket = socket;
	type = NotInitialyzed;
	//GetMessageReceived();
}		

int Client::SendMessage(COMMAND command)
{
	return socket->Send(command);
}

COMMAND Client::GetMessageReceived()
{
	int command;
	try
	{
		command = socket->Receive();
		if(type==NotInitialyzed)
		{
			type = Scanner; //->type; TODO get type
		}
		return (COMMAND)command;
	}
	catch(std::exception& ex)
	{
		std::cout <<"Error while receiving message." << std::endl;
	}
	return NACK;
}

BRICKTYPE Client::GetType()
{
	return type;
}

void Client::Disconnect()
{

}

Client::~Client()
{
	
}

std::string Client::GetHost()
{
	return socket->GetHost();
}