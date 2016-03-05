 ///
 /// @file    work.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-03 20:28:48
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	String();
	String(const char * pstr);
	String(const String & rhs);
	String & operator = (const String & rhs);
	~String();
	void print();
private:
	char * pStr_;
};
String::String()
{
	cout << "String()" << endl;
	int len = strlen("default");
	pStr_ = new char[len+1];
	strcpy(pStr_,"default");
}
String::String(const char * pstr)
{
	cout << "String(const char *)" << endl;
	int len = strlen(pstr);
	pStr_ = new char[len+1];
	strcpy(pStr_,pstr);
}
String::String(const String & rhs)
{
	cout << "String(const String &)" << endl;
	int len = strlen(rhs.pStr_);
	pStr_ = new char[len+1];
	strcpy(pStr_,rhs.pStr_);
}
String & String::operator =(const String & rhs)
{
	cout << "String & operator =()" << endl;
	if(this == & rhs)
	{
		return * this;
	}
	delete [] pStr_;
	int len = strlen(rhs.pStr_);
	pStr_ = new char[len+1];
	strcpy(pStr_,rhs.pStr_);
	return  * this;
}
String::~String()
{
	cout << "~String()" << endl;
	delete [] pStr_;
}
void String::print()
{
	cout << "String : " << pStr_ << endl;
}
int main()
{
	String str1;
	String str2 = "Hello,world";
	String str3 = "wangdao";
	str2 = str3;
	String str4 = str3;

	str1.print();
	str2.print();
	str3.print();
	str4.print();
}
