#include <stdio.h>
#include <pthread.h>

int main()
{
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex,NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}
