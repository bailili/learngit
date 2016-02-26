#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>       
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
void send_fd(int sfd,int fd)
{
	struct msghdr msg;
	bzero(&msg,sizeof(struct msghdr));
	char buf1[5]="China";
	char buf2[5]="world";
	struct iovec io[2];
	io[0].iov_base=buf1;
	io[0].iov_len=5;
	io[1].iov_base=buf2;
	io[1].iov_len=5;
	msg.msg_iov=io;
	msg.msg_iovlen=2;
	struct cmsghdr *cmsg;
	int len=CMSG_LEN(sizeof(int));
	cmsg=(struct cmsghdr*)calloc(1,len);
	cmsg->cmsg_len=len;
	cmsg->cmsg_level=SOL_SOCKET;
	cmsg->cmsg_type=SCM_RIGHTS;
	int *fdp;
	fdp=(int *)CMSG_DATA(cmsg);
	*fdp=fd;
	msg.msg_control=cmsg;
	msg.msg_controllen=len;
	int ret=sendmsg(sfd,&msg,0);
	if(-1==ret)
	{
		perror("sendmsg");
		return ;
	}	
}
void recv_fd(int sfd,int* fd)
{
	struct msghdr msg;
	bzero(&msg,sizeof(struct msghdr));
	char buf1[5]={0};
	char buf2[5]={0};
	struct iovec io;
	io.iov_base=buf1;
	io.iov_len=5;
//	io[1].iov_base=buf2;
//	io[1].iov_len=5;
	msg.msg_iov=&io;
	msg.msg_iovlen=1;
	struct cmsghdr *cmsg;
	int len=CMSG_LEN(sizeof(int));
	cmsg=(struct cmsghdr*)calloc(1,len);
	cmsg->cmsg_len=len;
	cmsg->cmsg_level=SOL_SOCKET;
	cmsg->cmsg_type=SCM_RIGHTS;
	msg.msg_control=cmsg;
	msg.msg_controllen=len;
	recvmsg(sfd,&msg,0);
	int * fdp=(int *)CMSG_DATA(cmsg);
	*fd=*fdp;
}
int main(int argc,char** argv)
{
	if(argc !=2)
	{
		printf("error args\n");
		return -1;
	}
	int sfd[2];
	int ret;
	ret=socketpair(AF_LOCAL,SOCK_STREAM,0,sfd);
	if(-1==ret)
	{
		perror("socketpair");
		return -1;
	}
	if(fork())
	{
		close(sfd[0]);
		int fd=open(argv[1],O_RDWR);
		printf("father,fd is %d\n",fd);
		send_fd(sfd[1],fd);
		wait(NULL);
		exit(0);
	}else{
		close(sfd[1]);
		int fd;
		recv_fd(sfd[0],&fd);
		printf("child,fd is %d\n",fd);
		char buf[128]={0};
		read(fd,buf,sizeof(buf));
		printf("buf is %s\n",buf);
		exit(0);	
	}
return 0;
}
