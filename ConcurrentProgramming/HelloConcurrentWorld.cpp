/*First Concurrent Program*/

#include "stdafx.h"
#include "iostream"
#include "thread"

void hellWorld()
{
	std::cout << "hello concurrent world" << std:: endl;
}

int main()
{
	std::thread t1(hellWorld);
	t1.join();

    return 0;
}

