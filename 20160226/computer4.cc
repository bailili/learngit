 ///
 /// @file    computer4.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-03 00:00:07
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
	cout << "Computer(char *,int )" << endl;
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
	cout << "品牌 :" << _brand << endl;
	cout << "价格 :" << _price << endl;
}
int text()
{
	Computer pc;
	pc.print();
	cout << endl;
	Computer pc1("Dell",6000);
	pc1.print();
	return 0;
}

int main()
{
	Computer * pc = new Computer;
	pc->print();
	delete pc;
//	pc->~Computer();
	return 0;
}
