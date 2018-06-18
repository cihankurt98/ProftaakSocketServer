#include <iostream>

#include "Server.h"
#include "udpSender.h"
#include <unistd.h>
#include <thread>

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
	std::cout << ("(A) Find Printers\n");
	std::cout << ("(1) Create socket\n");
	std::cout << ("(2) Bind\n");
	std::cout << ("(3) Listen\n");
	std::cout << ("(4) Accept connection\n");
	std::cout << ("(5) Receive\n");
	std::cout << ("-----------------------\n");
	std::cout << ("(9) QUIT\n\n");
	std::cout << ("Choice : ");
}


int main(int argc, char *argv[])
{
	if(argc<1)
	{
		printf("usage : %s <server> <data1> ... <dataN> \n", argv[0]);
		exit(1);
    }
	
	// stap 1 : create udp
	bool quit = false;
	Server server;
	udpSender udpsender;
	
	udpsender.SetIp(argv[1]);
    udpsender.Setup();
    
    
    
    // stap 2: create tcp
    CreateSocket(&server);
    Bind(&server);
    Listen(&server);
    
    
    //udpsender.Broadcast();
    std::thread brood(&udpSender::Broadcast, udpsender);
    brood.detach();

	AcceptConnection(&server);
	

		



	return 0;
}
