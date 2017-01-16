/*The following is an example of an insertion sort. Insertion sort  is used to sort the cards in the hands.
"We start with an empty left hand and the cards face down on the table. We then remove one card at a time 
from the table and insert it into the correct position in the left hand. To find the correct position for 
a card, we compare it with each of the cards already in the hand, from right to left.  At all times, 
the cards held in the left hand are sorted, and these cards were originally the top cards of the pile on the table" - Source Corman

Insertion sort is good for sorting small numbers. The complexity of insertion sort is O(n^2).
 */  


#include <stdio.h>
 
int main()
{
  int nelements, array[1000], currentnum, key, swap;
 
  printf("Enter number of elements\n"); /* Enter the number of elements to fill the array for example, 4. 
                                        The size of the array is 1000.*/
  scanf("%d", &nelements);
 
  printf("Enter %d integers\n", nelements); // Enter the values for the n elements of the array.
 
  for (currentnum = 0; currentnum < nelements; currentnum++) {
    scanf("%d", &array[currentnum]);  
  }
 
  for (currentnum= 1 ; currentnum <= nelements - 1; currentnum++) {  /* The outer loop will start comparing from 
                                                        the second element of the array (index =1) to the last one.*/
    
    key = currentnum;
    
    while ( key > 0 && array[key] < array[key-1]) { /* If the integer at array[key] < integer at array[key -1] 
                                                    then the values will be swapped. */
      
      swap = array[key];
      array[key] = array[key-1];
      array[key-1] = swap;
      key--; // The key value is decremented to check and if required sort the preceding integers of the array. 
 
    }
   }
 
  printf("Sorted list in ascending order:\n");
 
  for (currentnum = 0; currentnum <= nelements - 1; currentnum++) {
    printf("%d\n", array[currentnum]);
  }
 
  return 0;
}
