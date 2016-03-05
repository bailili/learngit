 ///
 /// @file    point4.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-02 22:37:06
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point()
	: _ix(0)
	, _iy(0)
	{
		cout << "Point()" << endl;
	}

	Point(int ix,int iy = 5)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;	
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
	Point pt(4);
	pt.print();
	return 0;
}
