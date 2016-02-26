#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
	if(argc !=2)
	{
		printf("error args\n");
		return -1;
	}
	int fd;
	fd=open(argv[1],O_RDWR|O_CREAT,0600);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	int ret;
	ret=lseek(fd,6,SEEK_SET);
	if(-1==ret)
	{
		perror("lseek");
		close(fd);
		return -1;
	}
	char buf[128];
	bzero(buf,sizeof(buf));
	read(STDOUT_FILENO,buf,sizeof(buf));
	write(fd,buf,strlen(buf));
	close(fd);
	return 0;
}
