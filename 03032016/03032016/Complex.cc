 ///
 /// @file    Complex.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-08 14:07:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Complex
{
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
		if(_dimag > 0)
			cout << "+" << _dimag << "i" << endl;
		else if(_dimag == 0)
			cout << endl;
		else
			cout << "-" << -1*_dimag << "i" << endl;
	}
public:
	double _dreal;
	double _dimag;
};

Complex operator + (const Complex & lhs, const Complex & rhs)
{
	return Complex(lhs._dreal+rhs._dreal,
			lhs._dimag+rhs._dimag);
}

int main()
{
	Complex c1(1.0, 2.0);
	Complex c2(3.0, 4.0);
	Complex c3 = c1 + c2;
	c3.display();
	return 0;
}
