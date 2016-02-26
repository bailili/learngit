#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;

void* p_func(void* p)
{
	pthread_mutex_lock(&mutex);
	printf("the child lock\n");
	while(1);
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}
int main()
{
	pthread_mutex_init(&mutex,NULL);
	pthread_t thid;
	pthread_create(&thid,NULL,p_func,NULL);
	sleep(2);
	int ret=pthread_mutex_trylock(&mutex);
	printf("pthread_mutex_trylock ret is %d\n",ret);
	pthread_join(thid,NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}		
