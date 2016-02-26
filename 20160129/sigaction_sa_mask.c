#include <signal.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>

void sigcl(int signum,siginfo_t* p,void* p2)
{
	printf("the sig is %d\n",signum);
	sleep(3);
	printf("... sig is %d\n",signum);
}

int main()
{
	struct sigaction act;
	bzero(&act,sizeof(act));
	act.sa_sigaction=sigcl;
	sigset_t sa_mask;
	sigemptyset(&act.sa_mask);
	act.sa_flags=SA_SIGINFO|SA_NODEFER;
	
	sigaddset(&act.sa_mask,SIGQUIT);

	int ret;
	ret=sigaction(SIGINT,&act,NULL);
	if(-1==ret)
	{
		perror("sigaction");
		return -1;
	}

	while(1);
	return 0;
}	
