#include "ftp.h"
void send_fd(int fds,int fd)
{
	struct msghdr msg;
	bzero(&msg,sizeof(struct msghdr));
	char buf[10]="hello";
	struct iovec iov;
	iov.iov_base=buf;
	iov.iov_len=5;
	msg.msg_iov=&iov;
	msg.msg_iovlen=1;
	struct cmsghdr* cmsg;
	int len=CMSG_LEN(sizeof(int));
	cmsg=(struct cmsghdr*)calloc(1,len);
	cmsg->cmsg_len=len;
	cmsg->cmsg_level=SOL_SOCKET;
	cmsg->cmsg_type=SCM_RIGHTS;
	int *fdptr;
	fdptr=(int *)CMSG_DATA(cmsg);
	*fdptr=fd;
	msg.msg_control=cmsg;
	msg.msg_controllen=len;
	sendmsg(fds,&msg,0);
}

void recv_fd(int fds,int *fd)
{
	struct msghdr msg;
	bzero(&msg,sizeof(struct msghdr));
	char buf[10]={0};
	struct iovec iov;
	iov.iov_base=buf;
	iov.iov_len=5;
	msg.msg_iov=&iov;
	msg.msg_iovlen=1;
	struct cmsghdr* cmsg;
	int len=CMSG_LEN(sizeof(int));
	cmsg=(struct cmsghdr*)calloc(1,len);
	cmsg->cmsg_len=len;
	cmsg->cmsg_level=SOL_SOCKET;
	cmsg->cmsg_type=SCM_RIGHTS;
	msg.msg_control=cmsg;
	msg.msg_controllen=len;
	recvmsg(fds,&msg,0);
	int *fdptr;
	*fd=*(int *)CMSG_DATA(cmsg);
}

