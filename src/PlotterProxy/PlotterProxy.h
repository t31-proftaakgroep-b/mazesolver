#pragma once

#include "../Client/Client.h"
#include "../ClientState.h"
#include "../Protocol.h"

#include <stdint.h>
#include <string>

class PlotterProxy : Client
{
    public:
        PlotterProxy(ICommunication* communication);
        void GetCurrentState();
        void GetState();
        void PrintSolution();

        
    private:
        void ReceiveSolution();
};