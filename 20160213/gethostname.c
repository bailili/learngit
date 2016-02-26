#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <strings.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	char** pptr;
	struct hostent* hptr;
	if((hptr=gethostbyname(argv[1]))==NULL)
	{
		perror("gethostbyname");
		return -1;
	}
	printf("the hname is %s\n",hptr->h_name);
	pptr=hptr->h_aliases;
	int i;
	for(i=0;pptr[i] !=NULL;i++)
	{
		printf("h_aliases is %s\n",pptr[i]);
	}
	printf("h_length is %d\n",hptr->h_length);
	char str[32];
	pptr=hptr->h_addr_list;
	for(i=0;pptr[i] != NULL;i++)
	{
		bzero(str,sizeof(str));
		printf("%s\n",inet_ntop(hptr->h_addrtype,pptr[i],str,sizeof(str)));
	}
	return 0;
}
