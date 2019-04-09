#ifndef SCANNER_H
#define SCANNER_H

#include "../Client/Client.h"
#include "../Protocol.h"

#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <sys/select.h>
#include <unistd.h>
#include <vector>


class Scanner
{
    public:
        Scanner();
        ~Scanner();

        void Disconnect();
        void ScanMaze();
    
    private:
        Client* client;

};

#endif