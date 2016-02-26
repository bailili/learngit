#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

char* p;
void * p_func(void *p)
{	
	printf("child\n");
	p=(char*)malloc(10);
//	strcpy(p,"world");
//	free(p);
//	p=NULL;
	pthread_exit(NULL);
}
int main()
{
	pthread_t thid;
	pthread_create(&thid,NULL,p_func,NULL);
	int ret;
	ret=pthread_join(thid,NULL);
	if(0!=ret)
	{
		printf("pthread_join ret is %d\n",ret);
		return -1;
	}
//	strcpy(p,"HELLO");
	printf("the &p is %x\n",p);
	printf("the p is %s\n",p);
	return 0;
}	
