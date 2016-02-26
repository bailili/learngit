#include "func.h"
#define NUM 10
int main(int argc,char* argv[])
{
	if(argc !=3)
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
	bind(sfd,(struct sockaddr*)&server_addr,sizeof(struct sockaddr));
	listen(sfd,NUM);
	fd_set rdset;
	int ret;
	struct sockaddr_in client_addr;
	bzero(&client_addr,sizeof(client_addr));
	int length=sizeof(client_addr);
	char buf[128];
	int newfd=-1;
	while(1)
	{
		FD_ZERO(&rdset);
		FD_SET(sfd,&rdset);
		FD_SET(0,&rdset);
		if(newfd >0)
		{
			FD_SET(newfd,&rdset);
		}
		ret=select(NUM+4,&rdset,NULL,NULL,NULL);
		if(ret >0)
		{
			if(FD_ISSET(sfd,&rdset))
			{
				newfd=accept(sfd,(struct sockaddr*)&client_addr,&length);
				printf("I am server,connect success!\n");
			}
			if((newfd>0) && FD_ISSET(newfd,&rdset))
			{
				bzero(buf,sizeof(buf));
				ret=recv(newfd,buf,sizeof(buf),0);
				if(ret >0)
				{
					printf("%s\n",buf);
				}
			}
			if(FD_ISSET(0,&rdset))
			{
				bzero(buf,sizeof(buf));
				read(0,buf,sizeof(buf));
				send(newfd,buf,strlen(buf)-1,0);
			}
		}
	}
return 0;
}
