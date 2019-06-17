#pragma once

//#include "../Client/Client.h"
#include "../TCPClient/TCPClient.h"
#include "../ClientState.h"
#include "../Protocol.h"

#include <arpa/inet.h>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <sys/select.h>
#include <thread>
#include <unistd.h>
#include <vector>

class Scanner
{
    public:
        Scanner();
        ~Scanner();

        void Disconnect();
        ClientState GetState();
        void HandleMessage();
        bool Save(int fileSize);
        void ScanMaze();
        void SendFile(std::string fileName);
        void SendState();

    private:
        TCPClient tcpClient;
        ClientState state;

};