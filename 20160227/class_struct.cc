 ///
 /// @file    class_struct.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-03 16:30:31
 ///
 
#include <iostream>
 
class A
{
	int _ia;
};

struct B
{
	int _ia;
};

int main()
{
	A a;
//	a._ia;
	B b;
	b._ia=4;
}
