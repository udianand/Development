/*
 * knapSack.c
 *
 *  Created on: May 2, 2016
 *      Author: Udit Anand
 */

/* A Dynamic Programming based solution for 0-1 Knapsack problem.*/
#include<stdio.h>

/* A utility function that returns maximum of two integers.*/
int max(int first, int second) {
	return ((first > second) ? first : second);
}

/* Returns the maximum value that can be put in a knapsack of capacity W.*/
int knapSack(int W, int wt[], int val[], int listSize) {

	int K[listSize + 1][W + 1];
	int tableIndex;
	int w;

/* Build table K[][] in bottom up manner.*/
	for (tableIndex = 0; tableIndex <= listSize; tableIndex++) {
		for (w = 0; w <= W; w++) {
			if (tableIndex == 0 || w == 0)
				K[tableIndex][w] = 0;

			else if (wt[tableIndex - 1] <= w)
				K[tableIndex][w] = max(
						val[tableIndex - 1] + K[tableIndex - 1][w - wt[tableIndex - 1]],
						K[tableIndex - 1][w]);

			else
				K[tableIndex][w] = K[tableIndex - 1][w];
		}
	}

	return (K[listSize][W]);
}

/* Driver Function.*/
int main() {
	int val[] = { 1, 4, 5, 7 };
	int wt[] = { 1, 3, 4, 5 };
	int W = 7;
	int listSize = sizeof(val) / sizeof(val[0]);

	printf("The KnapSack Value: %d", knapSack(W, wt, val, listSize));
	return (0);

}
