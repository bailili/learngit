#include <stdio.h>
#include <signal.h>
#include <strings.h>
#include <sys/time.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

void sig(int s)
{
	time_t tp;
	time(&tp);
	printf("%s\n",ctime(&tp));
}		
int main()
{
	signal(SIGALRM,sig);
	kill(getpid(),SIGALRM);
	struct itimerval im;
	bzero(&im,sizeof(im));
	im.it_value.tv_sec=5;
	im.it_interval.tv_sec=2;
	setitimer(ITIMER_REAL,&im,NULL);
	sleep(15);
	printf("HELLO WORLD\n");
	while(1);
	return 0;
}
