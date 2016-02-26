#include "head.h"
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
