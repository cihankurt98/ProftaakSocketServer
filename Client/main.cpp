#include <iostream>

#include "Client.h"

static void CreateSocket(Client* client)
{
	int result = client->CreateSocket();

	if (result == 1)
	{
		std::cout << "Socket succesfully created" << std::endl;
	}
	else
	{
		std::cout << "Could not create socket" << std::endl;
	}
}

static void ConnectToServer(Client* client)
{
	int result = client->ConnectToServer();

	if (result == 1)
	{
		std::cout << "Connected" << std::endl;
	}
	else
	{
		std::cout << "Connection failed" << std::endl;
	}
}

static void SendMessage(Client* client, char message[])
{
	int result = client->SendMessage(message);
	if (result == 1)
	{
		std::cout << "The message: '" << message << ".' is succesfully sent" << std::endl;
	}
	else
	{
		std::cout << "Failed to send message" << std::endl;
	}
}

static void ReceiveMessage(Client* client)
{
	char server_reply[2000];
	int result = client->ReceiveMessage(server_reply);

	if (result == 1)
	{
		std::cout << "Server reply: " << server_reply << std::endl;
	}
	else
	{
		std::cout << "recv failed" << std::endl;
	}
}

static void EndConnection(Client* client)
{
	client->EndConnection();
	std::cout << "Connection ended" << std::endl;
}

static void showMenu( void )
{
	std::cout << ("\n\nClient Menu\n");
	std::cout << ("===============\n");
	std::cout << ("(1) Create socket\n");
	std::cout << ("(2) Connect to server\n");
	std::cout << ("(3) SendMessage\n");
	std::cout << ("(4) ReceiveMessage\n");
	std::cout << ("(5) EndConnection\n");
	std::cout << ("-----------------------\n");
	std::cout << ("(9) QUIT\n\n");
	std::cout << ("Choice : ");
}


int main(void)
{
	bool quit = false;
	Client client;

	while (!quit)
	{
		char choice = '\0';
		char test[] = "hoi";
		showMenu();
		std::cin >> choice;
		std::cin.ignore();

		switch (choice)
		{
		case '1' :
			CreateSocket(&client);
			break;
		case '2' :
			ConnectToServer(&client);
			break;
		case '3' :
			SendMessage(&client, test);
			break;
		case '4' :
			ReceiveMessage(&client);
			break;
		case '5' :
			EndConnection(&client);
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