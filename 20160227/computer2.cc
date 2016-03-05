 ///
 /// @file    computer2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-03 17:04:56
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char * brand,int price);
	~Computer();
	static void print(Computer & pc);
	static void print_tatol();
private:
	char * _brand;
	int _price;
	static int _tatolPrice;
};

int Computer::_tatolPrice = 0;

Computer::Computer(const char * brand,int price)
: _price(price)
{
	cout << "Computer(const char * ,int)" << endl;
	int len = strlen(brand);
	_brand = new char[len+1];
	strcpy(_brand,brand);
	_tatolPrice += _price;
}
Computer::~Computer()
{
	if(_brand)
		delete [] _brand;
	cout << "~Computer()" << endl;
	_tatolPrice -= _price;
}
void Computer::print(Computer & pc)
{
	cout << "品牌:" << pc._brand << endl;
	cout << "价格:" << pc._price << endl;
}
void Computer::print_tatol()
{
	cout << "总价:" << _tatolPrice <<endl;
}

int main()
{
	Computer pc("lenovo",4000);
	Computer::print(pc);
	Computer::print_tatol();

	cout << endl;
	Computer pc1("Dell",5000);
	pc1.print(pc1);
	pc1.print_tatol();

	pc1.~Computer();
//	pc.print(pc1);
	pc1.print_tatol();
	return 0;
}
