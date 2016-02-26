#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <time.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>

void sig(int s)
{
	time_t tn;
	time(&tn);
	printf("%s\n",ctime(&tn));
}

int main()
{
	signal(SIGPROF,sig);
	kill(getpid(),SIGPROF);
	struct itimerval it;
	bzero(&it,sizeof(it));
	it.it_value.tv_sec=5;
	it.it_interval.tv_sec=2;
	setitimer(ITIMER_PROF,&it,NULL);
	sleep(15);
	printf("sleep over!\n");
	kill(getpid(),SIGPROF);
	printf("retime...\n");
	while(1);
	return 0;
}
