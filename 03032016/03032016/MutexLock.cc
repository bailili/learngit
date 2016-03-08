 ///
 /// @file    MutexLock.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-07 15:02:04
 ///

#include "MutexLock.h"
#include <iostream>
#include <pthread.h>

MutexLock::MutexLock()
{
	pthread_mutex_init(&_mutex,NULL);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
}

void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
}

pthread_mutex_t * MutexLock::get_Pmutex()
{
	return &_mutex;
}
