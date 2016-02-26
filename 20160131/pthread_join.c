#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* pthread_entry(void* p)
{
	int i;
	for(i=0;i<20;i++)
	{
		printf("child thread\n");
		sleep(1);
	}
}
int main()
{
	pthread_t id;
	pthread_create(&id,NULL,pthread_entry,(void*)3);
	int i;
	for(i=0;i<20;i++)
	{
		printf("main thread\n");
		sleep(1);
	}
	return 0;
}
