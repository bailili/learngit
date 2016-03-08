 ///
 /// @file    Complex3.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-08 14:59:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Complex
{
	friend Complex operator + (const Complex &, const Complex &);
public:
	Complex(double dreal, double dimag)
	: _dreal(dreal)
	, _dimag(dimag)
	{
		cout << "Complex()" << endl;
	}

	void display()
	{
		cout << _dreal;
		if(_dimag < 0)
			cout << "-" << -1 * _dimag << "i" << endl;
		else if(_dimag == 0)
			cout << endl;
		else
			cout << "+" << _dimag << "i" << endl;
	}
private:
	double _dreal;
	double _dimag;
};

Complex operator + (const Complex & c1, const Complex & c2)
{
	return Complex(c1._dreal + c2._dreal,
			c1._dimag + c2._dimag);
}

int main()
{
	Complex c1(1.0, 2.0);
	Complex c2(3.0, 4.0);
	Complex c3 = c1+ c2;
	c3.display();
	c1.display();
	c2.display();
}
