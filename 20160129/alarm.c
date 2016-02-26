#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sig(int s)
{
	printf("the s is %d\n",s);
}

int main()
{
	signal(SIGALRM,sig);
	alarm(3);
	while(1);
	return 0;
}
