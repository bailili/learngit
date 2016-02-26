#include <stdio.h>
#include <stdlib.h>

int add(int a,int b)
{
	return a+b;
}

void main(int argc,char* argv[])
{
	if(argc !=3)
	{
		printf("the args is error\n");
		return;
	}
	int a,b;
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	printf("the sum is %d\n",add(a,b));
}
