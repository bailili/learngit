#include "ftp.h"
int main(int argc,char* argv[])
{
	if(argc!=4)
	{
		printf("error args\n");
		return -1;
	}
	
	//创建num个子进程
	pchild cptr;
	int num=atoi(argv[3]);
	cptr=(pchild)calloc(num,sizeof(child));
	make_child(cptr,num);
	
	//进行socket通信
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	int ret;
	bind(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	listen(sfd,num);
	int epfd=epoll_create(1);
	struct epoll_event ev,*evs;
	evs=(struct epoll_event*)calloc(num+1,sizeof(struct epoll_event));
	ev.events=EPOLLIN;
	ev.data.fd=sfd;
	epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&ev);
	int i;
	for(i=0;i<num;i++)
	{
		ev.events=EPOLLIN;
		ev.data.fd=cptr[i].fds;
		epoll_ctl(epfd,EPOLL_CTL_ADD,cptr[i].fds,&ev);
	}
	int size;
	int flag;
	int j;
	int newfd;
	while(1)
	{
		ret=epoll_wait(epfd,evs,num+1,-1);
		if(ret >0)
		{
			for(i=0;i<ret;i++)
			{
				if(evs[i].data.fd==sfd && evs[i].events==EPOLLIN)
				{
					newfd=accept(sfd,NULL,NULL);
					printf("one client connect,newfd =%d\n",newfd);
					for(j=0;j<num;j++)
					{
						if(cptr[i].busy==0)
						{
							break;
						}
					}
					if(j!=num)
					{
						send_fd(cptr[i].fds,newfd);
						cptr[i].busy=1;
						printf("child %d is busy\n",j);
					}				
				}
				for(j=0;j<num;j++)
				{
					if(evs[i].data.fd==cptr[j].fds&&evs[i].events==EPOLLIN)
					{
						size=read(cptr[j].fds,&flag,4);
						printf("size if %d\n",size);
						cptr[j].busy=0;
						printf("child %d is not busy\n",j);
					}
				}
			}
		}
	}
return 0;
}
