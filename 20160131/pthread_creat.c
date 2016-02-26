#include <stdio.h>
#include <pthread.h>

void* pthread_entry(void* p)
{
	printf("success\n");
	pthread_exit(NULL);
}
int main()
{
	pthread_t pth_id;
	pthread_create(&pth_id,NULL,pthread_entry,NULL);
	while(1);
	return 0;
}
