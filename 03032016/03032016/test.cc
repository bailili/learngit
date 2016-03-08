 ///
 /// @file    test.cc
 /// @author  baihanbao(baihanbao@gmail.com)
 /// @date    2016-03-07 16:59:52
 ///

#include "MutexLock.h"
#include "Condition.h"
#include <unistd.h>
using std::cout;
using std::endl;

int count = 100;
MutexLock mutex;
Condition condition(mutex);
void * func1(void * p)
{
	while(1)
	{
		mutex.lock();
		while(count < 90)
			condition.wait();
		--count;
		cout << "count = " << count << endl;
		mutex.unlock();
		condition.notify();
		sleep(1);
	}
}

void * func2(void * p)
{
	while(1)
	{
		mutex.lock();
		while(count > 90)
			condition.wait();
		++count;
		cout << "count = " << count << endl;
		mutex.unlock();
		condition.notify();
		sleep(2);
	}
}
int main()
{
	pthread_t pth1;
	pthread_t pth2;

	pthread_create(&pth1,NULL,func1,NULL);
	pthread_create(&pth2,NULL,func2,NULL);

	pthread_join(pth1,NULL);
	pthread_join(pth2,NULL);

	return 0;
}
