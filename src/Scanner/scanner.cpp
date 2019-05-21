#include "scanner.h"

Scanner::Scanner():client("127.0.0.1")
{

}

Scanner::~Scanner()
{

}

void Scanner::Disconnect()
{
    client.Disconnect();
}

void Scanner::ScanMaze()
{
    client.SendMessage("Send a scanned maze! \n");
}

ClientState Scanner::GetState()
{
    return tcpClient.GetClientState();
}
        
bool Scanner::Save(int fileSize)
{
    return false;
}
               
void Scanner::SendFile(std::string fileName)
{

}
