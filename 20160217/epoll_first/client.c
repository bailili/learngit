#include "func.h"
int main(int argc,char** argv)
{
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	connect(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	printf("connect success!\n");
	
	int epfd=epoll_create(1);
	struct epoll_event ev,evs[2];
	ev.data.fd=sfd;
	ev.events=EPOLLIN;
	epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&ev);
	ev.data.fd=0;
	ev.events=EPOLLIN;
	epoll_ctl(epfd,EPOLL_CTL_ADD,0,&ev);
	int ret;
	int i;
	int ret1;
	char buf[128];

	while(1)
	{
		bzero(evs,sizeof(evs));
		ret=epoll_wait(epfd,evs,2,-1);
		if(ret >0)
		{
			for(i=0;i<ret;i++)
			{
				if(evs[i].data.fd==0 && evs[i].events==EPOLLIN)
				{
					bzero(buf,sizeof(buf));
					read(0,buf,sizeof(buf));
					send(sfd,buf,strlen(buf)-1,0);
				}
				if(evs[i].data.fd==sfd)
				{
					bzero(buf,sizeof(buf));
					ret1=recv(sfd,buf,sizeof(buf),0);
					if(ret1 >0)
					{
						printf("%s\n",buf);
					}else{
						close(sfd);
						return 0;
					}
				}
			}
		}
	}
close(sfd);
return 0;
}
						
