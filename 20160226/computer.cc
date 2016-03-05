 ///
 /// @file    computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-02 23:35:54
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Computer
{
public:
	void setBrand(char * brand)
	{
		strcpy(_brand,brand);
	}
	void setPrice(int price)
	{
		_price=price;
	}
	void print()
	{
		cout << "品牌" << _brand << endl;
		cout << "价格" << _price << endl;
	}
private:
	char _brand[10];
	int _price;
};

int main()
{
	Computer pc;
	pc.setBrand("lenove");
	pc.setPrice(4900);
	pc.print();
	return 0;
}
