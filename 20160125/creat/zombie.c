#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	if(0==fork())
	{
		printf("I am son_P");
		exit(0);
	}else{
			while(1);
		}
	return 0;
}
			
