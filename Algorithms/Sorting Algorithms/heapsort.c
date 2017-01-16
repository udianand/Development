#include<stdio.h>

void manage(int *, int);
void heapsort(int *, int, int);
int main()
{
 int arr[20]; 
 int i,j,size,tmp,k;
 printf("\n\t------- Heap sorting method -------\n\n");
 printf("Enter the number of elements to sort : ");
 scanf("%d",&size);
 for(i=1; i<=size; i++)
 {
   printf("Enter %d element : ",i);
   scanf("%d",&arr[i]);
   manage(arr,i);
 }
 //printf("Elements after manage\n");
 //for(i=1; i<=size; i++)
   //  printf("%d ",arr[i]);
 j=size;
 for(i=1; i<=j; i++)
 {
   tmp=arr[1];
   arr[1]=arr[size];
   arr[size]=tmp;
   size--;
   printf("\nSize of array calling function %d\n",size);
   heapsort(arr,1,size);
    for (k =1; k<=size; k++)
     printf("%d ",arr[k]);
   
 }
 printf("\n\t------- Heap sorted elements -------\n\n");
 size=j;
 for(i=1; i<=size; i++)
     printf("%d ",arr[i]);
printf("\n");
 return 0;
}


void manage(int *arr, int i)
{
 int tmp; 
 tmp=arr[i];
 while((i>1)&&(arr[i/2]<tmp))
 {
   arr[i]=arr[i/2];
   i=i/2;
 }
 arr[i]=tmp;
}


void heapsort(int *arr, int i, int size)
{
 printf("\n Size of array %d\n",size);
 int tmp,j,k;
 tmp=arr[i];
 j=i*2;
 printf("\n Value of j %d\n ",j);
 while(j<=size)
 {
   if((j<size)&&(arr[j]<arr[j+1]))
     { j++;
  
   if(arr[j]<arr[j/2]) 
     {
      break;
      }   
    arr[j/2]=arr[j];
    
   
   j=j*2;
 }
 arr[j/2]=tmp;
}
