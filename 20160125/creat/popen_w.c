#include <stdio.h>
#include <strings.h>
#include <string.h>

int main()
{
	FILE* fp;
	fp = popen("./scanf","w");
	char buf[512];
	bzero(buf,sizeof(buf));
	strcpy(buf,"123");
	fwrite(buf,1,strlen(buf),fp);
	pclose(fp);
	return 0;
}	
