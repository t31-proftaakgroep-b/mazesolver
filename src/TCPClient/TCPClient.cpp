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
}

void TCPClient::SendMessage()
{
    
}

ClientState TCPClient::GetClientState() const
{
    return state;
}

void TCPClient::SetClientState(ClientState status)
{
    state = status;
}
