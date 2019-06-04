#include "Communication.h"

/*Communication::Communication(PTSocket* socket)
{
	this->socket = socket;
	type = NotInitialyzed;
	//GetMessageReceived();
}		

void Communication::SendMessage(COMMAND command)
{
	Send(command);
}

std::string Communication::GetMessageReceived()
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

Bricktype Communication::GetType()
{
	return type;
}

Communication::Disconnect()
{

}

Communication::~Client()
{
	
}

Communication::GetHost()
{
	return socket->GetHost();
}*/

//Don't know what this above means but it is shit

Communication::Communication(std::string ip, int* socketFD)
{

}

Communication::~Communication()
{

}

Bricktype Communication::GetBrickType()
{
	return brickType;
}

void Communication::SendMessage(std::string message)
{

}

std::string Communication::ReceiveMessage()
{
	return NULL;
}

Client* Communication::WaitForClient()
{
 	return NULL;
}