#include "func.h"
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
	connect(sfd,(struct sockaddr*)&server_addr,sizeof(struct sockaddr));	  printf("I am client,connect success!\n");
	
	fd_set rdset;
	char buf[128];
	int ret;

	while(1)
	{
		FD_ZERO(&rdset);
		FD_SET(0,&rdset);
		FD_SET(sfd,&rdset);
		ret=select(sfd+1,&rdset,NULL,NULL,NULL);
		if(ret >0)
		{
			if(FD_ISSET(0,&rdset))
			{
				bzero(buf,sizeof(buf));
				ret=read(0,buf,sizeof(buf));
				if(ret >0)
				{
					send(sfd,buf,strlen(buf)-1,0);
				}else{
					send(sfd,"bye",3,0);
					break;
				}
			}
			if(FD_ISSET(sfd,&rdset))
			{
				bzero(buf,sizeof(buf));
				ret=recv(sfd,buf,sizeof(buf),0);
				if(ret >0)
				{
					printf("%s\n",buf);
					if(!strcmp(buf,"bye"))
					break;
				}
			}
		}
	}
close(sfd);
return 0;
}	
