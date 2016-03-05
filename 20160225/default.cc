 ///
 /// @file    default.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-25 21:21:23
 ///
 
#include <iostream>
using std::cout;
using std::endl;
#if 0
int add(int a,int b=0)
{
	return a+b;
}
#endif

int add(int a,int b=1,int c=0)
{
	return a+b+c;
}

int main()
{
	//cout << "a+b=" << add(1) <<endl;
	cout << "a+b+c=" << add(6) << endl;
	return 0;
}
