#pragma once

#include "../Protocol.h"
#include "../communication/Communication.h"
#include "../Maze/Maze.h"
#include "../MazeSolver/MazeSolver.h"
#include "../Solution/Solution.h"

#include <algorithm>  
#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <sys/select.h>
#include <unistd.h>
#include <vector>

class Server
{  
    public:
        Server();
        ~Server();
        int GetNumberOfConnectedClients();
        void Heartbeat();
        void PlotRequest(int number);
        std::vector<std::string> PrintSolution(int index);
        void RequestMaze();
        std::string GetMazeVisual(int index);
        void ScanRequest(int number);
        void SendMessage(int fd, const std::string &message);
        void SendSolution(int number);

    private:
        Communication* communication;
        MazeSolver* mazeSolver;

        int socketFd;   // ------v
        int connectFd;  // these 2 needs to be changed. We shoud've created theses in the main and used them as parameters and returns instead of global variable
        const std::string FileLocation = "/tmp/server";

        std::vector<Maze> scannedMazes;

        //std::string ReceiveMessage();
        //bool WaitForAck();

};
