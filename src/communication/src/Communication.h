#ifndef _COMMUNICATION_H_
#define _COMMUNICATION_H_

#include <iostream>
//#include <Structs.h>
#include <string.h>
#include <vector>
#include "PTSocket.h"
#include "Client.h"

class Communication
{
private:
    std::vector<Client*> Scanners;
    std::vector<Client*> Plotters;
    std::string IpAddress;
    PTSocket* Socket;
	COMMAND Command;
    BRICKTYPE Type; //Client var
    //std::string Message;

public:
	Communication(std::string IpAddress);
    Communication();
	~Communication();
	void StartListening();
	void Connect(std::string ip);
	void Disconnect(std::string ip);
	//static void SetType(BRICKTYPE type); //in device itseld
	COMMAND GetCommandReceived();
	void SendCommand(COMMAND command);
	//static bool IsConnected();
	Client* WaitForClient();
	//static int GetNumberOfClients();
	//static void Broadcast(std::string msg);
	//static Client* GetClient(int i);
	//static void PrintMessage(std::string msg);
};
#endif
