 ///
 /// @file    io3.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-07 19:04:59
 ///
 
#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;

int test0()
{
	ofstream ofs("file",std::ios::app);
	if(!ofs.good())
	{
		cout << "ofstream open error" << endl;
		return -1;
	}
	cout << ofs.tellp() << endl;
	ofs << "new nwe new" << endl;
	ofs.close();
	return 0;
}
int main()
{
	
}
