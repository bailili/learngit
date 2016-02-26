#include <string.h>
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;

void* p_func(void* p)
{
	pthread_mutex_lock(&mutex);
	pthread_mutex_lock(&mutex);
	printf("child\n");
	pthread_mutex_unlock(&mutex);
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}
	
int main()
{
	pthread_mutexattr_t attr;
	int i;
	i=PTHREAD_MUTEX_RECURSIVE_NP;
	memcpy(&attr,&i,4);
	pthread_mutex_init(&mutex,&attr);
	pthread_t thid;
	pthread_create(&thid,NULL,p_func,NULL);
	int ret=pthread_join(thid,NULL);
	if(0!=ret)
	{
		printf("pthread_join ret is %d\n",ret);
		return -1;
	}
	ret=pthread_mutex_destroy(&mutex);
	return 0;
}


