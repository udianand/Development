
/*
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
*/

public class Sqrt {

	public static int sqrt(int x) 
	{
		if (x<1)
			throw new RuntimeException();
		
		if (x==1)
			return x;
		
		int low = 0;
		int high = 1 + x/2;
		int mid;
		int square;
		
		while ((low+1) < high)
		{
			mid = low + (high - low)/2;
			square = mid * mid;
			
			if (square == x)
					return mid;
			
			else if (square < x)
				low = mid;
			else
				high = mid;
		}
		return low;
    }
	
	public static void main (String args[])
	{
		System.out.println("Sqrt of " + 14 + " is: " + sqrt(14) );
		System.out.println("Sqrt of " + 174 + " is: " + sqrt(174) );
		System.out.println("Sqrt of " + 2147395599 + " is: " + sqrt(2147395599) ); // Fails in this case !!!
	}
}
