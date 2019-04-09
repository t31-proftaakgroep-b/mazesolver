#include "Client.h"

Client::Client():
AckMessage("ACK"),
NackMessage("NACK")
{
    InitialiseSocket("127.0.0.1");
}

Client::~Client()
{
    
}

bool Client::Disconnect()
{
    if (shutdown(socketFd, SHUT_RDWR) < 0)
    {
        perror("shutdown failed");
        close(socketFd);
        exit(EXIT_FAILURE);
        return true;
    }
    close(socketFd);
    return true;
}

int Client::InitialiseSocket(std::string address)
{
    if (address.empty())
    {
        perror("No adress is given");
        exit(EXIT_FAILURE);
    }

    socketFd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketFd == -1)
    {
        perror("cannot create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in sa;
    memset(&sa, 0, sizeof sa);
    sa.sin_family = AF_INET;
    sa.sin_port = htons(PortNumber);

    int result = inet_pton(AF_INET, "127.0.0.1", &sa.sin_addr);
    if (result != 1)
    {
        perror("could not convert ip address to network address structure");
        exit(EXIT_FAILURE);
    }
    else 
    {
        connectFd = connect(socketFd, (struct sockaddr*)&sa, sizeof sa);
        if (connectFd < 0)
        {
            perror("connect failed");
            close(socketFd);
            exit(EXIT_FAILURE);
        }

        return result;
    }
}

std::string Client::ReceiveMessage()
{
    const int BufferSize = 100;
    char buffer[BufferSize];
    int nrBytes = read(socketFd, buffer, BufferSize - 1); //connectFd not initialized!!
    if (nrBytes >= 0)
    {
        buffer[nrBytes] = '\0';
        //sleep (1);
        return buffer;
    }
    sleep (1);

    return "error occured";
}

bool Client::SendMessage(std::string message)
{
    bool returnValue = false;
    size_t nrBytes = send(socketFd, message.c_str(), message.length(), 0);
    if (nrBytes != message.length())
    {
        std::string errorMessage = "not everything is sent (" + nrBytes + '/' + message.length();
        errorMessage += " bytes sent)";
        perror(errorMessage.c_str());
    }
    /*bool ackReceived = false;
    while(!ackReceived)
    {
        std::string receivedMessage = ReceiveMessage();

        if(red ‘Connect’
         scanner->Connect(&socketFd);
                  ^ceivedMessage == "ACK")
        {d ‘Connect’
         scanner->Connect(&socketFd);
                  ^
            ad ‘Connect’
         scanner->Connect(&socketFd);
                  ^ckReceived = true;
            rd ‘Connect’
         scanner->Connect(&socketFd);
                  ^eturnValue = true;
        }
    }*/
    return returnValue;
}

bool Client::WaitForAck()
{
    std::string receivedMessage = ReceiveMessage();

    if(receivedMessage == "ACK")
    {
        return true;
    }
    else if(receivedMessage == "NACK")
    {
        return false;
    }
    else
    {
        //should throw error, will return false for now
        return false;
    }
}