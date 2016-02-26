#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sigl(int signum)
{
	printf("the signum is %d\n",signum);
}

int main()
{
	signal(SIGINT,sigl);
	while(1);
	return 0;
}
