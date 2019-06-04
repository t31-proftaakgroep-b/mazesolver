#ifndef TCPCLIENT_H
#define TCPCLIENT_H

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
        TCPClient();
        ~TCPClient();
    
        void Connect();
        void Disconnect();
        void SendCurrentState();
        std::string ReceiveMessage();
        bool SendMessage(std::string message);

        ClientState GetClientState() const;
        void SetClientState(ClientState status);
    
    private:
        ClientState state;
        int socketFd;
};


#endif