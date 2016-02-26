#include "func.h"
#define NUM 10

void chang_nonblock(int *fd)
{
	int stat;
	stat=fcntl(*fd,F_GETFL);
	stat=stat|O_NONBLOCK;
	fcntl(*fd,F_SETFL,stat);
}
int main(int argc,char** argv)
{
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	bind(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	listen(sfd,NUM);
	
	int epfd=epoll_create(1);
	struct epoll_event ev,evs[3];
	
	ev.data.fd=sfd;
	ev.events=EPOLLIN;
	epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&ev);
	
	ev.data.fd=0;
	ev.events=EPOLLIN;
	epoll_ctl(epfd,EPOLL_CTL_ADD,0,&ev);
	char buf[128];
	int ret;
	int i;
	int newfd=0;
	int ret1;
	while(1)
	{
		bzero(evs,sizeof(evs));
		ret=epoll_wait(epfd,evs,3,-1);
		if(ret >0)
		{
			for(i=0;i<ret;i++)
			{
				if(evs[i].data.fd==sfd)
				{
					newfd=accept(sfd,NULL,NULL);
					printf("connect success!\n");
					chang_nonblock(&newfd);
					ev.data.fd=newfd;
					ev.events=EPOLLIN;
					epoll_ctl(epfd,EPOLL_CTL_ADD,newfd,&ev);
				}
				if(newfd >0)
				{
					if(evs[i].data.fd==newfd)
					{
						while(1)
						{
						bzero(buf,sizeof(buf));
						ret1=recv(newfd,buf,sizeof(buf),0);
						if(ret1 >0)
						{
							printf("%s\n",buf);
						}else{
							if(ret1==-1)
							{
								break;
							}else{
								printf("client close!\n");
								ev.data.fd=newfd;
								ev.events=EPOLLIN;
								epoll_ctl(epfd,EPOLL_CTL_DEL,newfd,&ev);
								newfd=0;
							}
						}		
						}
					//	if(ret1==-1)
						{
//							printf("\n");
						}
					}
					if(evs[i].data.fd==0 && evs[i].events==EPOLLIN)
					{
						bzero(buf,sizeof(buf));
						read(0,buf,sizeof(buf));
						send(newfd,buf,strlen(buf)-1,0);
					}		
				}
			}
		}
	}
	close(sfd);
	return 0;
}			
