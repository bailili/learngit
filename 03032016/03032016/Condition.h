 ///
 /// @file    Condition.h
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-07 15:08:07
 ///

#ifndef __CONDITION_H__
#define __CONDITION_H__
#include <iostream>
#include <pthread.h>

class MutexLock;

class Condition
{
public:
	Condition(MutexLock & mutex);
	~Condition();
	void wait();
	void notify();
	void notifyAll();
	
private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
};

#endif
