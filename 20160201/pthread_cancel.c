#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* p_func(void * p)
{
	printf("child\n");
	while(1);
	pthread_exit(NULL);	
}
int main()
{
	pthread_t thid;
	pthread_create(&thid,NULL,p_func,NULL);
	sleep(2);
	int ret;
	ret=pthread_cancel(thid);
	if(0!=ret)
	{
		printf("pthread_cancel ret is %d\n",ret);
		return -1;
	}
	return 0;
}	
