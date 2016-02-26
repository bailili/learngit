#include <signal.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>

void sigcl(int signum,siginfo_t* p,void* p1)
{
	printf("the sig is %d\n",signum);
}

int main()
{
	struct sigaction act;
	bzero(&act,sizeof(act));
	act.sa_sigaction=sigcl;
	sigset_t sa_mask;
	sigemptyset(&act.sa_mask);
	act.sa_flags=SA_SIGINFO|SA_RESTART;

	int ret;	


	ret=sigaction(SIGINT,&act,NULL);
	if(-1==ret)
	{
		perror("sigaction");
		return -1;
	}
	
	
	char buf[10];
	bzero(buf,sizeof(buf));	
	ret=read(0,buf,sizeof(buf));
	printf("the buf is %s\n",buf);
	return 0;
}	
