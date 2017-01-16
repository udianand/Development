#include <stdio.h>
#include <stdlib.h>
#define size 50

void swap(int *x,int *y)
{
int temp;
temp = *x;
*x = *y;
*y = temp;
}

int partition(int i,int j )
{
return((i+j) /2);
}

void quicksort(int list[],int m,int n)
{
int key,i,j,k;
if( m < n)
{
k = partition(m,n);
swap(&list[m],&list[k]);
key = list[m];
i = m+1;
j = n;
while(i <= j)
{
while((i <= n) && (list[i] <= key))
i++;
while((j >= m) && (list[j] > key))
j--;
if( i < j)
{swap(&list[i],&list[j]);}
printlist(list,n+1);
}
// swap two elements
swap(&list[m],&list[j]);
//printlist(list,j+1);
//printf("value of j,%d\n",j);
//printf("value of m,%d\n",m);
//printf("value of n,%d\n",n);
// recursively sort the lesser list
quicksort(list,m,j-1);
printf("before calling the second list");
printlist(list,n);
quicksort(list,j+1,n);
}
}
void printlist(int list[],int n)
{
int i;
for(i=0;i<n;i++)
printf("%d",list[i]);
printf("\n");
}

void main()
{
int n,i;
int list[size];


printf("How many numbers do you want to enter");
scanf("%d",&n);
/*printf("Numbers entered %d\n",&n);
i=&n;
printf("%d\n",(*i));
printf("Are you sure %d\n",i);*/
printf("Enter the numbers you want to sort");
for(i=0;i<n;i++)
{
scanf("%d",&list[i]);
//printf("%d",list[i]);
}


//printf("The list before sorting is:\n");
//printlist(list,n);

// sort the list using quicksort
quicksort(list,0,n-1);

// print the result
printf("The list after sorting using quicksort algorithm:\n");
printlist(list,n);
}
