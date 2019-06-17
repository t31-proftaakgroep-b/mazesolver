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
}

ClientState Scanner::GetState()
{
    return tcpClient.GetClientState();
}

void Scanner::HandleMessage()
{
    std::string message = tcpClient.ReceiveMessage();
    if(message == ScannerScanMaze)
    {
        ScanMaze();
    }
    if(message == ScannerSave)
    {
        Save(250);
    }
    if(message == ScannerSendFile)
    {
        SendFile("");
    }
}

bool Scanner::Save(int fileSize)
{
    return false;
}

void Scanner::ScanMaze()
{
    //Here should the maze been scanned and send a solution 
    std::cout << "Maze has been scanned" << std::endl;
    tcpClient.SendMessage("Send a scanned maze! \n");
}    
            
void Scanner::SendFile(std::string fileName)
{

}
