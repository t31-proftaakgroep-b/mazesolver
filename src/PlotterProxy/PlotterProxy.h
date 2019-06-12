#pragma once

#include "../Client/Client.h"

#include <stdint.h>
#include <string>

class PlotterProxy : Client
{
    public:
        PlotterProxy(ICommunication* communication);
        void GetState();
        void PrintSolution();
        
    private:
        void ReceiveSolution();
};