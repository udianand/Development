/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/


public class SearchInsertPosition {
    public int searchInsert(int[] A, int target) {
        
        if (A ==  null || A.length == 0)
            return 0;
        
        int start = 0;
        int end = A.length - 1;
        return searchInsert(start, end, A, target);    
    }
    
    private int searchInsert(int start, int end, int A[], int target)
    {
        int mid = (start + end)/2;
        
        if (target == A[mid])
            return mid;
        
        else if (target < A[mid])
           return start < mid ? searchInsert(start, mid-1, A, target) : start;
        
        else
        return end > mid ? searchInsert(mid+1, end, A, target) : end+1;
    }
}