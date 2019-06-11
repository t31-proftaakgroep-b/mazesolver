#include "Communication.h"
//All need to be implemented 
Communication::Communication(int socketFD)
{
	socketFd = socketFD;
}

Communication::~Communication()
{

}

Bricktype Communication::GetBrickType()
{
	return brickType;
}

bool Communication::SendMessage(std::string message)
{
    bool returnValue = false;
    size_t nrBytes = 0;
    while(nrBytes != message.length())
    {
        nrBytes = send(socketFd, message.c_str(), message.length(), 0);
    }
    returnValue = WaitForAck();

    return returnValue;
}

std::string Communication::ReceiveMessage()
{
	char buffer[BufferSize];
    int nrBytes = read(socketFd, buffer, BufferSize - 1);
    if (nrBytes >= 0)
    {
        buffer[nrBytes] = '\0';
        return buffer;
    }

    return "error occured";
}

Client* Communication::WaitForClient()
{
 	return NULL;
}


bool Communication::WaitForAck()
{
    std::string receivedMessage = ReceiveMessage();

    if(receivedMessage == AckMessage)
    {
        return true;
    }
    else if(receivedMessage == NackMessage)
    {
        return false;
    }
    else
    {
        //should throw error, will return false for now
        return false;
    }
}