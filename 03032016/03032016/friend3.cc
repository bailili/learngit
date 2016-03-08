 ///
 /// @file    friend3.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-08 11:14:08
 ///
 
#include <iostream>
#include <math.h>
using std::cout;
using std::endl;
class Point
{
	friend class Line;
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
class Line
{
public:
	float distance(const Point & ,const Point &);
	void setPoint(Point & pt,int ix, int iy);
};

float Line::distance(const Point & lhs, const Point & rhs)
{
	cout << "lhs : (" << lhs._ix << "," << lhs._iy << ")" << endl;
	cout << "rhs : (" << rhs._ix << "," << rhs._iy << ")" << endl;
}

void Line::setPoint(Point & pt,int ix, int iy)
{
	pt._ix = ix;
	pt._iy = iy;
	cout << "point : (" << pt._ix << "," << pt._iy << ")" << endl;
}

int main()
{
	Point pt1(1,2);
	Point pt2(4,5);
	pt1.print();
	pt2.print();
	cout << "distance()" << endl;
	Line line;
	line.distance(pt1,pt2);
	cout << "setPorint()" << endl;
	line.setPoint(pt1,2,1);
	return 0;
}
