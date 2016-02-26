#include "ftp.h"

void make_child(pchild cptr,int num)
{
	int i;
	int pid;
	int fds[2];
	int ret;
	for(i=0;i<num;i++)
	{
		socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
		pid=fork();
		if(pid==0)
		{
			close(fds[1]);
			child_handle(fds[0]);
		}
		close(fds[0]);
		cptr[i].pid=pid;
		cptr[i].fds=fds[1];
		cptr[i].busy=0;
	}
}

void child_handle(int fds)
{
	int flag=1;
	int newfd=-1;
	while(1)
	{
		recv_fd(fds,&newfd);
		recv_request(newfd);
		write(fds,&flag,4);
	}
}

void recv_request(int newfd)
{
	char buf[2048];
	int ret;
	while(1)
	{
		bzero(buf,sizeof(buf));
		ret=recv(newfd,buf,sizeof(buf),0);
		if(ret==0)
		{
			break;
		}
		if(strncmp("cd",buf,2)==0)
		{
			do_cd(newfd,buf);
	}else if(strncmp("ls",buf,2)==0)
	{
		do_ls(newfd,buf);
	}else if(strncmp("puts",buf,4)==0)
	{
		do_puts(newfd);
	}else if(strncmp("gets",buf,4)==0)
	{
		do_gets(newfd,buf);
	}else if(strncmp("remove",buf,6)==0)
	{
		do_remove(newfd,buf);
	}else if(strncmp("pwd",buf,3)==0)
	{
		do_pwd(newfd,buf);
	}else{
		continue;
	}
	}
}
void do_puts(int sfd)
{
	data_t buff;
	bzero(&buff,sizeof(buff));
    recv(sfd,&buff.len,4,0);
    recv(sfd,buff.buf,buff.len,0);
	printf("the file_name is %s\n",buff.buf);
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
	return;
}	
void do_gets(int sfd,char* buf)
{
	char f_name[128];
	sscanf(buf+5,"%s",f_name);
	send_file(sfd,f_name);
	printf("gets sucsess!\n");
	return;	
}
void do_remove(int sfd,char* buf)
{	
	char cmd[256]="";
	sprintf(cmd,"rm %s",buf+7);
	system(cmd);
	char buf1[128]="";
	sprintf(buf1,"%s is removed",buf+7);
	send(sfd,buf1,strlen(buf1),0);
}
void do_pwd(int sfd,char* buf)
{
	char dir[128]="";
	getcwd(dir,123);
	send(sfd,dir,strlen(dir),0);
}
void do_cd(int sfd,char* cmd_buf)
{
	char dir[128]="";
	sscanf(cmd_buf+3,"%s",dir);
	chdir(dir);
	getcwd(dir,128);
	send(sfd,dir,strlen(dir),0);
}

void do_ls(int sfd,char* cbuf)
{
	char dir[128]="";
	getcwd(dir,128);
	sprintf(cbuf,"%s\n",dir);
	myscandir(dir,0,cbuf);
	send(sfd,cbuf,strlen(cbuf),0);
}
void myscandir(char* path,int width,char* cbuf)
{
	DIR* dir;
	dir=opendir(path);
	struct dirent* pt;
	char buf[1024];
	int len;
	while(pt=readdir(dir))
	{
		len=strlen(cbuf);
		if(!strcmp(pt->d_name,".")||!strcmp(pt->d_name,".."))
		{}else{
			sprintf(cbuf+len,"%*s%s\n",width," ",pt->d_name);
			if(pt->d_type !=4)
			{}else{
			bzero(buf,sizeof(buf));
			sprintf(buf,"%s%s%s",path,"/",pt->d_name);
			myscandir(buf,width+4,cbuf);
			}
		}
	}
	closedir(dir);
}
