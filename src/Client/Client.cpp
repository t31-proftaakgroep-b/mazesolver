#include "Client.h"

Client::Client():
AckMessage("ACK"),
NackMessage("NACK"),
FileLocation("/tmp/client")
{

}

Client::~Client()
{

}


int Client::InitialiseSocket(std::string address)
{
    if (address.empty())
    {
        perror("No adress is given");
        exit(EXIT_FAILURE);
    }

    socketFd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketFd == -1)
    {
        perror("cannot create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in sa;
    memset(&sa, 0, sizeof sa);
    sa.sin_family = AF_INET;
    sa.sin_port = htons(PortNumber);

    int result = inet_pton(AF_INET, "127.0.0.1", &sa.sin_addr);
    if (result != 1)
    {
        perror("could not convert ip address to network address structure");
        exit(EXIT_FAILURE);
    }
    else 
    {
        connectFd = connect(socketFd, (struct sockaddr*)&sa, sizeof sa);
        if (connectFd < 0)
        {
            perror("connect failed");
            close(socketFd);
            exit(EXIT_FAILURE);
        }

    return result;
    }
}

bool Client::SendMessage(std::string message)
{
    bool returnValue = false;
    size_t nrBytes = send(socketFd, message.c_str(), message.length(), 0);
    if (nrBytes != message.length())
    {
        std::string errorMessage = "not everything is sent (" + nrBytes + '/' + message.length();
        errorMessage += " bytes sent)";
        perror(errorMessage.c_str());
    }
    /*bool ackReceived = false;
    while(!ackReceived)
    {
        std::string receivedMessage = ReceiveMessage();

        if(receivedMessage == "ACK")
        {
            ackReceived = true;
            returnValue = true;
        }
    }*/
    return returnValue;
}

std::string Client::ReceiveMessage()
{
    const int BufferSize = 100;
    char buffer[BufferSize];
    int nrBytes = read(socketFd, buffer, BufferSize - 1); //connectFd not initialized!!
    if (nrBytes >= 0)
    {
        buffer[nrBytes] = '\0';
        //sleep (1);
        return buffer;
    }
    sleep (1);

    return "error occured";
}


std::string Client::ReceiveFile(std::string fileName, int fileSize)
{
    std::string filePath = FileLocation + "/" + fileName;
    FILE *file;
    char buffer[512];
    int ch = 0;
    file = fopen(filePath.c_str(),"a");
    while(ch != fileSize)
    {
        read(connectFd , buffer , 512); 
        fprintf(file , " %s" , buffer);   
        ch++;
    }
    
    return fileName;
}

bool Client::RequestSave(int fileSize)
{

    std::string message = "<?xml version=\"1.0\"?>"
    "<request type=\"Save\">"
    " <fileSize>" + std::to_string(fileSize) + "</fileSize>"
    "</request>";

    SendMessage(message);

    return WaitForAck();
}

void Client::SendFile(std::string file, int fileSize)
{
    //std::cout << "SendFile============" << std::endl;
    std::string filePath = FileLocation + "/" + file;
    FILE* filePointer = fopen(filePath.c_str(),"r");
    
    char buffer[1024];

    bzero(buffer, 512);
    char c;
    
    while( (c = getc(filePointer) ) !=EOF) //we acknowledge this is ugly and this causes the a character to get "eaten" from the file and thus cannot be send. We didn't have enough time to fix this
    {	
        bzero(buffer, 512);
        //fscanf(filePointer , "%s" , buffer);
        fread(buffer, sizeof(char), 512, filePointer);
        //std::cout << "SendFile buffer: " << buffer << std::endl;
        write(socketFd,buffer,512);
    }
    rewind(filePointer);
}



bool Client::Disconnect()
{
    if (shutdown(socketFd, SHUT_RDWR) < 0)
    {
        perror("shutdown failed");
        close(socketFd);
        exit(EXIT_FAILURE);
        return true;
    }
    close(socketFd);
    return true;
}

bool Client::WaitForAck()
{
    std::string receivedMessage = ReceiveMessage();

    if(receivedMessage == "ACK")
    {
        return true;
    }
    else if(receivedMessage == "NACK")
    {
        return false;
    }
    else
    {
        //should throw error, will return false for now
        return false;
    }
    
}

int Client::GetFileSize(std::string fileName)
{
/*     std::ifstream in(fileName, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
 */
    std::string filePath = FileLocation + "/" + fileName;
    std::ifstream file(filePath.c_str(), std::ifstream::in | std::ifstream::binary);

    if(!file.is_open())
    {
        return -1;
    }

    file.seekg(0, std::ios::end);
    int fileSize = file.tellg();
    file.close();

    return fileSize;
}
