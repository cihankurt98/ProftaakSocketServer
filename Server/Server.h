#ifndef SERVER_H
#define SERVER_H

#include <arpa/inet.h> //inet_addr

class Server
{

private:
	int socket_desc;
	int client_sock;
	int c;
	int read_size;
	struct sockaddr_in server;
	struct sockaddr_in client;
	char client_message[2000];
	
	pid_t processID;                 /* Process ID from fork() */
    bool to_quit;
    int timeOut;
    

public:
	int CreateSocket();
	int Bind();
	void Listen();
	int AcceptConnection();
	void Receive();

	Server();

	virtual ~Server();

};
#endif
