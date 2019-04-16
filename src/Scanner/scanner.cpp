#include "scanner.h"

Scanner::Scanner():client("127.0.0.1")
{

}

Scanner::~Scanner()
{

}

void Scanner::Disconnect()
{

}

void Scanner::ScanMaze()
{
    client.SendMessage("Send a scanned maze");
}
