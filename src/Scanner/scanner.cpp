#include "scanner.h"

Scanner::Scanner():tcpClient("127.0.0.1")
{

}

Scanner::~Scanner()
{

}

void Scanner::Disconnect()
{
    tcpClient.Disconnect();
    //client.Disconnect();
}

void Scanner::ScanMaze()
{
    std::cout << "Maze has been scanned" << std::endl;
    tcpClient.SendMessage("Send a scanned maze! \n");
    //client.SendMessage("Send a scanned maze! \n");
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
