#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

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

//for Mac OS X
#include <stdlib.h>

#define LOCAL_SERVER_PORT 1080
#define MAX_MSG 100

class udpReceiver
{
	public:
		udpReceiver();
		void CreateSocket();
		void Bind();
		void Receive();
		sockaddr_in const& getAddr();
		void EndConnection();
	
	private:
		int sd;
		int rc;
		int n;
	    socklen_t cliLen;
	    struct sockaddr_in cliAddr;
	    struct sockaddr_in servAddr;
	    char msg[MAX_MSG];
	    char reply[MAX_MSG];
	    int broadcast;
};

#endif
