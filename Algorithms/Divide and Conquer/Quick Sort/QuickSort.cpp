// QuickSort.cpp : The QuickSort Algorithm an example of Divide and Conquer.


#include "stdafx.h"
#include "iostream"

#include "QuickSort.h"

using namespace std;

int main()
{
	
	int sample[] = { 2, 1, 0, 8, 9, -1 };
	int size = sizeof(sample) / sizeof(*sample);
	int start = 0;
	int end = size - 1;
	
	cout << "The input array is: " << endl;

	print(sample, size);

	cout << endl;

	quickSort(sample, start, end);
	
	cout << "The sorted array is: " << endl;

	print(sample, size);

	cout << endl;


	return 0;
}


