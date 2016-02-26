#include <stdio.h>
#include <strings.h>

int main()
{
	FILE* fp;
	fp=popen("ls -l","r");
	if(NULL==fp)
	{
		perror("popen");
		return -1;
	}
	char buf[512];
	bzero(buf,sizeof(buf));
	int ret=fread(buf,1,512,fp);
	if(ret>0)
	{
		printf("%s\n",buf);
	}
	return 0;
}	
