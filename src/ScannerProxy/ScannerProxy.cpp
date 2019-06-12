#include "ScannerProxy.h"

ScannerProxy::ScannerProxy(ICommunication* communication):Client(communication)
{

}

void ScannerProxy::ScanMaze()
{
    communication.SendMessage(ScannerScanMaze);
}

bool ScannerProxy::Save(int fileSize) 
{
    communication.SendMessage(ScannerSave);
    return false;
}

void ScannerProxy::SendFile(std::string fileName)
{
    communication.SendMessage(ScannerSendFile);
}
