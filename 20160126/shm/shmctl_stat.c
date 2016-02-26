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
	//int* p;
	//p=(int*)shmat(shmid,NULL,0);
	//if(p==(int*)-1)
	//{
	//		perror("shmat");
	//		return -1;
	//}
	//printf("I am here\n");
	//*p=4;
	//while(1);
		int ret;
		struct shmid_ds buf;
		ret=shmctl(shmid,IPC_STAT,&buf);
		if(-1==ret)
		{
			perror("shmctl");
			return -1;
		}
		printf("euid=%d,cuid=%d,mode=%u,size=%lu,cpid=%d,nattch=%lu\n",buf.shm_perm.uid,buf.shm_perm.cuid,buf.shm_perm.mode,buf.shm_segsz,buf.shm_cpid,buf.shm_nattch);
		return 0;
}	
