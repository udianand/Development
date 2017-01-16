/*
 * SubSetSum.cpp
 *
 *  Created on: May 6, 2016
 *      Author: Udit Anand
 */

// A Dynamic Programming based solution to the minimum edit distance problem.

#include<bits/stdc++.h>

using namespace std;

// Function to verify if the sum can be made from the given set.
bool subSetSum(int set[], int setSize, int desiredSum)
{
	int columnSize = desiredSum + 1;
	int lastRow =  setSize - 1;
	int lastColumn = desiredSum;
	bool subSet[setSize][columnSize];
	int i, j; // row and column index

	if (desiredSum == 0)
		return true;

	// Build matrix in a bottom up manner.
	for (i = 0; i < setSize ; i++)
	{
		for (j = 0; j < columnSize; j++ )
		{
			if (j == 0)
				subSet[i][j] = true;

			else if (i == 0)
			{
				if (set[i] == j)
					subSet[i][j] =  true;
				else
					subSet[i][j] = false;
			}

			else
			{
				subSet[i][j] = subSet[i-1][j];

				if (set[i] <= j)
					subSet[i][j] = subSet[i-1][j] || subSet[i-1][j-set[i]];
			}

		}
	}

	// Print Matrix
	     for (i = 0; i < setSize; i++)
	     {
	       for (j = 0; j < columnSize; j++)
	          printf ("%4d", subSet[i][j]);
	       printf("\n");
	     }

	return subSet[lastRow][lastColumn];
	}

// Driver Program
int main()
{
	int set[] = {3, 34, 4, 12, 5, 2};
	int setSize = sizeof(set)/sizeof(set[0]);
	int desiredSum = 9;

	bool result =  subSetSum(set, setSize, desiredSum);
	if (result == true)
	cout<<"The given sum exists.";
	else
		cout<<"The given sum does not exist.";

	return 0;
}

