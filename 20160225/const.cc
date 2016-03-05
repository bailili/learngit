 ///
 /// @file    const.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-25 20:57:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;
#define MAX 100

int test0(void)
{
	int a=3;
	a=5;
	cout << MAX << endl;
	cout << "a = " << a << endl;
	
}

int test1()
{
	const int a=1;
	const int b=2;
	int const c=3;
	cout << "c = " << c << endl;
	cout << "a = " << a <<endl;
}

int test3()
{
	const int a=3;
//	int * pa=&a;
//	*pa=4;

	const int * paa = &a;
	cout << "a = " << *paa << endl;
}

int test4()
{
	int a=1;
	int * const pa = &a;
	int b=4;
	cout << "a = " << *pa << endl;
}

int main()
{
	test3();
	return 0;
}

