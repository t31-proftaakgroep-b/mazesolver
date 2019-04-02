#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdexcept>
#include <netdb.h>
#include <iostream>
#include <arpa/inet.h>

#include "PTSocket.h"

PTSocket::PTSocket(int* socketfd)
{
	this->socketfd = *socketfd;
}

PTSocket::PTSocket(std::string host, int port)
{
	// (void) host;
	// (void) port;
	this->host = host;
	struct sockaddr_in serv_addr;
	struct hostent* server; 
	socketfd =  socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (socketfd < 0)
	{
		throw std::runtime_error("Error opening socket.");
	}
	server = gethostbyname(host.c_str());
	if (server == NULL) {
		throw std::runtime_error("Host not found");
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(port);

	int test = connect(socketfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
	std::cout << "new socket??: " << test << std::endl;
	if (test < 0)
	{
		throw std::runtime_error("Error connecting");
	}
}

PTSocket::~PTSocket()
{
	close(socketfd);
}
	//client
PTSocket::PTSocket(int port)
{
	socketfd =  socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (socketfd < 0)
	{
		throw std::runtime_error("Error opening socket.");
	} 
	struct sockaddr_in  serv_addr;
	serv_addr.sin_family = AF_INET;  

	serv_addr.sin_addr.s_addr = INADDR_ANY;  

	serv_addr.sin_port = htons(port);


	if(bind(socketfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))==-1)
	{
		throw std::runtime_error("Error binding socket.");
	}

}
	//server
int PTSocket::Send(int data)
{
	//std::cout << data << std::endl;
	return send(socketfd, &data, 1, 0);
}

int PTSocket::Receive()
{
	int data;
	data = -1;
	//std::cout << "whatsup?" << std::endl;
	std::cout << "Receive socket: " << socketfd << std::endl;
	recv(socketfd, &data, sizeof(data), 0);
	return data;
}


int PTSocket::Connect(std::string host)
{
	return socketfd;
	(void) host;
}

int PTSocket::Disconnect(std::string host)
{
	return 0;
	(void) host;
}


int PTSocket::Listen()
{
	int ret = listen(socketfd,5);
	if(ret==-1)
	{
		throw std::runtime_error("Error on listen");
	}
	return ret;
}

PTSocket* PTSocket::Accept()
{
	socklen_t clilen = sizeof(clientAddress);
	int newsockfd = accept(socketfd, (sockaddr*) &clientAddress, &clilen);
	if (newsockfd == -1	) 
	{
		std::cout << strerror(errno) << std::endl;
		throw std::runtime_error("Error on accept");
	}
	std::cout<<"New client!" << std::endl;
	return new PTSocket(&newsockfd);
}

int PTSocket::GetPort()
{
	return 0;
}

std::string PTSocket::GetHost()
{
	return inet_ntoa(( clientAddress).sin_addr);
}

/* The port number is passed as an argument

void error(const char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{

     // server byte order
	serv_addr.sin_family = AF_INET;  

     // automatically be filled with current host's IP address
	serv_addr.sin_addr.s_addr = INADDR_ANY;  

     // convert short integer value for port must be converted into network byte order
	serv_addr.sin_port = htons(portno);

     // bind(int fd, struct sockaddr *local_addr, socklen_t addr_length)
     // bind() passes file descriptor, the address structure, 
     // and the length of the address structure
     // This bind() call will bind  the socket to the current IP address on port, portno
	if (bind(sockfd, (struct sockaddr *) &serv;_addr,
		sizeof(serv_addr)) < 0) 
	error("ERROR on binding");

     // This listen() call tells the socket to listen to the incoming connections.
     // The listen() function places all incoming connection into a backlog queue
     // until accept() call accepts the connection.
     // Here, we set the maximum size for the backlog queue to 5.
	listen(sockfd,5);

     // The accept() call actually accepts an incoming connection
	clilen = sizeof(cli_addr);

     // This accept() function will write the connecting client's address info 
     // into the the address structure and the size of that structure is clilen.
     // The accept() returns a new socket file descriptor for the accepted connection.
     // So, the original socket file descriptor can continue to be used 
     // for accepting new connections while the new socker file descriptor is used for
     // communicating with the connected client.
	newsockfd = accept(sockfd, 
		(struct sockaddr *) &cli;_addr, &clilen;);
	if (newsockfd < 0) 
		error("ERROR on accept");

	printf("server: got connection from %s port %d\n",
		inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));


     // This send() function sends the 13 bytes of the string to the new socket
	send(newsockfd, "Hello, world!\n", 13, 0);

	bzero(buffer,256);

	n = read(newsockfd,buffer,255);
	if (n < 0) error("ERROR reading from socket");
	printf("Here is the message: %s\n",buffer);

	close(newsockfd);
	close(sockfd);
	return 0; 
}

*/