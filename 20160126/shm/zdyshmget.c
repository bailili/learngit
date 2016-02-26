#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	if(argc !=2)
	{
		printf("error args\n");
		return -1;
	}
	int shmid;
	shmid=shmget(IPC_PRIVATE,1<<11,0666|IPC_CREAT);
	if(shmid==-1)
	{
		perror("shmget");
		return -1;
	}
	printf("shmid is %d\n",shmid);
	return 0;
}
