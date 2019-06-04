#include "TCPClient.h"

TCPClient::TCPClient()
{

}

TCPClient::~TCPClient()
{

}
    
void TCPClient::Connect()
{

}
        
void TCPClient::Disconnect()
{

}
        
void TCPClient::SendCurrentState()
{

}

std::string TCPClient::ReceiveMessage()
{
    std::string message = "";
    return message;
}

bool TCPClient::SendMessage(std::string message)
{
    bool returnValue = false;
    size_t nrBytes = send(socketFd, message.c_str(), message.length(), 0);
    if (nrBytes != message.length())
    {
        std::string errorMessage = "not everything is sent (" + nrBytes + '/' + message.length();
        errorMessage += " bytes sent)";
        perror(errorMessage.c_str());
    }

    return returnValue;
}

ClientState TCPClient::GetClientState() const
{
    return state;
}

void TCPClient::SetClientState(ClientState status)
{
    state = status;
}
