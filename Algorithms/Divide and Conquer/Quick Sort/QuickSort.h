#pragma once

#include "iostream"

#define Boundary 1

using namespace std;

void print(int array[], int size)
{

	for (int i = 0; i < size; i++)
	{
		if (i == 0)
			cout << array[i];
		else
			cout << " , " << array[i];
	}

	cout << endl;
}


void swap(int *firstVal, int *secVal)
{
	int temp = *firstVal;
	*firstVal = *secVal;
	*secVal = temp;
}

int partition(int sample[], int leftMostIndex, int size)
{
	int pivot = sample[leftMostIndex];
	int start = leftMostIndex;
	int temp;

	for (int j = start; j <= size; j++)
	{
		if (sample[j] < pivot)
		{
			start = start++;
			swap(sample[start], sample[j]);
		}
	}

	swap(sample[start], sample[leftMostIndex]);

	return start;
}

void quickSort(int sample[], int start, int end)
{

	if (start < end)
	{
		int breakPoint;

		breakPoint = partition(sample, start, end);

		quickSort(sample, start, breakPoint - Boundary);

		quickSort(sample, breakPoint + Boundary, end);

	}

	else
		return;
}
