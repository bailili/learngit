 ///
 /// @file    test.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-03 10:42:46
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Test
{
public:
	int c;
	void change1()
	{
		a=1;
		b=1;
		c=1;
	}
	void change3();
private:
	int a;
	int b;
	void change2()
	{
		a=2;
		b=2;
		c=2;
	}
	void change4();
protected:

};
void Test::change3()
{
	c=3;
	a=3;
	b=3;
}
void Test::change4()
{
	c=4;
	a=4;
	b=4;
}

