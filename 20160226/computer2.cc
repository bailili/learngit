 ///
 /// @file    computer2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-02 23:43:16
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	void setBrand(char * brand);
	void setPrice(int price);
	void print();
private:
	char _brand[10];
	int _price;
};
void Computer::setBrand(char * brand)
{
	strcpy(_brand,brand);
}
void Computer::setPrice(int price)
{
	_price=price;
}
void Computer::print()
{
	cout << "品牌" << _brand << endl;
	cout << "价格" << _price << endl;
}

int main()
{
	Computer pc;
	pc.setBrand("lenovo");
	pc.setPrice(4900);
	pc.print();
	return 0;
}
