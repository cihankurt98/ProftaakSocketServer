#ifndef UDPSENDER_H
#define UDPSENDER_H


#include <arpa/inet.h>

#define MAX_MSG 100
#define BUFSIZO 30



class udpSender
{
	public:
		udpSender();
		void SetIp(char * ip);
		int Setup();
		int CreateSocket();
		int Bind();
		int Broadcast();
	
	private:
	  int sd;
	  int n;
	  struct sockaddr_in cliAddr;
	  struct sockaddr_in remoteServAddr;
	  struct hostent *host;
	  socklen_t cliLen;	  
	  int broadcast;
	  
	  char MESSAGEBUF[BUFSIZO];
	  char printerBuf[MAX_MSG];
	  
	  char *remote_addr;
	  
	 
	  
	  
};

#endif
