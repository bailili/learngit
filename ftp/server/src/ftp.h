#include <strings.h>
#include <sys/epoll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <fcntl.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <signal.h>
#define DOWN_FILE "file"

typedef struct pro_child{
	pid_t pid;
	int fds;
	int busy;
}child,*pchild;

typedef struct tdata{
	int len;
	char buf[1000];
}data_t,*pdata_t;

void make_child(pchild,int);
void child_handle(int);
void send_fd(int,int);
void recv_fd(int,int *);
void send_file(int,char*);
void send_n(int,char*,int);
void recv_request(int);
void do_cd(int,char*);
void do_ls(int,char*);
void myscandir(char*,int,char*);
void do_pwd(int,char*);
void do_remove(int,char*);
void do_gets(int,char*);
void do_puts(int);
