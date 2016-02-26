#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <strings.h>
#include <unistd.h>
void sigcl(int sign,siginfo_t* p,void *p2)
{
	printf("the sig is %d\n",sign);
	sleep(4);
	printf("... sig is %d\n",sign);
}
int main()
{
	struct sigaction act;
	bzero(&act,sizeof(act));
	act.sa_sigaction=sigcl;
	sigset_t sa_mask;
	sigemptyset(&act.sa_mask);
	act.sa_flags=SA_SIGINFO;

	int ret;

	ret=sigfillset(&act.sa_mask);
	if(-1==ret)
	{
		perror("sigfillset");
		return -1;
	}
	
	ret=sigaction(SIGQUIT,&act,NULL);
	if(-1==ret)
	{
		perror("sigaction");
		return -1;
	}

	ret=sigaction(SIGINT,&act,NULL);
	if(-1==ret)
	{
		perror("sigaction");
		return -1;
	}
	while(1);
	return 0;
}	
