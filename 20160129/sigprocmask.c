#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGINT);
	sigprocmask(SIG_BLOCK,&set,NULL);
	while(1);
	return 0;
}
