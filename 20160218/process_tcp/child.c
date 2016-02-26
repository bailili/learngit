#include "head.h"

void make_child(pchild cp,int n)
{
	int fds[2];
	int pid;
	int i;
	for(i=0;i<n;i++)
	{
		socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
		pid=fork();
		if(pid==0)
		{
			child_handle();	
		}
		cp[i].pid=pid;
		cp[i].fds[0]=fds[0];
		cp[i].fds[1]=fds[1];
		cp[i].busy=0;
	}
	
}

void child_handle()
{
	while(1);	
}		
