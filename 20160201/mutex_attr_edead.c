#include <string.h>
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;

void* p_func(void* p)
{
	int ret;
	ret=pthread_mutex_lock(&mutex);
	printf("lock_1 ret is %d\n",ret);
	ret=pthread_mutex_lock(&mutex);
	if(0!=ret)
	{
		printf("lock_2 ret is %d\n",ret);
	}
	printf("child\n");
	pthread_mutex_unlock(&mutex);
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}
int main()
{
	int ret;
	pthread_mutexattr_t attr;
	int i;
	i=PTHREAD_MUTEX_ERRORCHECK_NP;
	memcpy(&attr,&i,4);	
	pthread_mutex_init(&mutex,&attr);
	pthread_t thid;
	pthread_create(&thid,NULL,p_func,NULL);
	pthread_join(thid,NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}
