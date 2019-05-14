#ifndef ICOMMUNICATION_H
#define ICOMMUNICATION_H

class ICommunication
{
    public virtual ICommunication(){};

    virtual void SendMessage(std::String message);
    virtual std::String ReceiveMessage();
    virtual Client* WaitForClient();
};

#endif