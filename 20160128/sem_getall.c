#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <strings.h>

int main()
{
	int semid;
	semid=semget((key_t)9,4,0600|IPC_CREAT);
	if(-1==semid)
	{
		perror("semget");
		return -1;
	}
	
	unsigned short arr[4];
	
	int ret;	
	ret=semctl(semid,0,GETALL,arr);
	if(-1==ret)
	{
		perror("semctl");
		return -1;
	}
	printf("s1=%d, s2=%d, s3=%d, s4=%d\n",arr[0],arr[1],arr[2],arr[3]);
	return 0;
}
