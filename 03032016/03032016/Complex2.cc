 ///
 /// @file    Complex2.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-08 14:26:27
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
			cout << "-" << -1 * _dimag << endl;
	}
//	Complex operator + (const Complex &);
	Complex & operator + (const Complex &);
private:
	double _dreal;
	double _dimag;
};

// Complex Complex::operator + (const Complex & c2)
// {
// 	cout << "hahaha" << this->_dreal << " " 
// 		<< this->_dimag << endl;
// 	return Complex(this->_dreal+c2._dreal,
// 			this->_dimag+ c2._dimag);
// }
#if 0
Complex & Complex::operator + (const Complex & c2)
{
	this->_dreal + c2._dreal;
	this->_dimag + c2._dimag;
	return * this;
}
#endif

Complex & Complex::operator + (const Complex & c2)
{
	this->_dreal += c2._dreal;
	this->_dimag += c2._dimag;
	return * this;
}
int main()
{
	Complex c1(1.0, 2.0);
	Complex c2(3.0, 4.0);
	Complex c3 = c1+c2;
	c3.display();
	c1.display();
	c2.display();
	return 0;
}
