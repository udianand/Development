/* Merge Sort is based on the divide and conquer paradigm. Merge sort works by dividing the array into smaller arrays,
as small as possible, and then sorts the smaller arrays. After sorting these smaller arrays the arrays are combined, merged,
to form a single sorted array. Owing to the divide and combine nature of Merge Sort its Worst Case Complexity is 
O(nlogn).

The following is a simple program showing the working of Merge Sort.
*/


#include<stdio.h>
#define SIZE 50 // Size of Array

void mergeSort(int arr[],int low,int mid,int high); // Sorting and Combining the arrays to form a single sorted array.
void divide(int arr[],int low,int high); // Function to Partition the array into smaller arrays.

int main(){
   
    int merge[SIZE],i,n;

    printf("Enter the total number of elements: ");
    scanf("%d",&n);

    printf("Enter the elements which to be sort: ");
    for(i=0;i<n;i++){
         scanf("%d",&merge[i]);
    }

    divide(merge,0,n-1);

    printf("After merge sorting elements are: ");
    for(i=0;i<n;i++){
         printf("%d ",merge[i]);
    }

   return 0;
}
/* The divide step to partition the array to as small a size is possible. Arrays are divided from the midpoint. 
Note: As a prequisite for division/partition, the index of the low or the starting element of the array should be 
less than the index of the high or the end element of the array. */
void divide(int arr[],int low,int high){

    int mid;

    if(low<high){
         mid=(low+high)/2;
         divide(arr,mid+1,high);
         divide(arr,low,mid);
         mergeSort(arr,low,mid,high);
    }
}

void mergeSort(int arr[],int low,int mid,int high){

    int i,m,k,l,temp[SIZE];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){
                                    
         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

   if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}
