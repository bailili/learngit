 ///
 /// @file    friend1.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-08 10:49:16
 ///
 
#include <iostream>
#include <math.h>
using std::cout;
using std::endl;

class Point
{
	friend float distance(const Point & lhs, const Point & rhs);
public:
	Point(int ix, int iy)
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
		cout << "(" << _ix
			<< "," << _iy
			<< ")" << endl;
	}
private:
	int _ix;
	int _iy;
};
float distance(const Point & lhs, const Point & rhs)
{
	return sqrt((lhs._ix - rhs._ix)*(lhs._ix - rhs._ix)+
			(lhs._iy - rhs._iy)*(lhs._iy - rhs._iy));
}

int main()
{
	Point pt1(1,2);
	Point pt2(4,5);
	pt1.print();
	pt2.print();

	cout << "the distance of pt1 & pt2" << endl;
	cout << distance(pt1,pt2) << endl;
	return 0;
}
