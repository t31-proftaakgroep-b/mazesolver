#include "Server.h"
#include <iostream> //ewl

Server::Server() :
AckMessage("ACK"),
NackMessage("NACK"),
FileLocation("/tmp/server")
{
    
}

Server::~Server()
{

}


void Server::InitialiseSocket()
{
    socketFd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketFd < 0)
    {
        perror("cannot create socket");
        exit(EXIT_FAILURE);
    }   

    struct sockaddr_in sa;
    memset(&sa, 0, sizeof sa);
    sa.sin_family = AF_INET;
    sa.sin_port = htons(PortNumber);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(socketFd, (struct sockaddr*)&sa, sizeof sa) < 0)
    {
        perror("bind failed");
        close(socketFd);
        exit(EXIT_FAILURE);
    }

    if (listen(socketFd, 10) < 0)
    {
        perror("listen failed");
        close(socketFd);
        exit(EXIT_FAILURE);
    }

    fileDescriptors.push_back(socketFd);
    
    //return connectFd;
}

bool Server::HandleMessage(int fd, std::string message)
{
    tinyxml2::XMLDocument doc;

    tinyxml2::XMLError result = doc.Parse(message.c_str());

    if (result == tinyxml2::XML_SUCCESS)
    {
        const tinyxml2::XMLElement* request = doc.FirstChildElement("request");
        if (request != NULL)
        {
            const tinyxml2::XMLAttribute* requestType = request->FindAttribute("type");
            if (requestType != NULL)
            {
                if(strcmp(requestType->Value(), "Save") == 0)
                {
                    std::string temp = request->FirstChildElement("fileSize")->GetText();
                    int fileSize = atoi(temp.c_str());

                    SendMessage(fd, AckMessage);
                    
                    //receives file, then sends the key
                    SendMessage(fd, ReceiveFile(fd, fileSize));
                }
                else if(strcmp(requestType->Value(), "Load") == 0)
                {
                    std::string key = request->FirstChildElement("key")->GetText();

                    if(CheckKey(key))
                    {
                        SendMessage(fd, AckMessage);
                        SendFile(fd, key);
                    }
                    else
                    {
                        SendMessage(fd, NackMessage);
                    }
                    
                }
                else if(strcmp(requestType->Value(), "Delete") == 0)
                {
                    std::string key = request->FirstChildElement("key")->GetText();
                    
                    if(CheckKey(key))
                    {
                        SendMessage(fd, AckMessage);
                        DeleteFile(fd, key);
                    }
                    else
                    {
                        SendMessage(fd, NackMessage);
                    }
                }

            }
        }
        return true;
    } 
    else
    {
        return false;
    }
}

std::string Server::ReceiveMessage(int fd)
{
    const int BufferSize = 100;
    char buffer[BufferSize];
    int nrBytes = read(fd, buffer, BufferSize - 1);
    if (nrBytes > 0)
    {
        buffer[nrBytes] = '\0';      
        return buffer;
    }

    else if (nrBytes == 0)
    {
        //return "CLOSED";
        throw std::invalid_argument("Connection closed");
    }

    else if (nrBytes == -1)
    {
        //TODO: Throw exception
    }

    return "";
}

void Server::SendMessage(int fd, std::string message)
{
    size_t nrBytes = send(fd, message.c_str(), message.length(), 0);
    
    if (nrBytes != message.length())
    {
        //std::cout << "not everything is sent (" << nrBytes << "/" << text.length() << " bytes sent)\n";
    }
}

bool Server::Connect()
{
    int newFd = accept(socketFd, NULL, NULL);
    if (newFd < 0)
    {
        perror("accept failed");
        close(newFd);
        exit(EXIT_FAILURE);
    }
    fileDescriptors.push_back(newFd);
    return true;
}

int Server::checkConnection()
{
    int returnval = CheckSocket();
    if (returnval != socketFd)
    {
        returnval = 0;
    }
    return returnval;

}

int Server::GetAmountOfConnectedClients()
{
    return fileDescriptors.size() -1;
}

int Server::CheckSocket()
{
    timeout.tv_sec = SelectTimeout;
    timeout.tv_usec = 0;

    FD_ZERO(&readFds);
    

    for(unsigned int i = 0; i < fileDescriptors.size(); i++)
    {
        FD_SET(fileDescriptors[i], &readFds);
    }

    if (select(FD_SETSIZE, &readFds, NULL, NULL, &timeout) > 0)
    {
        for(unsigned int i = 0; i < fileDescriptors.size(); i++)
        {
            int set = FD_ISSET(fileDescriptors[i], &readFds);
            if(set > 0)
            {
                return fileDescriptors[i];
            }
        }

        //returnval = FD_ISSET(fd, &readFds);
    }
    return 0;
}

std::string Server::ReceiveFile(int fd, int fileSize)
{
    std::string fileName = Server::GetRandomKey();
    std::string filePath = FileLocation + "/" + fileName;
 
    FILE* fp;
    char buffer[512];
    int ch = 0;
    fp = fopen(filePath.c_str(),"a");
    if (fp != NULL)
    {
        while(ch <= fileSize)
        {
            read(fd , buffer , 512);
            fwrite(buffer, sizeof(char), 512, fp); //we should check if the buffer had any data instead of reading 512 (magic number) bytes
            ch += 512;
            bzero(buffer, 512);
	    }
        fclose(fp);
    }
    else 
    {
        return "";
    }
    
    return fileName;
}

bool Server::CheckKey(std::string key)
{
    std::string filePath = FileLocation + "/" + key;
    if (FILE *file = fopen(filePath.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

void Server::SendFile(int fd, std::string key)
{    
    char buffer[1024];
    std::string filePath = FileLocation + "/" + key;
    FILE* file = fopen(filePath.c_str(),"r");
    
    char c;
    
    while((c = getc(file))!=EOF)
	{	
		fscanf(file , "%s" , buffer);
	}       
    
    rewind(file);
       
    char ch;
    while(ch != EOF)
    {
        fscanf(file , "%s" , buffer);
		write(fd,buffer,512);
		ch = fgetc(file);
    }
    
}

void Server::DeleteFile(int fd, std::string key)
{
    //TODO
}



//Generates a random key, repeats process if key is already in use
std::string Server::GetRandomKey()
{
    //std::cout << "GetRandomKey" << std::endl;
    std::string TotallyRandomKey = "";
    do 
    {
        //std::cout << "inside while" << std::endl;
        TotallyRandomKey = GenerateRandomString();
    } while (CheckKey(TotallyRandomKey));
    return TotallyRandomKey;
}

std::string Server::GenerateRandomString()
{
    int len = 10;
    std::string output = "0123456789";
    static const char alphanum[] =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";    
    //std::cout << "Generating random string" << std::endl;
    for (int i = 0; i < len; ++i)
    {
        output[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    output[len] = '\0';

    return output;
}