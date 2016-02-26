#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <strings.h>

#define TIMES 10000000

int main()
{
	int shmid;
	shmid=shmget((key_t)5,1<<11,IPC_CREAT);
	int *p;
	p=(int*)shmat(shmid,NULL,0);
	int semid;
	
	semid=semget((key_t)5,0,IPC_CREAT);
	
	struct sembuf sop;
	bzero(&sop,sizeof(sop));
	sop.sem_num=0;
	sop.sem_op=-1;
	sop.sem_flg=SEM_UNDO;
	
	struct sembuf sov;
	bzero(&sov,sizeof(sov));
	sov.sem_num=0;
	sov.sem_op=1;
	sop.sem_flg=SEM_UNDO;
	
	int i;
	for(i=0;i<TIMES;i++)
	{
		semop(semid,&sop,1);
		*p=(*p)+1;			
		semop(semid,&sov,1);
	}
	printf("the sum1 is %d\n",*p);
	return 0;
}
