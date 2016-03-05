 ///
 /// @file    computer3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-03 18:53:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(int price);
	~Computer();
	void print()const;
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
	_totalPrice -= _price;
	cout << "~Computer()" << endl;
}
void Computer::print()const
{
	cout << "价格:" << _price << endl;
	cout << "总价:" << _totalPrice << endl;
}
int main()
{
	Computer pc(4000);
	cout << "buy one" << endl;
	pc.print();
	cout << endl;

	Computer pc2(5000);
	cout << "buy two" << endl;
	pc2.print();
	cout << endl;

	cout << "pc: " << sizeof(pc) << endl;
	cout << "Computer: " << sizeof(Computer) << endl;
}

