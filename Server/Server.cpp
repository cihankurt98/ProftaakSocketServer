#include <sys/socket.h>
#include <iostream> //std
#include <string.h>
#include <unistd.h>    //write
#include <stdlib.h>

#include "Server.h"

#define TIMEOUT 3

Server::Server()
{

}

Server::~Server()
{
}

int Server::CreateSocket()
{
	socket_desc = socket(AF_INET , SOCK_STREAM , 0); // list met meerdere sockets voor meerdere connecties?
	if (socket_desc == -1)
	{
		return -1;
	}

	struct timeval tv =
	{
		.tv_sec = timeOut,
		.tv_usec = 0,
	};

	if (0 > setsockopt(socket_desc, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)))
	{
		std::cout << "setsockopt failed" << std::endl;
		return -1;
	}

	//struct inaddr is ip, htons is port.
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( 8888 );


	return 1;
}

int Server::Bind() //parameter list socket[index] om te binden met specifieke socket?
{
	if ( bind(socket_desc, (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		return -1;
	}
	return 1;
}


void Server::Listen()
{
	listen(socket_desc , 3);
}

int Server::AcceptConnection()
{
	while (to_quit == false)
	{

		c = sizeof(struct sockaddr_in);

		//accept connection from an incoming client
		client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
		processID = fork();
		if (client_sock < 0 && processID < 0)
		{
			return -1;
		}

		if (processID == 0)
		{
			// processID == 0: child process
			Receive();
			exit (0);        /* Child process terminates */
		}
		else
		{
			// processID > 0: main process
			std::cout << "main waiting..." << getpid() << std::endl;

			sleep (2);
		}

	}
	close(client_sock);
	close(socket_desc);
	return 1;
}

void Server::Receive() //manier zoeken om de std::cout weg te halen, moet in main
{

	while ( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 )
	{
		std::cout << read_size << std::endl;
		client_message[read_size] = '\0';
		write(client_sock , client_message , strlen(client_message));
		std::cout << client_message << std::endl;
	}

	if (read_size == 0)
	{
		std::cout << "Client disconnected" << std::endl;
	}

	else if (read_size == -1)
	{
		std::cout << "recv failed" << std::endl;
	}
}

/* De bovenstaande code zal een server starten op localhost (127.0.0.1) op poort 8888.
Zodra het een connectie heeft, zal er input gelezen worden van de client. Het zelfde bericht zal worden terug geschreven.
*/
