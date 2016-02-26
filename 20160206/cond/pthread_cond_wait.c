#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

int ret;
pthread_cond_t cond;
pthread_mutex_t mutex;

void * p_func(void*p)
{
	pthread_mutex_lock(&mutex);
	printf("I am child.\n");
	ret=pthread_cond_wait(&cond,&mutex);
	if(0!=ret)
	{
		printf("pthread_cond_wait ret is %d\n",ret);
	}
	printf("I am child.Iam wake.\n");
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}	

int main()
{
	pthread_t pthid;
	ret=pthread_cond_init(&cond,NULL);
	if(0!=ret)
	{
		printf("pthread_cond_init ret is %d\n",ret);
		return -1;
	}
	ret=pthread_mutex_init(&mutex,NULL);
	if(0!=ret)
	{
		printf("pthread_mutex_init ret is %d\n",ret);
		return -1;
	}
	pthread_create(&pthid,NULL,p_func,NULL);
    sleep(1);
	pthread_mutex_lock(&mutex);
	printf("I am main.I lock.\n");
	pthread_mutex_unlock(&mutex);
	pthread_join(pthid,NULL);
	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&mutex);
	return 0;
}	
