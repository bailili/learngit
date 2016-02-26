#include <stdio.h>
#include <signal.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>

void sigcl(int sign,siginfo_t *p,void* p1)
{
	printf("the sig is %d\n",sign);
	sleep(5);
	sigset_t set;
	sigemptyset(&set);
	sigpending(&set);
	if(1==sigismember(&set,SIGINT))
	{
		printf("the SIGINT is pending\n");
	}
	if(1==sigismember(&set,SIGQUIT))
	{
		printf("the SIGQUIT is pending\n");
	}
	printf("... sig is %d\n",sign);
}
int main()
{
	struct sigaction act;
	bzero(&act,sizeof(act));
	act.sa_sigaction=sigcl;
	sigset_t sa_mask;
	sigemptyset(&act.sa_mask);
	int ret;
	sigfillset(&act.sa_mask);
	act.sa_flags=SA_SIGINFO|SA_NODEFER;
	sigaction(SIGINT,&act,NULL);
	while(1);
	return 0;
}
