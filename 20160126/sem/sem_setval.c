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
	printf("the value is %d\n",ret);

	ret=semctl(semid,0,SETVAL,1);
	printf("the value set return is %d\n",ret);
	
	ret=semctl(semid,0,GETVAL);
	printf("the value set is %d\n",ret);

	return 0;
}
