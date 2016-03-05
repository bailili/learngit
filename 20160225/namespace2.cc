 ///
 /// @file    namespace2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-25 22:10:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;

namespace A
{
	void display()
	{
		cout << "this is A" << endl;
	}
}

namespace B
{
	void display()
	{
		cout << "this is B" << endl;
	}
}

int main()
{
	A::display();
	B::display();
	using B::display;
	display();
	return 0;
}
