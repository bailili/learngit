#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
int main(int argc,char** argv)
{
	if(argc !=2)
	{
		printf("error args\n");
		return -1;
	}
	int fd=open(argv[1],O_RDWR);
	char buf1[30]="My name is BaiLyly.\n";
	char buf2[20]="I am great!\n";
	struct iovec io[2];
	io[0].iov_base=buf1;
	io[0].iov_len=30;
	io[1].iov_base=buf2;
	io[1].iov_len=20;
	writev(fd,io,2);
	close(fd);
	return 0;
}
