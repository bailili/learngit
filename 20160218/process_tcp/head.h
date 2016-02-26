#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define DOWM_FILE "file"
typedef struct process_child{
	int pid;
	int fds[2];
	int busy;
}child,*pchild;

void make_child(pchild,int);
void child_handle();
void send_fd(int,int);
