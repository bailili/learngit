 ///
 /// @file    reference1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-26 17:05:14
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void swap(int & ra,int & rb)
{
	int tmp=ra;
	ra=rb;
	rb=tmp;
}

int main()
{
	int a=1;
	int b=10;
	swap(a,b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	return 0;
}
