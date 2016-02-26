#include "ftp.h"

int main(int argc,char** argv)
{
	if(argc!=3)
	{
		printf("error args\n");
		return -1;
	}
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	connect(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	printf("connect success\n");

	char buf[2048];
	int ret;
	data_t buff;
	while(1)
	{
		bzero(buf,sizeof(buf));
		ret=read(0,buf,sizeof(buf));
		if(strncmp("gets",buf,4)==0)
		{
			send(sfd,buf,strlen(buf)-1,0);
			bzero(&buff,sizeof(buff));
			recv(sfd,&buff.len,4,0);
			recv(sfd,buff.buf,buff.len,0);
			int fd;
			int flag;
			fd=open(buff.buf,O_RDWR|O_CREAT,0666);
			while(1)
			{
				bzero(&buff,sizeof(buff));
				recv(sfd,&buff.len,4,0);
				recv(sfd,buff.buf,buff.len,0);
				if(buff.len==4 && !memcmp(buff.buf,&flag,4))
				{
					break;
				}
				write(fd,buff.buf,buff.len);
			}
		}else if(strncmp("puts",buf,4)==0)
			{
				send(sfd,buf,strlen(buf)-1,0);
				sleep(1);
				char f_name[128];
 			    sscanf(buf+5,"%s",f_name);
     			send_file(sfd,f_name);
			    printf("puts sucsess!\n");
			}else{	
				send(sfd,buf,strlen(buf)-1,0);
				bzero(buf,sizeof(buf));
				recv(sfd,buf,sizeof(buf),0);
				printf("%s\n",buf);
				continue;
			}
	}
	close(sfd);
	return 0;
}
