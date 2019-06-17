#include "Communication.h"

Communication::Communication(int socketFD)
{
	socketFd = socketFD;
}

Communication::~Communication()
{

}

bool Communication::AcceptConnection()
{
    int newFd = accept(socketFd, NULL, NULL);
    if (newFd < 0)
    {
        perror("accept failed");
        close(newFd);
    }
    else
    {
        fileDescriptors.push_back(newFd);
    }
    return true;
}

int Communication::CheckSocket()
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

Bricktype Communication::GetBrickType()
{
	return brickType;
}

int Communication::GetNumberOfClients()
{
    return fileDescriptors.size() -1;
}

void Communication::InitialiseSocket()
{
    socketFd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketFd < 0)
    {
        //TODO uitzoeken/vragen wat we hiermee moeten
        throw std::bad_exception();
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

std::string Communication::ReceiveMessage()
{
	char buffer[BufferSize];
    int nrBytes = read(socketFd, buffer, BufferSize - 1);
    if (nrBytes >= 0)
    {
        buffer[nrBytes] = '\0';
        return buffer;
    }

    return "error occured";
}

std::string Communication::ReceiveMessage(int fd)
{
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
        //throw std::invalid_argument("Connection closed");
        fileDescriptors.erase(std::find(std::begin(fileDescriptors), std::end(fileDescriptors), fd));
    }

    else if (nrBytes == -1)
    {
        //TODO: Throw exception
    }
    
    return "";
}

bool Communication::SendMessage(std::string message)
{
    bool returnValue = false;
    size_t nrBytes = 0;
    while(nrBytes != message.length())
    {
        nrBytes = send(socketFd, message.c_str(), message.length(), 0);
    }
    returnValue = WaitForAck();

    return returnValue;
}

bool Communication::WaitForAck()
{
    std::string receivedMessage = ReceiveMessage();

    if(receivedMessage == AckMessage)
    {
        return true;
    }
    else if(receivedMessage == NackMessage)
    {
        return false;
    }
    else
    {
        //should throw error, will return false for now
        return false;
    }
}

int Communication::WaitForClient()
{
 	int returnval = CheckSocket();
    if (returnval != socketFd)
    {
        returnval = 0;
    }
    return returnval;
}