#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>

int main(int argc,char* argv[])
{
	if(argc !=2)
	{
		printf("error args\n");
		return -1;
	}
	key_t key;
	key=ftok(argv[1],1);
	printf("the key is %d\n",key);
return 0;
}	
