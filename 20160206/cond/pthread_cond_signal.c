#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

pthread_cond_t cond;
pthread_mutex_t mutex;

void* p_func(void* p)
{
	pthread_mutex_lock(&mutex);	
	printf("I am child.I lock\n");
	pthread_cond_wait(&cond,&mutex);
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
	pthread_mutex_lock(&mutex);
	printf("I am main.I lock\n");
	pthread_mutex_unlock(&mutex);
	pthread_cond_signal(&cond);
	pthread_join(pthid,NULL);
	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&mutex);
	return 0;
}
