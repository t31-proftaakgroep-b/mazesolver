#include "scanner.h"

Scanner::Scanner()
{
    client = new Client();
}

Scanner::~Scanner()
{

}

void Scanner::Disconnect()
{

}

void Scanner::ScanMaze()
{
    client->SendMessage("Send a scanned maze");
}