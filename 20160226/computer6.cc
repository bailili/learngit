 ///
 /// @file    computer6.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-03 09:54:49
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer();
	Computer(char * brand,int price);
	Computer(const Computer & rhs);
	Computer & operator = (const Computer &rhs);
	~Computer();
	void print();
private:
	char * _brand;
	int _price;
};
Computer::Computer()
{
	cout << "Computer()" << endl;
	int len = strlen("lenovo");
	_brand = new char[len+1];
	strcpy(_brand,"lenovo");
	_price = 4900;
}
Computer::Computer(char * brand,int price)
: _price(price)
{
	cout << "Computer(char *,int)" << endl;
	int len = strlen(brand);
	_brand = new char[len+1];
	strcpy(_brand,brand);
}
Computer::Computer(const Computer & rhs)
: _price(rhs._price)
{
	cout << "Computer(const Computer &)" << endl;
	int len = strlen(rhs._brand);
	_brand = new char[len+1];
	strcpy(_brand,rhs._brand);
}
Computer::~Computer()
{
	delete [] _brand;
	cout << "~Computer()" << endl;
}
Computer & Computer::operator = (const Computer & rhs)
{
	delete _brand;
	int len = strlen(rhs._brand);
	_brand = new char[len+1];
	strcpy(_brand,rhs._brand);
	_price = rhs._price;
	cout << "Computer & operator = " << endl;
	return * this;
}
void Computer::print()
{
	cout << "品牌:" << _brand << endl;
	cout << "价格:" << _price << endl;
}
int main()
{
	Computer pc;
	pc.print();
	cout << endl;
	Computer pc2("Dell",6000);
	pc2.print();
	cout << endl;
	pc = pc2;
	pc.print();
	cout << endl;
	return 0;
}
