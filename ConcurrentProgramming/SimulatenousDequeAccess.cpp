
/*Using unique_lock and conditional variable to push and pop an element in a deque.*/

#include "stdafx.h" // Uncomment if not on windows.
#include "deque"

#include <condition_variable>
#include <iostream>
#include <thread>
#include <mutex>

#define SLEEP_TIME 1

std::deque <int> q;
std::mutex mu;
std::condition_variable cond;

void function1()
{
	int count = 10;

	while (count > 0)
	{
		/*
		Instead of mutex lock and unlock we use the lock_guard or unique_lock.
		The reason being that mutex lock and unlock is not exception free. Incase, the
		exception occurs at the resource when it is in the lock stage then the resource
		stays in the lock stage.

		To avoid this we use unique_lock or lock_guard as when the exception occurs it will
		put the resource  out of the lock.
		*/

		std::unique_lock <std::mutex> locker(mu);
		q.push_front(count);
		locker.unlock();
		cond.notify_one();
		std::this_thread::sleep_for(std::chrono::seconds(SLEEP_TIME));
		
		count--;
	}

	if (count == 0) // To avoid T2 waiting till eternity.
		cond.notify_one();

	return;
}

void function2()
{
	int data = 0;

	while (!q.empty())
	{
		std::unique_lock<std::mutex> locker(mu);
		cond.wait(locker);
		
		data = q.back();
		q.pop_back();
		locker.unlock(),

		std::cout << "T2 gets " << data << " from T1" << std::endl;
	}

	return;

}

int main() {

	std::thread t1(function1);
	std::thread t2(function2);

	t1.join();
	t2.join();

	std::cout << "Thread Function Executed Successfully" << std::endl;
}


