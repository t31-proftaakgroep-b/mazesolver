#include "ScannerProxy.h"

ScannerProxy::ScannerProxy(ICommunication* communication):Client(communication)
{

}

void ScannerProxy::ScanMaze()
{
    GetCommunication()->SendMessage(ScannerScanMaze);
}

bool ScannerProxy::Save(int fileSize)
{
    GetCommunication()->SendMessage(ScannerSave);
    return false;
}

void ScannerProxy::SendFile(std::string fileName)
{
    GetCommunication()->SendMessage(ScannerSendFile);
}
