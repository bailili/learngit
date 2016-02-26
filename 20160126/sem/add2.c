#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define TIMES 10000000

int main()
{
	int shmid;
	shmid=shmget((key_t)8,1<<11,IPC_CREAT);
	printf("the shmid is %d\n",shmid);
	int *p;
	p=(int*)shmat(shmid,NULL,0);
	printf("*p is %d\n",*p);
	int i;
	for(i=0;i<TIMES;i++)
	{
		*p=(*p)+1;
	}
	printf("the sum2 is %d\n",*p);
	shmdt(p);
	return 0;
}		
