/*
 * minimumEditDistance.c
 *
 *  Created on: May 3, 2016
 *      Author: Udit Anand
 */

// A Dynamic Programming based solution to the minimum edit distance problem.

#include<bits/stdc++.h>
using namespace std;

// Utility function to calculate minimum.
int calMinVal(int var1, int var2)
{
	return ((var1 > var2) ? var2 : var1);
	}

// Utility function to find minimum of three numbers.
int minVal(int var1, int var2, int var3)
{
	return (calMinVal(calMinVal(var1, var2), var3));
}

int calMinEditDist(string str1, string str2)
{
	// Length of string.
	int str1Len = str1.length();
	int str2Len = str2.length();

	// Size of Array.
	int str1ArraySize =  str1Len + 1;
	int str2ArraySize = str2Len + 2;

	int minDist[str1ArraySize][str2ArraySize];

	// Index for row and column.
	int i, j;

	// Constant Cost of operation in case of unequal characters.
	 int constCost = 1;

	// Edit distance algorithm. Builds table in bottom up manner.
	for (i = 0; i <= str1ArraySize; i++)
	{
		for (j = 0; j <= str2ArraySize; j++)
		{
			if (i == 0) // Filling the initial row.
				minDist[i][j] = j;

			else if (j==0) // Filling the initial column.
				minDist[i][j] = i;

			else if (str1[i-1] == str2[j-1]) // Case when both the characters are same.
				minDist[i][j] = minDist[i-1][j-1];

			else // Case when both the characters are different.
			{
				minDist[i][j] = constCost + minVal(minDist[i-1][j-1],minDist[i-1][j], minDist[i][j-1] );
			}

		}
	}

	return (minDist[str1Len][str2Len]);
	}

// Driver Function.
int main ()
{
	string str1 = "sunday";
	string str2 = "saturday";

	cout << calMinEditDist(str1, str2);
	return (0);
	}

