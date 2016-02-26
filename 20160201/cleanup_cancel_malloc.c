#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void cleanup(void *p)
{
	free(p);
	p=NULL;
	printf("qingli over\n");
}
void *p_func(void *p1)
{
	char*p=(char*)malloc(10);
	pthread_cleanup_push(cleanup,p);
	sleep(3);
	pthread_exit(NULL);
	pthread_cleanup_pop(0);
}
int main()
{
	pthread_t thid;
	pthread_create(&thid,NULL,p_func,NULL);
//	pthread_cancel(thid);
	pthread_join(thid,NULL);
	return 0;
}
