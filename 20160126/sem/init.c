#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc,char* argv[])
{
	int shmid;
	shmid=shmget((key_t)8,1<<11,0600|IPC_CREAT);
	if(-1==shmid)
	{
		perror("shmget");
		return -1;
	}
	printf("the shmid is %d\n",shmid);
	int *p;
	p=(int*)shmat(shmid,NULL,0);
	if((int*)-1==p)
	{
		perror("shmat");
		return -1;
	}
	*p=0;
	printf("the value is %d\n",*p);
	return 0;
}	
