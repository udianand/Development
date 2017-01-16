public class Solution {
    public int trap(int[] A) {
        // Start typing your Java solution below
	        // DO NOT write main() function
	        // check the max from the left to right
	        int size = A.length;
	        if(size == 0) return 0;

	        int[] left_to_right_max = new int[size];
	        int[] right_to_left_max = new int[size];

	        left_to_right_max[0] = A[0];
	        for(int i = 1; i < size; i++) {
	            if(A[i] > left_to_right_max[i-1]) {
	                left_to_right_max[i] = A[i];
	            } else {
	                left_to_right_max[i] = left_to_right_max[i-1];
	            }
	        }
	        
	     
	        
	        right_to_left_max[size-1] = A[size-1];
	        for(int i = size - 2; i >= 0; i--) {
	            if(right_to_left_max[i+1] < A[i]) {
	                right_to_left_max[i] = A[i];
	            } else {
	                right_to_left_max[i] = right_to_left_max[i+1];
	            }
	        }
	        
	     
	        // find the max water trapped
	        int trapped_max = 0;
	        for(int i = 0; i < size; i++) {
	            if(left_to_right_max[i] > A[i] &&
	               right_to_left_max[i] > A[i]) {
	                   trapped_max += Math.min(left_to_right_max[i] - A[i],
	                                           right_to_left_max[i] - A[i]);
	               }
	        }
	        
	        return trapped_max;
        
    }
}