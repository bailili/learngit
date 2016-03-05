 ///
 /// @file    namespace4.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-25 22:39:20
 ///
 
#include <iostream>
using std::cout;
using std::endl;

extern int a=0;

namespace B
{
	int a=2;
}

namespace A
{
	int a=1;
	void display()
	{
		int a=3;
		cout << "display中的a=" << a << endl;
		cout << "A a=" << A::a << endl;
		cout << "B a=" << B::a << endl;
		cout << "extern b=" << ::a << endl;
	}
}

int main()
{
	A::display();
	return 0;
}
