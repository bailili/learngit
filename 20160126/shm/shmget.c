#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main(int argc,char* argv[])
{
	if(argc !=2)
	{	
		printf("error args.\n");
		return -1;
	}
	key_t key;
	key=ftok(argv[1],1);
	int shmid;
	shmid=shmget(key,1<<11,0600|IPC_CREAT);
	if(shmid==-1)
	{
		perror("shmget");
		return -1;
	}
	printf("the shmid is %d\n",shmid);
 	return 0;
}
