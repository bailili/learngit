#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
		pid_t pid;
		pid = fork();
		if(0==pid)
		{
				printf("I am son\n");
				while(1);				
		}else{
				int status;
				int ret;
				ret=waitpid(pid,&status,0);
				printf("ret is %d\n",ret);
				if(ret<0)
				{
						perror("waitpid");
						return -1;
				}
				if(ret>0)
				{
					if(WIFEXITED(status))
				{
						printf("process return is %d\n",WEXITSTATUS(status));
				}
				}
		        return 0;
		}
}


