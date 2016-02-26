#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void cleanup(void* p)
{
	printf("child\n");
	printf("qingli child\n");
	free(p);
	p=NULL;
}
void* p_func(void* p1)
{
	char* p=(char*)malloc(10);
	pthread_cleanup_push(cleanup,p);
	sleep(4);
	pthread_cleanup_pop(1);
}
int main()
{
	pthread_t thid;
	pthread_create(&thid,NULL,p_func,NULL);
	int ret=pthread_join(thid,NULL);
	if(0!=ret)
	{
		printf("pthread_join ret is %d\n",ret);
		return -1;
	}
	return 0;
}
