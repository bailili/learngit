#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	if(fork()>0)
	{
		exit(0);
	}
	setsid();
	chdir("/");
	umask(0);
	int i;
	for(i=0;i<3;i++)
		close(i);
	while(1);
	return 0;
}

