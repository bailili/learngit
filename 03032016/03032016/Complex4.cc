 ///
 /// @file    Complex4.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-08 15:21:44
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
			cout << _dimag << "i" << endl;
	}

	Complex & operator += (const Complex & c2)
	{
		this->_dreal += c2._dreal;
		this->_dimag += c2._dimag;
		return * this;
	}

	Complex & operator ++ ()
	{
		this->_dreal += 1;
		this->_dimag += 1;
		return * this;
	}

	Complex  operator ++ (int)
	{
		Complex tmp(this ->_dreal, this->_dimag);
		this->_dreal +=1;
		this->_dimag +=1;
		return tmp;
	}
private:
	double _dreal;
	double _dimag;
};

Complex operator + (const Complex & c1, const Complex & c2)
{
	Complex tmp(c1);
	tmp += c2;
	return tmp;
}

int main()
{
	Complex c1(1.0, 2.0);
	Complex c2(3.0, 4.0);
//	Complex c3 = c1 + c2;
//	c3.display();
//	c1.display();
//	c2.display();
	
	c1++;
	c1.display();
	return 0;
}
