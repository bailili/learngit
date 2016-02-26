#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
	int semid;
	semid=semget((key_t)5,1,0600|IPC_CREAT);
	int ret;
	ret=semctl(semid,0,GETVAL);
	printf("the ret is %d\n",ret);
	printf("the semid is %d\n",semid);
	return 0;
}
