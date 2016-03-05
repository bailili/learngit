 ///
 /// @file    computer5.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-03 00:16:02
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
	~Computer();
	void print();
	Computer(const Computer & rhs);
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
	_price=4900;
}
Computer::Computer(char * brand,int price)
{
	cout << "Computer(char*,int)" << endl;
	int len = strlen(brand);
	_brand = new char[len+1];
	strcpy(_brand,brand);
	_price=price;
}
Computer::~Computer()
{
	delete [] _brand;
	cout << "~Computer()" << endl;
}
void Computer::print()
{
	cout << "品牌:" << _brand <<endl;
	cout << "价格:" << _price << endl;
}
Computer::Computer(const Computer & rhs)
: _price(rhs._price)
{
	cout << "Computer(const Computer & rhs)" << endl;
	int len = strlen(rhs._brand);
	_brand = new char[len+1];
	strcpy(_brand,rhs._brand);
}
int main()
{
	Computer pc;
	pc.print();

	Computer pc1=pc;
	pc1.print();

	return 0;
}
