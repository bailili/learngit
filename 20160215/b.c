#include <unistd.h>
#include <strings.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[])
{
	if(argc !=2)
	{	
		printf("error args\n");
		return -1;
	}
	int fdw;
	fdw=open(argv[1],O_WRONLY);
	if(-1==fdw)
	{
		perror("open");
		return -1;
	}
	char buf[128];
	int ret;
	while(bzero(buf,sizeof(buf)),(ret=read(STDIN_FILENO,buf,sizeof(buf)))>0)
	{
		write(fdw,buf,ret-1);
	}
	close(fdw);
	return 0;
}
