 ///
 /// @file    new.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-25 22:59:38
 ///
#include <stdlib.h> 
#include <iostream>
using std::cout;
using std::endl;

int test0()
{
	int *p=(int *)malloc(sizeof(int));
	*p=3;
	free(p);
	return 0;
}

int main()
{
	int *p=new int(4);
	*p=44;
	cout << *p << endl;

	int *pa=new int[10];
	for(int i=0;i<10;i++)
	{
		cout << pa[i] << endl;
	}
	delete []pa;
	delete p;
	return 0;
}


