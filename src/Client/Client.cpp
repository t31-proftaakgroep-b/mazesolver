#include "Client.h"
//Some must be deleted here, since we must use communication
Client::Client()
{
    //Address = "127.0.0.1";
    //InitialiseSocket(Address);//niet doen!
}

Client::~Client()
{
    
}

/* bool Client::Disconnect()
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
}*/

/* bool Client::InitialiseSocket(std::string address)
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
}*/

/*bool Client::ReceiveMessage(std::string& messageReceived)
{
    char buffer[BufferSize];
    int nrBytes = read(socketFd, buffer, BufferSize - 1);
    if (nrBytes >= 0)
    {
        buffer[nrBytes] = '\0';
        messageReceived = buffer;
        return true;
    }

    return false;
}*/

/* std::string Client::ReceiveMessage()
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

bool Client::SendMessage(std::string message)
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

bool Client::WaitForAck()
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
}*/