#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
int main()
{
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGINT);
	sigprocmask(SIG_BLOCK,&set,NULL);
	sleep(5);
	sigprocmask(SIG_UNBLOCK,&set,NULL);
	while(1);
	return 0;
}
