#include "scanner.h"

Scanner::Scanner():tcpClient("127.0.0.1")
{
    state = Idle;
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
    return state;
}

void Scanner::HandleMessage()
{
    std::string message = tcpClient.ReceiveMessage();
    if(message == ScannerScanMaze)
    {
        state = Busy;
        ScanMaze();
        state = Done;
    }
    if(message == ScannerSendFile)
    {
        if (state != Busy)
        {
            SendFile("~/example");
            state = Idle;
        }
    }
    if(message == GetCurrentState)
    {
        SendState();
    }
}

bool Scanner::Save(int fileSize)
{
    return false;
}

void Scanner::ScanMaze()
{
    //Here should the maze been scanned and send a solution
    // ...scanning
    // ...scanning
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "Maze has been scanned" << std::endl;
}
void Scanner::SendFile(std::string fileName)
{
    fileName = fileName;

    tcpClient.SendMessage("0, 0, Empty\n1, 0, Empty\n2, 0, Start\n3, 0, Wall\n4, 0, Empty\n5, 0, Empty\n0, 1, Empty\n1, 1, Wall\n2, 1, Empty\n3, 1, Wall\n4, 1, Wall\n5, 1, Empty\n0, 2, Empty\n1, 2, Wall\n2, 2, Empty\n3, 2, Empty\n4, 2, Empty\n5, 2, Empty\n0, 3, Wall\n1, 3, Wall\n2, 3, Wall\n3, 3, Wall\n4, 3, Wall\n5, 3, Empty\n0, 4, Empty\n1, 4, Empty\n2, 4, Empty\n3, 4, Empty\n4, 4, Empty\n5, 4, Empty\n0, 5, Wall\n1, 5, Wall\n2, 5, Empty\n3, 5, Wall\n4, 5, Wall\n5, 5, Empty\n0, 5, Empty\n1, 5, Empty\n2, 5, Empty\n3, 5, Finis\n4, 5, Wal\n5, 5, Empty\n");
}
void Scanner::SendState()
{
    tcpClient.SendMessage(ClientStateString[state]);
}
