#pragma once

#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unistd.h>

#include "../ClientState.h"
#include "../Protocol.h"

class TCPClient
{  
    public:
        TCPClient(std::string address);
        ~TCPClient();
    
        bool Connect(std::string address);
        bool Disconnect();
        ClientState GetClientState() const;
        std::string ReceiveMessage();
        void SetClientState(ClientState status);
        void SendCurrentState();
        bool SendMessage(std::string message);
        bool WaitForAck();    
    
    private:
        std::string EnumToString(ClientState state);
        ClientState state;
        int socketFd;
        int connectFd;

};