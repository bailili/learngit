#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void sig(int sig)
{
	printf("the sigid is %d\n",sig);
}

int main()
{
	signal(SIGINT,sig);
	int ret;
	ret=kill(getpid(),SIGINT);
	if(-1==ret)
	{
		perror("kill");
		return -1;
	}
	return 0;
}
