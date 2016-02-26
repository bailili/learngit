#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <strings.h>

void sigcl(int signum,siginfo_t* p,void* p1)
{
	printf("the signum is %d\n",signum);
}

int main()
{
	struct sigaction act;
	bzero(&act,sizeof(act));
	act.sa_sigaction=sigcl;
	sigset_t sa_mask;
	sigemptyset(&act.sa_mask);
	act.sa_flags=SA_SIGINFO|SA_RESETHAND;
	
	int ret;
	ret=sigaction(SIGQUIT,&act,NULL);
	if(-1==ret)
	{
		perror("sigaction");
		return -1;
	}
	while(1);
	return 0;
}
