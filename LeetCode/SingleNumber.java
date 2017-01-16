
/*Given an array of integers, every element appears twice except for one. 
 *Find that single one.*/


/* Key: Use the XOR operation to find the single number.
 * The XOR operator will return a 1, or TRUE, if both numbers being 
 * compared are different. But, if the numbers being compared are the 
 * same it will return a 0 for FALSE.
 */

public class SingleNumber {

	public static int singleNumber(int[] A) {
        
		int result = 0;
		int arrLen = A.length;
		
		for (int index = 0; index < arrLen; index++)
		{
			result = result ^ A[index]; // XOR Operation.
		}
		return result;
	
    }
	
	public static void main (String args[])
	{
		int sampleArray [] = {1,1,2,2,3,4,4};
		
		System.out.println(singleNumber(sampleArray));
	}
}
