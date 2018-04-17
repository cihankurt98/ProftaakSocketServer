#include <iostream>

#include "Server.h"

static void CreateSocket(Server* server)
{
	int result = server->CreateSocket();

	if (result == 1)
	{
		std::cout << "Socket is successfully created" << std::endl;
	}
	else
	{
		std::cout << "Could not create socket" << std::endl;
	}
}

static void Bind(Server* server)
{
	int result = server->Bind();

	if (result == 1)
	{
		std::cout << "Binding completed" << std::endl;
	}
	else
	{
		std::cout << "Binding failed" << std::endl;
	}
}

static void Listen(Server* server)
{
	server->Listen();
}

static void AcceptConnection(Server* server)
{
	std::cout << "Waiting for incoming connections..." << std::endl;
	int result = server->AcceptConnection();

	if (result == 1)
	{
		std::cout << "Connection accepted" << std::endl;
	}
	else
	{
		std::cout << "Accepting connection failed" << std::endl;
	}
}

static void Receive(Server* server)
{
	server->Receive();
}

static void showMenu( void )
{
	std::cout << ("\n\nSocket Server Menu\n");
	std::cout << ("===============\n");
	std::cout << ("(1) Create socket\n");
	std::cout << ("(2) Bind\n");
	std::cout << ("(3) Listen\n");
	std::cout << ("(4) Accept connection\n");
	std::cout << ("(5) Receive\n");
	std::cout << ("-----------------------\n");
	std::cout << ("(9) QUIT\n\n");
	std::cout << ("Choice : ");
}


int main(void)
{
	bool quit = false;
	Server server;

	while (!quit)
	{
		char choice = '\0';
		showMenu();
		std::cin >> choice;
		std::cin.ignore();

		switch (choice)
		{
		case '1' :
			CreateSocket(&server);
			break;
		case '2' :
			Bind(&server);
			break;
		case '3' :
			Listen(&server);
			break;
		case '4' :
			AcceptConnection(&server);
			break;
		case '5' :
			Receive(&server);
			break;

		case '9' :
			quit = true;
			break;
		default:
			std::cout << "\n\nChoice not recognized(" << choice << ")" << std::endl;
			break;
		}
	}

	return 0;
}