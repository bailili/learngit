#include <sys/time.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

pthread_cond_t cond;
pthread_mutex_t mutex;
int ret;

void* p_func(void *p)
{
	struct timespec ts;
	struct timeval now;
	bzero(&ts,sizeof(ts));
	gettimeofday(&now,NULL);
	ts.tv_sec=now.tv_sec+5;
	pthread_mutex_lock(&mutex);
	printf("I am child.I am lock!\n");
	ret=pthread_cond_timedwait(&cond,&mutex,&ts);
	if(0!=ret)
	{
		printf("pthread_cond_timedwait ret is %d\n",ret);
	}
	printf("I am child.I am wake!\n");
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}
int main()
{
	pthread_cond_init(&cond,NULL);
	pthread_mutex_init(&mutex,NULL);
	pthread_t pthid;
	pthread_create(&pthid,NULL,p_func,NULL);
	sleep(1);
//	pthread_cond_signal(&cond);
	pthread_join(pthid,NULL);
	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&mutex);
	return 0;
}
