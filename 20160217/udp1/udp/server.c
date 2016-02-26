#include <string.h>
#include <sys/select.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>      
#include <sys/socket.h>
int main(int argc,char* argv[])
{
	int sfd=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	bind(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	printf("bind ok!\n");
	
	char buf[128];
	struct sockaddr_in client;
	bzero(&client,sizeof(client));
	int len=sizeof(client);
	bzero(buf,sizeof(buf));	
	fd_set rdset;
	int ret;
	
	while(1)
	{
		FD_ZERO(&rdset);
		FD_SET(sfd,&rdset);
		FD_SET(0,&rdset);
		ret=select(sfd+1,&rdset,NULL,NULL,NULL);
		if(ret >0)
		{
			if(FD_ISSET(sfd,&rdset))
			{		
				bzero(buf,sizeof(buf));
				recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr*)&client,&len);
				printf("I am client,recv message is %s\n",buf);
				printf("client ip=%s,port=%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
			}
			if(FD_ISSET(0,&rdset))
			{
				bzero(buf,sizeof(buf));
				read(0,buf,sizeof(buf));
				sendto(sfd,buf,strlen(buf)-1,0,(struct sockaddr*)&client,sizeof(struct sockaddr));
			}
		}
	}
	close(sfd);
	return 0;
}
