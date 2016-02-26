#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char* argv[])
{
	if(argc !=2)
	{
		printf("error args\n");
		return -1;
	}
	int fdw;
	fdw=open(argv[1],O_WRONLY);
	char buf[128];
	while(bzero(buf,sizeof(buf)),read(STDIN_FILENO,buf,sizeof(buf))>0)
	{	
		write(fdw,buf,strlen(buf));
	}
	return 0;
}
