 ///
 /// @file    MutexLock.h
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-07 14:59:12
 ///

#ifndef __MUTEX_LOCK_H__
#define __MUTEX_LOCK_H__
#include <iostream>

class MutexLock
{
public:
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();
	pthread_mutex_t * get_Pmutex();
private:
	pthread_mutex_t _mutex;
};
#endif
