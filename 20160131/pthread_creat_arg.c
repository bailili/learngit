#include <stdio.h>
#include <pthread.h>

void* pthread_entry(void* p)
{
	printf("the p is %d\n",(int)p);
}
int main()
{
	pthread_t id;
	pthread_create(&id,NULL,pthread_entry,(void*)1);
	while(1);
	return 0;
}
