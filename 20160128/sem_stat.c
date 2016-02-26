#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>

int main()
{
	int semid;
	semid=semget((key_t)9,0,IPC_CREAT);
	if(-1==semid)
	{	
		perror("semget");
		return -1;
	}
	
	struct semid_ds buf;
	int ret;
	ret=semctl(semid,0,IPC_STAT,&buf);
	if(-1==ret)
	{
		perror("semctl");
		return -1;
	}
	printf("uid=%d, cuid=%d, mode=%u, nsem=%lu\n",buf.sem_perm.uid,buf.sem_perm.cuid,buf.sem_perm.mode,buf.sem_nsems);
	return 0;
}
		
	
