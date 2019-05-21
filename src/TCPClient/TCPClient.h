#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <stdint.h>
#include <string>
#include "../ClientState.h"

class TCPClient
{  
    public:
        TCPClient();
        ~TCPClient();
    
        void Connect();
        void Disconnect();
        void SendCurrentState();
        std::string ReceiveMessage();
        void SendMessage();

        ClientState GetClientState() const;
        void SetClientState(ClientState status);
    
    private:
        ClientState state;
};


#endif