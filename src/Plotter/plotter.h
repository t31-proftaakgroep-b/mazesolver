#ifndef PLOTTER_H
#define PLOTTER_H

#include "../Protocol.h"
#include "../ClientState.h"
#include "../Client/Client.h"

#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <sys/select.h>
#include <unistd.h>
#include <vector>

class Plotter
{  
    public:
        Plotter();
        ~Plotter();
    
        void Disconnect();
        ClientState GetState();
        void PlotMaze();
    
    private:
        Client client;
};

#endif