 ///
 /// @file    namespace6.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-25 22:54:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;

namespace B
{
	int a=2;
	namespace A
	{
		int a=1;
		void dis()
		{
			cout << "A a=" << A::a << endl;
			cout << "B a=" << B::a << endl;
		}
	}
}

int main()
{
	B::A::dis();
	return 0;
}
