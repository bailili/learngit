#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main()
{
	if(fork()==0)
	{
		printf("I am son_P. My pid is %d,my ppid is %d\n",getpid(),getppid());
		exit(0);
	}else{
			printf("I am father_P. My pid is %d,my ppid is %d\n",getpid(),getppid());
			while(1);
		}
			return 0;
}
