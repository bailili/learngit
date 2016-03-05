 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-29 17:30:50
 ///
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int test0()
{
	char str1[]="hello,world";
	char str2[]="shenzhen";

	int len1=strlen(str1);
	int len2=strlen(str2);

	char * pstr = (char *)malloc(len1+len2+1);
	strcpy(pstr,str1);
	strcat(pstr,str2);
//	printf("%s\n",pstr);
	free(pstr);
	pstr=NULL;

	char * p=strstr(str2,"enzh");
	strncpy(str1,p,4);
	printf("%s\n",str1);
	return 0;
}

void test1()
{
	string s1="hello,world!";
	string s2="shenzhen";
	s1+=s2;
	cout << s1 << endl;

	s2+="fang zi gui!";
	cout << s2 << endl;

	string s3=s1+s2;
	cout << s3 << endl;

	string s4="BERJING";
	s4.append("WELCOM!");
	cout << s4 << endl;

}

void test2()
{
	string s1="hello,world";
	string sub = s1.substr(6,5);
	cout << sub << endl;

	int len1=sub.size();
	int len2=sub.length();
	cout << "len1 " << len1 << endl << "len2 " << len2 << endl;
}

void str_func(const char* p)
{
	cout << p << endl;
}

int main()
{
	string s1 = "Bailili";
	str_func(s1.c_str());
	for(int i=0;i<s1.size();i++)
	{
		cout << s1[i] << endl;
	}
	return 0;
}

