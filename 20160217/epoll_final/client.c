#include "func.h"
int main(int argc,char** argv)
{
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	connect(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	printf("connect success!\n");
	while(1);
	return 0;
}
