#include "plotter.h"

Plotter::Plotter():client("127.0.0.1")
{

}

Plotter::~Plotter()
{

}

void Plotter::Disconnect()
{
    client.Disconnect();
}

void Plotter::PlotMaze()
{
    std::cout << "Maze has been plotted" << std::endl;
}