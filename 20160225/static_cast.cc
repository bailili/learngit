 ///
 /// @file    static_cast.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-29 10:25:05
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int func(int * pa)
{
	return *pa;
}

int main()
{
	int a=3;
	double d1=double(a);//c++
	double d2=static_cast<double>(a);

	cout << "d1=" << d1 << endl;
	cout << "d2=" << d2 << endl;
	
	//常量指针被转化成非常量指针，仍指向原来的对象；
	//常量引用被转换成非常量引用，仍.....；
	//常量对象被转换成非常量对象，可以改变值,但注意不再是同一个对象了；
	const int b=10;
	int * p =const_cast<int*>(&b);
	cout << "&b=" << &b << endl;
	cout << "p=" << p << endl;

	func(const_cast<int*>(&b));
	return 0;

}

