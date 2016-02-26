#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#define NUM 3
pthread_cond_t cond;
pthread_mutex_t mutex;

void *p_func(void* p)
{
	long k;
	k=(long)p;
	pthread_mutex_lock(&mutex);
	printf("I am child%luth.I am lock!\n",k);
	pthread_cond_wait(&cond,&mutex);
	printf("I am child%luth.I am wake!\n",k);
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}
int main()
{
	pthread_cond_init(&cond,NULL);
	pthread_mutex_init(&mutex,NULL);
	pthread_t pthid[NUM];
	long i;
	for(i=0;i<NUM;i++)
	{
		pthread_create(&pthid[i],NULL,p_func,(void *)i);
	}
	sleep(1);
	pthread_cond_broadcast(&cond);
	for(i=0;i<NUM;i++)
	{
		pthread_join(pthid[i],NULL);
	}
	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&mutex);
	return 0;
}	
