 ///
 /// @file    reference.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-25 23:22:35
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void swap(int *pa,int *pb)
{
	int tem=*pa;
	*pa=*pb;
	*pb=tem;
}

void swap(int & refa,int & refb)
{
	int tmp=refa;
	refa=refb;
	refb=tmp;
}

int main()
{
	int a=1;
	int b=2;
//	swap(&a,&b);
//	swap(a,b);
	cout << a << endl << b << endl;
	return 0;
}
