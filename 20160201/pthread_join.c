#include <stdio.h>
#include <pthread.h>

void* p_func(void *p)
{
	printf("I am child\n");
	pthread_exit(NULL);
}
int main()
{
	pthread_t thid;
	pthread_create(&thid,NULL,p_func,NULL);
	int ret;
	ret=pthread_join(thid,NULL);	
	if(0 !=ret)
	{
		printf("pthread_join ret is %d\n",ret);
		return -1;
	}
	return 0;
}
