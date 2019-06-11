#include "Communication.h"

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