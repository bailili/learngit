 ///
 /// @file    computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-03 16:47:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(int price);
	~Computer();
	void print();
private:
	int _price;
	static int _totalPrice;
};

int Computer::_totalPrice = 0;

Computer::Computer(int price)
: _price(price)
{
	cout << "Computer(int)" << endl;
	_totalPrice += _price;
}
Computer::~Computer()
{
	cout << "~Computer()" << endl;
	_totalPrice -= _price;
}
void Computer::print()
{
	cout << "价格:" << _price << endl;
	cout << "总价:" << _totalPrice << endl;
}
int main()
{
	Computer pc(4000);
	cout << "buy one" << endl;
	pc.print();

	Computer pc1(5000);
	cout << "buy two" << endl;
	pc1.print();
}
