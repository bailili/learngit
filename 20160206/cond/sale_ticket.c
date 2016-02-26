#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM 2
pthread_mutex_t mutex;
pthread_cond_t cond;
int ticket=10;

void* sale_func(void *p)
{
	long i = (long)p;
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if(ticket > 0)
		{
			printf("I am windows %lu,ticket=%d\n",i,ticket);
			ticket--;
			if(0 == ticket)
				pthread_cond_signal(&cond);
			printf("I am windows %lu,sale finish, ticket=%d\n",i,ticket);
		}else{
			pthread_mutex_unlock(&mutex);
			pthread_exit(NULL);
		}
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}	
}

void* set_func(void* p)
{
	pthread_mutex_lock(&mutex);
	if(ticket > 0)
	{
		pthread_cond_wait(&cond,&mutex);
	}
	ticket = 10;
	sleep(5);
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}	
int main()
{
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);
	pthread_t sale[NUM],setticket;
	long i;
	for(i=0;i<NUM;i++)
	{
		pthread_create(&sale[i],NULL,sale_func,(void*)i);
	}	
	pthread_create(&setticket,NULL,set_func,NULL);
	for(i=0;i<NUM;i++)
	{
		pthread_join(sale[i],NULL);
	}
	pthread_join(setticket,NULL);
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	return 0;
}
