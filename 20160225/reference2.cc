 ///
 /// @file    reference2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-26 17:12:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int arr[5]={1,2,3,4,5};
int & func(int n)
{
	return arr[n];
}

int main()
{
	int a;
	int b;
	int & ra=a;
	int	& rb=b;
	cout << "a[5]=" << func(5) << endl;
	func(5)=10;
	cout << "gai a[5]" << arr[5] << endl;
	return 0;
}
