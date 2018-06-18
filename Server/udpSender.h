#ifndef UDPSENDER_H
#define UDPSENDER_H


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h> /* memset() */
#include <sys/time.h> /* select() */ 

//for Mac OS X
#include <stdlib.h>

#define REMOTE_SERVER_PORT 1080
#define MAX_MSG 100
#define BUFSIZO 30



class udpSender
{
	public:
		udpSender();
		~udpSender();
		void SetIp(char * ip);
		void Setup();
		void CreateSocket();
		void Bind();
		void Broadcast();
	
	private:
	  int sd;
	  int rc;
	  int i;
	  int n;
	  struct sockaddr_in cliAddr;
	  struct sockaddr_in remoteServAddr;
	  struct hostent *h;
	  socklen_t cliLen;	  
	  int broadcast;
	  
	  char MESSAGEBUF[BUFSIZO];
	  char printerBuf[MAX_MSG];
	  
	  char * remote_addr;
	  
	 
	  
	  
};

#endif
