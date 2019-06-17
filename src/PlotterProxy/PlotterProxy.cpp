#include "PlotterProxy.h"

PlotterProxy::PlotterProxy(ICommunication* communication):Client(communication)
{
}

void PlotterProxy::GetCurrentState()
{

}

void PlotterProxy::GetState()
{
    //GetCommunication()->SendMessage("Idle");
}

void PlotterProxy::PrintSolution()
{
    GetCommunication()->SendMessage(PlotterPrintSolution);
}

void PlotterProxy::ReceiveSolution()
{
    GetCommunication()->SendMessage(PlotterReceiveSolution);
}




