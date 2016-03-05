 ///
 /// @file    point3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-02 22:26:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point()
	: _ix(0)
	, _iy(_ix)
	{
		cout << "Point()" << endl;
	}
	
	~Point()
	{
		cout << "~Point()" << endl;
	}

	void print()
	{
		cout << "(" << _ix << "," << _iy << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};

int main()
{
	Point pt;
	pt.print();
	return 0;
}
