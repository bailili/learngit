#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
	
int main()
{
	int shmid;
	shmid=shmget((key_t)5,1<<11,0600|IPC_CREAT);
	int* p;
	p=(int*)shmat(shmid,NULL,0);
	*p=0;
	printf("*p is %d\n",*p);
	return 0;
}		
