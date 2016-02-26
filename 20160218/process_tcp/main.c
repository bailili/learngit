#include "head.h"
#define NUM 10
int main(int argc,char* argv[])
{
	if(argc !=4)
	{
		printf("error args\n");
		return -1;
	}
	pchild cp;
	int num=atoi(argv[3]);
	cp=(pchild)calloc(num,sizeof(child));
	make_child(cp,num);
	
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	bind(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	listen(sfd,NUM);
	
	int epfd;
	epfd=epoll_create(1);
	struct epoll_event ev,*evs;
	evs=(struct epoll_event*)calloc(num+1,sizeof(struct epoll_event));
	
	ev.events=EPOLLIN;
	ev.data.fd=sfd;
	epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&ev);
	
	int i;
	for(i=0;i<num;i++)
	{
		ev.events=EPOLLIN;
		ev.data.fd=cp[i].fds[0];
		epoll_ctl(epfd,EPOLL_CTL_ADD,cp[i].fds[0],&ev);	
	}
	int ret;
	int j;
	int newfd;
	while(1)
	{
		ret=epoll_wait(epfd,evs,num+1,-1);
		if(ret >0)
		{
			for(i=0;i<ret;i++)
			{
				if(evs[i].data.fd==sfd)
				{
					newfd=accept(sfd,NULL,NULL);
					printf("one success! client newfd is %d\n",newfd);
					for(j=0;j<num;j++)
					{
						if(cp[i].busy=0)
						{
							break;	
						}
					}
					if(j!=num)
					{
						send_fd(cp[i].fds[1],newfd);
					}
				}
				
			}	
		}
	}
	return 0;
}
