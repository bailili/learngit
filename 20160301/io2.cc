 ///
 /// @file    io2.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-07 18:38:43
 ///
 
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::vector;

int test0()
{
	ifstream ifs("file");
	if(!ifs.good())
	{
		cout << "ifstream open error" << endl;
		return -1;
	}
	string s;
	string ss;
#if 0
	while(ifs >> s)
	{
		cout << s << endl;
	}
	cout << "ABCDEFG" << endl;
	while(getline(ifs,ss))
	{
		cout << ss << endl;
	}
#endif
	vector<string> vecstr;
	string line;
	while(getline(ifs,line))
	{
		vecstr.push_back(line);
	}
	vector<string>::iterator it = vecstr.begin();
	for(;it != vecstr.end(); ++it)
	{
		cout << *it << endl;
	}
	return 0;
}

int main()
{
	ifstream ifs("file");
	if(!ifs.good())
	{
		cout << "ifstream open error" << endl;
		return -1;
	}
	ofstream ofs("file2");
	if(!ofs.good())
	{
		cout << "ofstream open error" << endl;
		return -1;
	}

	string line;
	while(getline(ifs,line))
	{
		ofs << line << endl;
	}
}



