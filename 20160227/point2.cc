 ///
 /// @file    point2.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-03 19:51:43
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix,int iy,double & z);
	Point(const Point & rhs);
	void print();
	void setX(int x);
private:
	int _ix;
	int _iy;
	int & _ref1;
	double & _ref2;
};
Point::Point(int ix,int iy,double & z)
: _ix(ix)
, _iy(iy)
, _ref1(_ix)
, _ref2(z)
{
	cout << "Point(int,int,double)" << endl;
}
Point::Point(const Point & rhs)
: _ix(rhs._ix)
, _iy(rhs._iy)
, _ref1(rhs._ref1)
, _ref2(rhs._ref2)
{
	cout << "Point(const Point &)" << endl;
}
void Point::print()
{
	cout << "(" << _ix 
		<< "," << _iy
		<< "," << _ref1
		<< "," << _ref2
		<< ")" << endl;
}
void Point::setX(int x)
{
	_ix = x;
}
int main()
{
	double d = 4.0;
	Point pt(1,2,d);
	pt.print();
	cout << endl;
	Point pt1(pt);
	pt1.print();

	cout << "after change X" << endl;
	pt.setX(4);
	pt.print();
	pt1.print();//pt1的ref1也会随着X变化，因为pt1是复制的pt,即pt.ref1与pt1.ref是同一
				//实体的引用，所以pt1.ref1会随pt._ix变化
	
	Point pt2(3,3,d);
	cout << "after change X" << endl;
	pt.setX(10);
	pt.print();
	pt2.print();
	return 0;
}
