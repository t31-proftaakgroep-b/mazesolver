#ifndef SCANNERPROXY_H
#define SCANNERPROXY_H

#include <stdint.h>
#include <string>

class ScannerProxy
{
    public:
        ScannerProxy();
        void ScanMaze();
        bool Save(int fileSize);
        void SendFile(std::string fileName);

    private:

};

#endif