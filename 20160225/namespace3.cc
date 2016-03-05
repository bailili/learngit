 ///
 /// @file    namespace3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-25 22:15:37
 ///
 
#include <iostream>
using std::cout;
using std::endl;

namespace A
{
	int a=1;
	void display()
	{
		cout << "A a=" << a << endl;
	}
}

namespace B
{
	int a=2;
	void display()
	{
		A::display();
		cout << "B a =" << a << endl;
	}
}

int main()
{
	using B::display;
	display();
	return 0;
}
