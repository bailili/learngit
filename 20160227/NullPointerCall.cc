 ///
 /// @file    NullPointerCall.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-03 19:34:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class NullPointerCall
{
public:
	static void test1();
	void test2();
	void test3(int ix);
	void test4();
private:
	static int _istatic;
	int _ix;
};
int NullPointerCall::_istatic = 0;
void NullPointerCall::test1()
{
	cout << "test1() static:" << _istatic << endl;
}
void NullPointerCall::test2()
{
	cout << "test2()" << endl;
}
void NullPointerCall::test3(int ix)
{
	cout << "test3()" << ix << endl;
}
void NullPointerCall::test4()
{
	cout << "test4()" << this->_ix << endl;
}
int main()
{
	NullPointerCall * npc = NULL;
	npc->test1();
	npc->test2();
	npc->test3(3);
	npc->test4();
	return 0;
}
