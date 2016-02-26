#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(int argc,char** argv)
{
	if(argc !=2)
	{
		printf("error args\n");
		return -1;
	}
	int fds[2];
	pipe(fds);
	if(!fork())
	{
		close(fds[1]);
		int fd;
		char buf[10]={0};
		read(fds[0],&fd,4);
		printf("fds[0] is %d\n",fds[0]);
		printf("child,fd is %d\n",fd);
		int ret=read(fd,buf,sizeof(buf));
		if(-1==ret)
		{
			perror("read");
			return -1;
		}
		exit(0);
	}else{
		close(fds[0]);
		int fd;
		fd=open(argv[1],O_RDWR);
		write(fds[1],&fd,4);
		printf("father,fd is %d\n",fd);
		write(fd,"hello",5);
		wait(NULL);
		exit(0);
	}
}
			
