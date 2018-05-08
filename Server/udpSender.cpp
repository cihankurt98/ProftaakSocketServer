#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h> /* memset() */
#include <sys/time.h> /* select() */
#include "udpSender.h"

//for Mac OS X
#include <stdlib.h>

#define REMOTE_SERVER_PORT 1080
#define MAX_MSG 100
#define BUFSIZO 30

udpSender::udpSender()
{
	strncpy(MESSAGEBUF, "Who is here?", BUFSIZO - 1);
	MESSAGEBUF[BUFSIZO - 1] = 0;
	broadcast = 1;
}

int udpSender::Setup()
{
	host = gethostbyname(remote_addr);
	if (host == NULL)
	{
		return -1;
	}

	remoteServAddr.sin_family = host->h_addrtype;
	memcpy((char *) &remoteServAddr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);
	remoteServAddr.sin_port = htons(REMOTE_SERVER_PORT);

	if (CreateSocket() == -1 || Bind() == -1)
	{
		return -1;
	}
	return 1;
}

void udpSender::SetIp(char * ip)
{
	remote_addr = ip;
}

int udpSender::CreateSocket()
{
	sd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sd < 0 || setsockopt(sd, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof broadcast) == -1)
	{
		close(sd);
		return -1;
	}
	return 1;
}

int udpSender::Bind()
{
	cliAddr.sin_family = AF_INET;
	cliAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	cliAddr.sin_port = htons(0);

	rc = bind(sd, (struct sockaddr *) &cliAddr, sizeof(cliAddr));
	if (rc < 0)
	{
		close(sd);
		return -1;
	}
	return 1;
}

int udpSender::Broadcast()
{
	rc = sendto(sd, MESSAGEBUF, BUFSIZO, 0, (struct sockaddr *) &remoteServAddr, sizeof(remoteServAddr));

	if (rc < 0)
	{
		close(sd);
		return -1;
	}
	return 1;
}

