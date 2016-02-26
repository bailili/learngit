#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig(int s)
{
	printf("the s is %d\n",s);
}

int main()
{
	signal(SIGALRM,sig);
	pause();
	return 0;
}	
