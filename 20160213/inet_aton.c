#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

int main(int argc,char* argv[])
{
	struct in_addr addr;
	inet_aton(argv[1],&addr);
	printf("the s_addr is %x\n",addr.s_addr);
	printf("string is %s\n",inet_ntoa(addr));
	printf("the s_addr 2 is %x\n",inet_addr(argv[1]));
	return 0;
}
