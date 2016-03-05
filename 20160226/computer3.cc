 ///
 /// @file    computer3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-02 23:50:41
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer();
	Computer(char * brand,int price);
	void print();
private:
	char _brand[10];
	int _price;
};
Computer::Computer()
{
	cout << "Computer()" << endl;
	strcpy(_brand,"lenovo");
	_price=4900;
}
Computer::Computer(char * brand,int price)
{
	cout << "Computer(char *,int)" << endl;
	strcpy(_brand,brand);
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
	pc.print();
	cout << endl;
	Computer pc1("Thinkpad",4500);
	pc1.print();
	return 0;
}
