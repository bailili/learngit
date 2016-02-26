#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGINT);
	sigprocmask(SIG_BLOCK,&set,NULL);
	sleep(5);
	sigemptyset(&set);
	sigpending(&set);
	if(1==sigismember(&set,SIGINT))
	{
		printf("the SIGINT is pending\n");
	}
	while(1);
	return 0;
}	
