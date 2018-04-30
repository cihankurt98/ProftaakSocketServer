/* fpont 12/99 */
/* pont.net    */
/* udpClient.c */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h> /* memset() */
#include <sys/time.h> /* select() */ 
#include "udpSender.h"

//for Mac OS X
#include <stdlib.h>

#define REMOTE_SERVER_PORT 1500
#define MAX_MSG 100
#define BUFSIZO 30

udpSender::udpSender()
{
	strncpy(MESSAGEBUF, "Who is here?", BUFSIZO -1);
	MESSAGEBUF[BUFSIZO - 1] = 0;
	broadcast = 1;
}

void udpSender::Setup()
{
	 h = gethostbyname(remote_addr);
	 if (h == NULL) 
	 {
		printf("unknown host '%s' \n", remote_addr);
		exit(1);
	 }	
	 
	 remoteServAddr.sin_family = h->h_addrtype;
	 memcpy((char *) &remoteServAddr.sin_addr.s_addr, h->h_addr_list[0], h->h_length);
	 remoteServAddr.sin_port = htons(REMOTE_SERVER_PORT);
	 
	 CreateSocket();
	 Bind();
}

void udpSender::SetIp(char * ip)
{
	remote_addr = ip;
}

void udpSender::CreateSocket()
{
	  sd = socket(AF_INET,SOCK_DGRAM,0);
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

void udpSender::Bind()
{
	  cliAddr.sin_family = AF_INET;
	  cliAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	  cliAddr.sin_port = htons(0);
	  
	  rc = bind(sd, (struct sockaddr *) &cliAddr, sizeof(cliAddr));
	  if (rc < 0) 
	  {
		printf("cannot bind port\n");
		exit(1);
	  }	
}

void udpSender::Broadcast()
{
    rc = sendto(sd, MESSAGEBUF, BUFSIZO, 0, (struct sockaddr *) &remoteServAddr, sizeof(remoteServAddr));

    if (rc < 0) 
    {
      printf("cannot send data\n");
      close(sd);
      exit(1);
    }	
}

