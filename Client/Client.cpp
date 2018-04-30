#include <stdlib.h>	/* defines exit and other sys calls */
#include <sys/socket.h>
#include <string.h> //strlen
#include <unistd.h>    //write
#include <stdio.h> //printf
#include <iostream> // std

#include "Client.h"



Client::Client()
{

}

Client::~Client()
{

}

int Client::CreateSocket()
{
	sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1)
	{
		return -1;
	}

	//server.sin_addr.s_addr = inet_addr("192.168.19.167");
	server.sin_family = AF_INET;
	server.sin_port = htons( 8888 );
	return 1;
}

int Client::ConnectToServer()
{
	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		return -1;
	}
	return 1;
}

int Client::SendMessage(char message[])
{
	if ( send(sock , message , strlen(message) , 0) < 0)
	{
		return -1;
	}
	return 1;
}

int Client::ReceiveMessage(char server_reply[])
{
	if ( recv(sock , server_reply , 2000 , 0) < 0)
	{
		return -1;
	}
	return 1;
}

void Client::EndConnection()
{
	close(sock);
}

void Client::setServer(struct sockaddr_in servero)
{
	server = servero;
}
