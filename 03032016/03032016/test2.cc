 ///
 /// @file    test2.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-07 21:58:00
 ///
 
#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

int main()
{
	ifstream ifs("file");
	string s;
	for(int i = 0; i < 2; i++)
	{
		ifs >> s;
		cout << s << endl;
	}
	cout << "next" << endl;
	cout << s << endl;
		
}
