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

void Plotter::PrintSolution()
{
    tcpClient.SendMessage("Maze has been plotted \n");
    std::cout << "Maze has been plotted" << std::endl;
}

ClientState Plotter::GetState()
{
    return tcpClient.GetClientState();
}
