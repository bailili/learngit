 ///
 /// @file    point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-02 22:15:47
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	//在初始化列表中初始化数据成员的构造函数
	Point()
	: _ix(0)
	, _iy(0)
	{
		cout << "Point()" << endl;
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
	Point pt1;
	pt1.print();
	return 0;
}
