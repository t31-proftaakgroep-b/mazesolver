#pragma once

#include "../Interfaces/ICommunication.h"
#include "../Protocol.h"

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

class Client
{
    public:
        Client(ICommunication& communication);
        ~Client();
        virtual void GetCurrentState() = 0;

    private:
        ICommunication& communication;
        int connectFd;
        int socketFd;

};