/* fpont 12/99 */
/* pont.net    */
/* udpServer.c */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h> /* close() */
#include <string.h> /* memset() */
#include "udpReceiver.h"

//for Mac OS X
#include <stdlib.h>

#define LOCAL_SERVER_PORT 1500
#define MAX_MSG 100
#define BUFSIZO 30

udpReceiver::udpReceiver()
{
	strncpy(reply, "I'm a Printer", BUFSIZO -1);
	reply[BUFSIZO - 1] = 0;
	broadcast = 1;
}

void udpReceiver::CreateSocket()
{
	 /* socket creation */
	  sd=socket(AF_INET, SOCK_DGRAM, 0);
	  if (sd < 0)
	  {
		printf("cannot open socket \n");
		exit(1);
	  }
	  
	  if (setsockopt(sd, SOL_SOCKET, SO_BROADCAST, &broadcast,sizeof broadcast) == -1) 
	  {
			  perror("setsockopt (SO_BROADCAST)");
			  exit(1);
	  }	
}

void udpReceiver::Bind()
{
	  servAddr.sin_family = AF_INET;
	  servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	  servAddr.sin_port = htons(LOCAL_SERVER_PORT);
	  rc = bind (sd, (struct sockaddr *) &servAddr,sizeof(servAddr));
	  if (rc < 0) 
	  {
		printf("cannot bind port number %d \n", LOCAL_SERVER_PORT);
		exit(1);
	  }	
}

void udpReceiver::Receive()
{
	  while(1) 
	  {
		
		memset(msg,0x0,MAX_MSG);

		cliLen = sizeof(cliAddr);
		n = recvfrom(sd, msg, MAX_MSG, 0, (struct sockaddr *) &cliAddr, &cliLen);

		if (n < 0) 
		{
		  printf("cannot receive data \n");
		  continue;
		}
		
		if (n > 0)
		{
			printf("from %s:UDP%u : %s \n",inet_ntoa(cliAddr.sin_addr), ntohs(cliAddr.sin_port),msg);		
			close(sd);	
			return;
		}
		
	  }	
}

sockaddr_in const& udpReceiver::getAddr() 
{
	return servAddr;
}

