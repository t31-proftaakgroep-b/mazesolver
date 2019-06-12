#include "Server.h"

#include <iostream>

int main(void)
{
    Server server;
    
    while(true)
    {
        server.Heartbeat();
    }
    return 0;
}