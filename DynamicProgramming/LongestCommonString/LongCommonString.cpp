/*
 * LongComString.cpp
 *
 *  Created on: May 5, 2016
 *      Author: Udit Anand
 */

// A Dynamic Programming based solution to the longest common string problem.

#include<bits/stdc++.h>
using namespace std;

int calMinEditDist(string str1, string str2)
{
	// Length of string.
	int str1Len = str1.length();
	int str2Len = str2.length();

	// Size of Array.
	int str1ArraySize =  str1Len + 1;
	int str2ArraySize = str2Len + 2;

	int LCS[str1ArraySize][str2ArraySize];

	// Index for row and column.
	int i, j;

	// Constant Cost of operation in case of equal characters.
	 int matchCost = 1;

	// Value for the zeroth row, zeroth column and when characters are not same.
	 int initVal = 0;

	// Edit distance algorithm. Builds table in bottom up manner.
	for (i = 0; i <= str1ArraySize; i++)
	{
		for (j = 0; j <= str2ArraySize; j++)
		{
			// Case for the zeroth row and column and when both the characters are different.
			if (i == 0 || j == 0 || (str1[i-1]!=str2[j-1]))
				LCS[i][j] = initVal;

			else if (str1[i-1] == str2[j-1]) // Case when both the characters are same.
				LCS[i][j] = matchCost + LCS[i-1][j-1];

		}
	}

	return LCS[str1Len][str2Len];
	}

// Driver Function.
int main ()
{
	string str1 = "SATURDAY";
	string str2 = "SUNDAY";

	cout <<"The Longest Common Substring is: "<< calMinEditDist(str1, str2);
	return 0;
	}




