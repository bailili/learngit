 ///
 /// @file    word.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-07 23:25:48
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;

struct Record
{
	string word;
	int freq;
};

class WordStatic
{
public:
	WordStatic();
	void readFile(const string & filename);
	void writeFile(const string & filename);
private:
	vector<Record> _dict;
};

WordStatic::WordStatic()
{
	_dict.reserve(10000);
}

void WordStatic::readFile(const string & filename)
{
	ifstream ifs(filename.c_str());
	if(!ifs.good())
	{
		cout << "ifstream open error" << endl;
		return ;
	} 
	string w;
	vector<Record>::iterator it;
	while(ifs >> w)
	{
		for(it = _dict.begin();it != _dict.end(); ++it)
		{
			if(w == it->word)
			{
				++(it->freq);
				break;
			}
		}

		if(it == _dict.end())
		{
			Record record;
			record.word = w;
			record.freq = 1;
			_dict.push_back(record);
		}
	}
}

void WordStatic::writeFile(const string & filename)
{
	ofstream ofs(filename.c_str());
	if(!ofs.good())
	{
		cout << "ofstream open error" << endl;
		return ;
	}

	for(auto & ss : _dict)
	{
		ofs << ss.word << " " << ss.freq << endl;
	}
}

int main()
{
	WordStatic ws;
	ws.readFile("file");
	ws.writeFile("file2");
	return 0;
}
