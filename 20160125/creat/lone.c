#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
		if(0==fork())
		{
				printf("I am son_P\n");
				while(1);
		}else{
				exit(0);
		}
}
