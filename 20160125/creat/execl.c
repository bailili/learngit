#include <unistd.h>
#include <stdio.h>

int main()
{
	execl("./","ls -l",NULL);
	printf("lalala");
	return 1;
}
