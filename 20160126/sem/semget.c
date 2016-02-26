#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>

int main()
{
	int semid;
	semid=semget((key_t)5,5,0600|IPC_CREAT);
	printf("the semid is %d\n",semid);
	return 0;
}
