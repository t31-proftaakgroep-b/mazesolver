#ifndef PLOTTERPROXY_H
#define PLOTTERPROXY_H

#include <stdint.h>
#include <string>

class PlotterProxy
{
    public:
        PlotterProxy();
        void PrintSolution();
        
    private:
        void ReceiveSolution();
};

#endif