#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
		if(0==fork())
		{
				printf("I am son\n");
				exit(0);
		}else{
				int status;
				int ret;
				ret=wait(&status);
				if(ret<0)
				{
						perror("wait");
						return -1;
				}
				printf("the pid js %d\n",ret);
				if(WIFEXITED(status))
				{
						printf("process return is %d\n",WEXITSTATUS(status));
				}
				return 0;
		}
}	
