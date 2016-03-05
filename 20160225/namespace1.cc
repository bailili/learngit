 ///
 /// @file    namespace1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-25 22:02:23
 ///
 
#include <iostream>
using namespace std;

namespace A
{
	void displayA()
	{
		cout << "this is A" << endl;
	}
}

namespace B
{
	void display()
	{
		using namespace A;
		displayA();
		cout << "this is B" << endl;
	}
}

int main()
{
	B::display();
	return 0;
}
