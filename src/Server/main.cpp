#include "Server.h"

#include <iostream>

int main(void)
{
    Server server;
    //bool connected = false;
    int nrSockets = 0;
    

    while(true)
    {
        //std::cout << "nrSockets: " << nrSockets << std::endl;

      // dit is niet nrSockets, maar socketFd, de socket waarop je aan het listenen bent.
        nrSockets = server.checkConnection();
        std::cout << "connected clients: " << server.GetNumberOfConnectedClients() << std::endl;

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
            server.AcceptConnection();
        }

        // Het lijkt erop dat deze functie een stuk communicatie en
        // socket handling doet.  Het lijkt er ook op dat classe
        // Server een ander stuk doet. Hoe hebben jullie de
        // verantwoordelijkheden eigenlijk verdeeld?
        if (server.GetNumberOfConnectedClients() > 0)
        {
            std::string message = "";
            int activeSocketFd = server.CheckSocket();
            // Als een client op precies het goed (of foute) moment
            // connect, dan geldt dat activeSocketFd == socketFd, het
            // socket waarop je aan het luisteren bent voor
            // connecties. In dat geval gaat ReceiveMessage(),
            // hieronder, waarschijnlijk niet goed.
            if (activeSocketFd > 0)
            {
                try
                {
                    message = server.ReceiveMessage(activeSocketFd);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                    break;
                }

                if (!message.empty())
                {
                    std::cout << message;
                }
            }
        }       
        
    }
    
    return 0;
}
