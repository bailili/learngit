#include <stdio.h>
#include <signal.h>
#include <strings.h>
#include <stdlib.h>

void siga(int sign,siginfo_t* p,void* p1)
{
	printf("sig is %d, send pid is %d\n",sign,p->si_pid);
}

int main()
{
	struct sigaction act;
	bzero(&act,sizeof(act));
	act.sa_sigaction=siga;
	sigset_t sa_mask;
	sigemptyset(&act.sa_mask);
	act.sa_flags=SA_SIGINFO;
	sigaction(SIGINT,&act,NULL);
	while(1);
	return 0;
}
