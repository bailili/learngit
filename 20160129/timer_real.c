#include <stdio.h>
#include <signal.h>
#include <strings.h>
#include <sys/time.h>
#include <time.h>
void sig(int s)
{
	time_t tp;
	time(&tp);
	printf("%s\n",ctime(&tp));
}		
int main()
{
	signal(SIGALRM,sig);
	struct itimerval im;
	bzero(&im,sizeof(im));
	im.it_value.tv_sec=5;
	im.it_interval.tv_sec=2;
	setitimer(ITIMER_REAL,&im,NULL);
	while(1);
	return 0;
}
