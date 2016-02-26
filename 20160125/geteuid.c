#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc,char* argv[])
{
	printf("uid=%d gid=%d euid=%d egid=%d\n",getuid(),getgid(),geteuid(),getegid());
	if(argc !=2)
	{
		printf("error args\n");
		return -1;
	}
	int fd=open(argv[1],O_RDWR);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	int ret;
	ret=write(fd,"dodododo",8);
	if(ret<0)
	{
		perror("write");
		return -1;
	}
	return 0;
}
