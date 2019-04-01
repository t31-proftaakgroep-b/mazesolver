#ifndef __SOCKET_H
#define __SOCKET_H
#include <netinet/in.h>

#include <string>

class PTSocket
{
private:
	int socketfd;
	PTSocket(int* socketfd);
	std::string host;
	struct sockaddr_in clientAddress;

public:
	PTSocket(std::string host, int port);//client
	PTSocket(int port);//server
	~PTSocket();
	int Send(int data);
	int Receive();
	int Connect(std::string host);
	int Disconnect(std::string host);
	int Listen();
	PTSocket* Accept();
	int GetPort();
	std::string GetHost();

};


#endif