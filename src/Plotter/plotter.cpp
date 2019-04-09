#include "Plotter.h"

Plotter::Plotter()
{
    client = new Client(); 
}

Plotter::~Plotter()
{

}

void Plotter::Disconnect()
{

}

void Plotter::PlotMaze()
{
    std::cout << "Maze has been plotted" << std::endl;
}