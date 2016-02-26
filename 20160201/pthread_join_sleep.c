#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *p_func(void *p)
{
	printf("child\n");
	sleep(3);		
	pthread_exit(NULL);
}
int main()
{
	pthread_t pthid;
	pthread_create(&pthid,NULL,p_func,NULL);
	int ret;
	ret=pthread_join(0,NULL);
	if(0!=ret)
	{
		printf("pthread_join ret is %d\n",ret);
		return -1;
	}
	return 0;
}		
