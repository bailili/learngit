 ///
 /// @file    aa.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-08 09:50:19
 ///
 
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::string;
int main()
{
	string s = "I am lily, how are you?";
	vector<string> vecstr;
	vecstr.reserve(100);
	vecstr.push_back("lalala");
	vecstr.push_back(s);
	vector<string>::iterator it = vecstr.begin();
	for(auto & ss : vecstr)
	{
		cout << ss << endl;
	}
}

