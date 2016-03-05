 ///
 /// @file    point2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-02 22:22:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	void print();
private:
	int _ix;
	int _iy;
};
void Point::print()
{
	cout << "(" << _ix << "," << _iy << ")" << endl;
}

int main()
{
	Point pt1;
	pt1.print();
	return 0;
}
