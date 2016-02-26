#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
	if(argc !=2)
	{
		printf("error args\n");
		return -1;
	}
	int fdr;
	fdr=open(argv[1],O_RDONLY);
	if(-1==fdr)
	{
		perror("open");
		return -1;
	}
	char buf[128];
	while(bzero(buf,sizeof(buf)),read(fdr,buf,sizeof(buf))>0)
	{
		printf("%s\n",buf);
	}
	close(fdr);
	return 0;
}	
