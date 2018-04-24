#ifndef CLIENT_H
#define CLIENT_H

#include <arpa/inet.h> //inet_addr

class Client
{
private:
	int sock;
	struct sockaddr_in server;
	//char message[1000];
	//char last_server_reply[2000];
	

public:
	int CreateSocket();
	int ConnectToServer();
	int SendMessage(char message[]);
	int ReceiveMessage(char server_reply[]);
	void EndConnection();

	Client();
	virtual ~Client();
};



#endif