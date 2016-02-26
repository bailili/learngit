#include <stdio.h>
#include <pthread.h>

#define NUM 1000000

pthread_mutex_t mutex;
int sum;

void* p_func(void* p)
{
	int i;
	for(i=0;i<NUM;i++)
	{
		pthread_mutex_lock(&mutex);
		sum++;
		pthread_mutex_unlock(&mutex);
	}
	printf("the chile sum is %d\n",sum);
	pthread_exit(NULL);	
}
int main()
{
	pthread_mutex_init(&mutex,NULL);
	pthread_t thid;
	pthread_create(&thid,NULL,p_func,NULL);
	int i;
	for(i=0;i<NUM;i++)
	{		
		pthread_mutex_lock(&mutex);
		sum++;
		pthread_mutex_unlock(&mutex);
	}		
	printf("the sum is %d\n",sum);
	pthread_mutex_destroy(&mutex);
	pthread_join(thid,NULL);
	return 0;
}
