#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void cleanup(void* p)
{
	printf("the p is %ld\n",(long)p);
}
void* p_func(void *p)
{
	pthread_cleanup_push(cleanup,(void*)1);
	pthread_cleanup_push(cleanup,(void*)2);
	sleep(3);
	pthread_exit(NULL);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
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
