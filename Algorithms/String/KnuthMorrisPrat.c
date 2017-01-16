/* The follwing is an example of a KMP algorithm for searching a pattern in a string, in time O(m+n). 
Here, O(m) - Time taken  to compute the prefix function values. 
and  O(n) - Time taken to compare the pattern to the text.

The KMP algorithm has the following properties:

1. It Compares from left to right.
2. It preprocesses Pattern to avoid trivial comparisions.
3. It avoids recomputing matches.
4. Since it avoids backtracking it can be used to process large files.
5. However, it does not work when size of the alphabets increases as there are more chances of mismatch.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The prefix-function preprocesses the pattern to find matches of prefixes of the pattern with the pattern itself.
   It indicates how much of the last comparison can be reused if it fails. It enables avoiding backtracking on the 
   string ‘S’ */.

int *compute_prefix_function(char *pattern, int psize)
{
	int k = -1;
	int i = 1;
	int*pi;
	
	pi=malloc(sizeof(int)*psize);
	if (!pi)
		return NULL;
    pi[0] = k;
     
	for (i = 1; i < psize; i++) {
		while (k > -1 && pattern[k+1] != pattern[i])
			k = pi[k];
		if (pattern[i] == pattern[k+1])
			k++;
		pi[i] = k;
	}
	return pi;
	
}

/* Implementation of the KMP algorithm. */

int kmp(char *target, int tsize, char *pattern, int psize)
{
	int i;
	int *pi;
	pi= compute_prefix_function(pattern, psize);
	int k = -1; // Indicates the number of characters matched.

	if (!pi)
		return -1;
		
	/* Compare first character of pattern with first character of string. If a matach is found increement 
	k by 1 else if no match is found substitue value of pi[k] to k.*/	
	
	for (i = 0; i < tsize; i++) {
		while (k > -1 && pattern[k+1] != target[i])
			k = pi[k];
		if (target[i] == pattern[k+1])
			k++;
		if (k == psize - 1)  /* If number of charaters matched == Size of the pattern then 
		                        return the location where match has occured.*/ 
		   { 
		     free(pi);
	             return i-k;
		    }
	}
	free(pi);
	return -1; // In case, no match has occured and pattern is not in the string.
}

int main()
{
	char target[] = "PQR ABCXYZ ABC QVW";
	char *ch = target;
	char pattern[] = "ABC";
	int i;

	i = kmp(target, strlen(target), pattern, strlen(pattern));
	if (i >= 0)
		{
			printf("matched @: %s\n", ch + i);
		    printf("Index of first match %d\n",i);
		    }
		else
		printf("Sorry, no match found !!!");
	return 0;
}
