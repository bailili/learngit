 ///
 /// @file    line.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-03 19:10:50
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix,int iy);
	Point(const Point & rhs);
	void print();
private:
	int _ix;
	int _iy;
};
Point::Point(int ix,int iy)
: _ix(ix)
, _iy(iy)
{
	cout << "Point(int,int)" << endl;
}
Point::Point(const Point & rhs)
: _ix(rhs._ix)
, _iy(rhs._iy)
{
	cout << "Point(const Point &)" << endl;
}
void Point::print()
{
	cout << "(" << _ix
		<< "," << _iy
		<< ")" << endl;
}

class Line
{
public:
	Line(int x1,int y1,int x2,int y2);
	Line(const Line & rhs);
	void draw();
private:
	Point _pt1;
	Point _pt2;
};
Line::Line(int x1,int y1,int x2,int y2)
: _pt1(x1,y1)
, _pt2(x2,y2)
{
	cout << "Line(int,int,int,int)" << endl;
}
Line::Line(const Line & rhs)
: _pt1(rhs._pt1)
, _pt2(rhs._pt2)
{
	cout << "Lint(const Line & rhs)" << endl;
}
void Line::draw()
{
	_pt1.print();
	cout << "	to	";
	_pt2.print();
}
int main()
{
	Line l1(1,2,3,4);
	l1.draw();
	cout << endl;

	Line l2(l1);
	l2.draw();

	return 0;
}

