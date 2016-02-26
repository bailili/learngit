#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void sigchuli(int signum)
{
	printf("the signum is %d\n",signum);
}

int main()
{
	signal(SIGINT,sigchuli);
	char buf[10];
	memset(buf,0,sizeof(buf));
	read(0,buf,sizeof(buf));
	printf("the buf is %s\n",buf);
	return 0;
}
