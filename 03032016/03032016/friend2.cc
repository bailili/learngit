 ///
 /// @file    friend2.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-08 11:00:53
 ///
 
#include <iostream>
#include <math.h>
using std::cout;
using std::endl;

class Point;
class Line
{
public:
	float distance(const Point & lhs, const Point & rhs);
};

class Point
{
	friend float Line::distance(const Point & ,const Point & );
public:
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
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

float Line::distance(const Point & lhs, const Point & rhs)
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
	Line line;
	cout << line.distance(pt1,pt2) << endl;
	return 0;
	
}
