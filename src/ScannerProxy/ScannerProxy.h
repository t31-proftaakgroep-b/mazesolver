#pragma once

#include "../Client/Client.h"

#include <stdint.h>
#include <string>

class ScannerProxy:Client
{
    public:
        ScannerProxy(ICommunication* communication);
        void ScanMaze();
        bool Save(int fileSize);
        void SendFile(std::string fileName);

    private:

};
