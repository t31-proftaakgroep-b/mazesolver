#include <stdlib.h>
#include <string.h>
#include "Communication.h"
#include <stdexcept>

Communication::Communication(std::string IpAddress) //Client
{
    Socket = new PTSocket(IpAddress, 5000);
    socketFd = Socket->Connect(IpAddress);
    this->IpAddress = IpAddress;
}

Communication::Communication() //server
{
    //Type = NotInitialyzed;
    Socket = new PTSocket(5000);

}

Communication::~Communication()
{
    uint8_t i = 0;
    for(; i < Scanners.size(); i++)
    {
        delete Scanners[i];
        Scanners[i] = NULL;
    }

    i = 0;
    for(; i < Plotters.size(); i++)
    {
        delete Plotters[i];
        Plotters[i] = NULL;
    }
    delete Socket;
    Socket = NULL;
}

void Communication::StartListening()
{
    std::cout << "listening" << std::endl;
    Socket->Listen();
}

void Communication::Connect(std::string ip)
{
    Socket->Connect(ip);
}

void Communication::Disconnect(std::string ip)
{
    Socket->Disconnect(ip); //TODO add to socket
}

// void Communication::SetType(BRICKTYPE type)
// {
//     Type = type;
// }

COMMAND Communication::GetCommandReceived()
{
	try
	{
		int command = Socket->Receive();
        // if(length!=sizeof(buffer))
        // {
        //     std::cout <<"Message is the wrong length: " << length << std::endl;
        //     //todo throw exception
        // }
        // else
        // {
        return (COMMAND)command;
        // }
    }
    catch(std::exception& ex)
    {
      printf("Error while receiving message.\n");
    }
    return NACK;
    //edit
}

void Communication::SendCommand(COMMAND command)
{
	Socket->Send(command);
}

// bool Communication::IsConnected()
// {
//     return true;
// }

Client* Communication::WaitForClient()
{
    PTSocket* newSocket = Socket->Accept();
    std::cout << "waiting for client socket: " << newSocket << std::endl;
    if(newSocket != NULL)
    {
        Client* client = new Client(newSocket);
        //getType
        Scanners.push_back(client);
        return client;
    }
    return NULL;
}


// int Communication::GetNumberOfClients()
// {
//     return Clients.size();
// }

// void Communication::Broadcast(MESSAGE* msg)
// {
//     uint8_t i = 0;
//     for(; i < Clients.size(); i++)
//     {
//         Clients[i]->SendMessage(msg);
//     }
// }

// Client* Communication::GetClient(int i)
// {
//     if((unsigned int)i>Clients.size())
//     {
//         return NULL;
//     }
//     return Clients[i];
// }