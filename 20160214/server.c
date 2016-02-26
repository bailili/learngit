#include "func.h"

#define NUM 10

int main(int argc,char* argv[])
{
	if(argc != 3)
	{
		printf("error args\n");
		return -1;
	}
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in server_addr;
	bzero(&server_addr,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr=inet_addr(argv[1]);
	
	int ret;
	ret=bind(sfd,(struct sockaddr*)&server_addr,sizeof(struct sockaddr));
	if(-1==ret)
	{
		perror("bind\n");
		close(sfd);
		return -1;
	}
	ret=listen(sfd,NUM);
	if(-1==ret)
	{
		perror("listen\n");
		close(sfd);
		return -1;
	}
	struct sockaddr_in client_addr;
	bzero(&client_addr,sizeof(client_addr));
	int length=sizeof(client_addr);
	int newfd;
	while(1)
	{
		newfd=accept(sfd,(struct sockaddr*)&client_addr,&length);
		if(-1==newfd)
		{
			perror("accept\n");
			close(sfd);
			return -1;
		}
		printf("I am server,connect success,client IP =%s,client PORT =%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
	}
	return 0;
}
