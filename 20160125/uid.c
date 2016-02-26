#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
	printf("pid=%d ppid=%d\n",getpid(),getppid());
	while(1);
	return 0;
}
