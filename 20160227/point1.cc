 ///
 /// @file    point1.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-03 19:44:39
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
	const int _ix;
	const int _iy;
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
int main()
{
	Point pt(4,4);
	pt.print();

	return 0;
}
