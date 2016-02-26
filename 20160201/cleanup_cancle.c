#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void cleanup(void* p)
{
	printf("child exit\n");
}
void* p_func(void* p)
{
	pthread_cleanup_push(cleanup,NULL);
	sleep(5);
	pthread_cleanup_pop(0);
}
int main()
{
	pthread_t thid;
	pthread_create(&thid,NULL,p_func,NULL);
	int ret=pthread_cancel(thid);
	if(0!=ret)
	{
		printf("pthread_cancle ret is %d\n",ret);
		return -1;
	}
	ret=pthread_join(thid,NULL);
	if(0!=ret)
	{
		printf("pthread_join ret is %d\n",ret);
		return -1;
	}
	
	return 0;
}
