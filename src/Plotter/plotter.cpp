#include "plotter.h"

Plotter::Plotter():tcpClient("127.0.0.1")
{

}

Plotter::~Plotter()
{

}

void Plotter::Disconnect()
{
    tcpClient.Disconnect();
}

ClientState Plotter::GetState()
{
    return tcpClient.GetClientState();
}

void Plotter::HandleMessage()
{
    std::string message = tcpClient.ReceiveMessage();
    if(message == GetCurrentState)
    {
        GetState();
    }
    if(message == PlotterPrintSolution)
    {
        PrintSolution();
    }
    if(message == PlotterReceiveSolution)
    {
        tcpClient.SendMessage(AckMessage);
    }
}

void Plotter::PrintSolution()
{
    //I Believe here must come the package to send to the real plotter to print
    tcpClient.SendMessage("Maze has been plotted \n");
    std::cout << "Maze has been plotted" << std::endl;
}

void Plotter::ReceiveSolution()
{
    //communication.SendMessage(PlotterReceiveSolution);
}