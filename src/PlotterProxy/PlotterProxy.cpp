#include "PlotterProxy.h"

PlotterProxy::PlotterProxy(ICommunication* communication):Client(communication)
{

}

void PlotterProxy::GetState()
{
    communication.SendMessage(PlotterGetState);
}

void PlotterProxy::PrintSolution()
{
    communication.SendMessage(PlotterPrintSolution);
}

void PlotterProxy::ReceiveSolution()
{
    communication.SendMessage(PlotterReceiveSolution);
}


