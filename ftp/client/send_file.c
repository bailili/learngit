#include "ftp.h"
void send_file(int sfd,char* file)
{
	int ret;
	data_t buf;
	buf.len=strlen(file);
	strcpy(buf.buf,file);
	send(sfd,&buf,buf.len+4,0);
	int fd=open(file,O_RDONLY);
	while(bzero(&buf,sizeof(buf)),(buf.len=read(fd,buf.buf,sizeof(buf.buf)))>0)
	{
		send_n(sfd,(char*)&buf,buf.len+4);
	}
	bzero(&buf,sizeof(buf));
	int flag=0;
	buf.len=sizeof(int);
	memcpy(buf.buf,&flag,4);
	send(sfd,&buf,buf.len+4,0);
	close(sfd);
	return;

}


void send_n(int sfd,char* p,int len)
{
	int total=0;
	int size=0;
	while(total<len)
	{
		size=send(sfd,p+total,len-total,0);
		total=total+size;
	}
}
