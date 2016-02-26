#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigchuli(int signum)
{
	printf("the signum is %d\n",signum);
	sleep(4);
	printf("after ...signum is %d\n",signum);
}

int main()
{
	signal(SIGINT,sigchuli);
	signal(SIGQUIT,sigchuli);
	while(1);
	return 0;
}
