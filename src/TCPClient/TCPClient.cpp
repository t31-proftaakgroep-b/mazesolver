#include "TCPClient.h"

TCPClient::TCPClient(std::string address)
{
    Connect(address);
}

TCPClient::~TCPClient()
{

}

bool TCPClient::Connect(std::string address)
{
    if (address.empty())
    {
        perror("No adress is given");
        return false;
    }

    socketFd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketFd == -1)
    {
        perror("cannot create socket");
        return false;
    }

    struct sockaddr_in sa;
    memset(&sa, 0, sizeof sa);
    sa.sin_family = AF_INET;
    sa.sin_port = htons(PortNumber);

    int result = inet_pton(AF_INET, address.c_str(), &sa.sin_addr);
    if (result != 1)
    {
        perror("could not convert ip address to network address structure");
        return false;
    }
    else 
    {
        connectFd = connect(socketFd, (struct sockaddr*)&sa, sizeof sa);
        if (connectFd < 0)
        {
            perror("connect failed");
            close(socketFd);
            return false;
        }
        return result;
    }
    return false;
}
        
bool TCPClient::Disconnect()
{
    if (shutdown(socketFd, SHUT_RDWR) < 0)
    {
        perror("shutdown failed");
        close(socketFd);
        //TODO throw exception
        return false;
    }
    close(socketFd);
    return true;
}
        
void TCPClient::SendCurrentState()
{
    std::string messageToSend = EnumToString(state);
    SendMessage(messageToSend);
}

std::string TCPClient::ReceiveMessage()
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


bool TCPClient::SendMessage(std::string message)
{
    bool returnValue = false;
    size_t nrBytes = 0;
    while(nrBytes != message.length())
    {
        nrBytes = send(socketFd, message.c_str(), message.length(), 0);
    }
    //returnValue = WaitForAck();

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

bool TCPClient::WaitForAck()
{
    std::string receivedMessage = ReceiveMessage();

    const char * recvMSG = receivedMessage.c_str();
    const char * ACKMSG = AckMessage.c_str();
    const char * NACKMSG = NackMessage.c_str();
    if(strcmp(recvMSG, ACKMSG) == 0)
    {
        return true;
    }
    else if(strcmp(recvMSG, NACKMSG) == 0)
    {
        return false;
    }
    else
    {
        //should throw error, will return false for now
        return false;
    }
}

std::string TCPClient::EnumToString(ClientState state)
{
    switch(state)
    {
        case Idle: return "Idle";
        case Busy: return "Busy";
        case Done: return "Done";
    }
    return "an unknown error occurred";
}

