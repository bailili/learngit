#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main(int argc,char* argv[])
{
		if(argc !=2)
		{
				printf("error args\n");
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
		printf("shmid is %d\n",shmid);
		int* p;
		p=(int*)shmat(shmid,NULL,0);
		if(p==(int*)-1)
		{
				perror("shmat");
				return -1;
		}
		printf("I am here\n");
		*p=4;
		int ret;
		ret=shmctl(shmid,IPC_RMID,NULL);
		if(ret==-1)
		{
			perror("shmctl");
			return -1;
		}
		return 0;
}	
