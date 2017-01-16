package com.fi.sort.array;

public class MergeSortArray {
	
	private static final int size = 100;

	public static void main (String args[])
	{
		int unsortArr[] = {8,7,6,5,4,3,2,1};
		Sort(unsortArr);
		printArray(unsortArr);
	}
	
	public static void Sort(int array[])
	{
		Sort(array,0,array.length-1);
		 
	}
	
	private static void Sort(int array[], int low, int high)
	{
		int mid;
		
		if (low<high)
		{
			mid = low + (high-low)/2;
			Sort (array, low, mid);
			Sort(array, mid+1,high);
			Merge(array, low, mid, high);
		}
		
	
	}
	
	private static void Merge(int array[], int low, int mid, int high)
	{
		int extraArray [] = new int [size];
		int startIndex = low;
		int centerIndex = mid+1;
		int index = low; // Index for extra Array.
				

		while (startIndex <= mid && centerIndex <= high)
		{
			if (array[startIndex] <= array[centerIndex])
			{
				extraArray[index] = array[startIndex];
				startIndex = startIndex ++;
				index = index+1;
			}
			
			else
			{
				extraArray[index] = array[centerIndex];
				centerIndex = centerIndex + 1;
				index = index + 1;
			}
		}
				
		 if (startIndex > mid)
		{
			for (int k=centerIndex; k<=high; k++)
			{
				extraArray[index] = array[k]; 
				index = index + 1;
			}
		}
		
		if (centerIndex > high)
		{
			for (int k=startIndex; k<=mid; k++)
			{
				extraArray[index] = array[k];
				index = index + 1;
			}
		}
		
	
        // Copy array items to actual array.
		for (int j = low; j <=high; j++)
			array[j] = extraArray[j];
		
	
	 
	}
	
	private static void printArray(int array[])
	{
		System.out.println("Sorted Array:");
		for (int i = 0; i<array.length; i++)
		{
			System.out.print(array[i] + " ");
		}
	}
}
