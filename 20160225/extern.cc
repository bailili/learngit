 ///
 /// @file    extern.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-25 21:29:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#ifdef __cplusplusֻ//只有c++编译器自动定义了__cplusplus这个宏，只有c++编译器才会进入这个宏，执行c代码
//而c中__cplusplus是没有定义的，如果进入会有异常，所以用了#ifdef __cplusplus,来当做开关。
extern "C"
{
#endif
	int add(int a,int b)
	{
		return a+b;
	}
#ifdef __cplusplus
}
#endif

