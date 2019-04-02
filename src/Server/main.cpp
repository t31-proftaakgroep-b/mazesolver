#include "Server.h"

#include <iostream>

int main(void)
{
    Server* server = new Server();
    server->InitialiseSocket();
    //bool connected = false;
    int nrSockets = 0;
    

    while(true)
    {
        //std::cout << "nrSockets: " << nrSockets << std::endl;
        nrSockets = server->checkConnection();
        std::cout << "connected clients: " << server->GetAmountOfConnectedClients() << std::endl;

        if (nrSockets < 0) // error situation
        {
            perror("error from calling socket");
        }
        else if (nrSockets == 0) // timeout
        {
            std::cout << "still listening\n";
        }
        
        else if (nrSockets > 0)
        {
            std::cout << "going to connect" << std::endl;
            server->Connect();
        }

        if (server->GetAmountOfConnectedClients() > 0)
        {
            std::string message = "";
            int activeSocketFd = server->CheckSocket();
            if (activeSocketFd > 0)
            {
                try
                {
                    message = server->ReceiveMessage(activeSocketFd);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }

                if (!message.empty())
                {
                    if(!server->HandleMessage(activeSocketFd, message))
                    {
                        std::cout << "Error Parsing Message";
                    }
                }
            }
        }       
        
    }
    delete server;
    server = NULL;
    return 0;
}