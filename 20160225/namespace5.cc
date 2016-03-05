 ///
 /// @file    namespace5.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-25 22:44:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;

namespace B
{
	int a=2;
}

namespace A
{
	int a=1;
	void display()
	{
		cout << "A a=" << A::a << endl;
		cout << "B a=" << B::a << endl;
	}
}

namespace B
{
	void display()
	{
		A::display();
	}
}

int main()
{
	B::display();
	return 0;
}
