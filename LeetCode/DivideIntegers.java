
/*
Divide two integers without using multiplication, 
division and mod operator.
*/

public class DivideIntegers {

	public static int Divide(int dividend, int divisor) {

		long a = dividend;
		long b = divisor;
		int res = 0;
		int numLeftShift = 0;

		if (b == 0)
			throw new ArithmeticException();

		boolean isNeg = false;
		if (a < 0)
			isNeg = !isNeg;

		if (b < 0)
			isNeg = !isNeg;

		a = Math.abs(a);
		b = Math.abs(b);
		
		while (b << numLeftShift <= a)
			++numLeftShift;
	
		for (int i = numLeftShift; i >= 0; i--) {
			if (b << i <= a) {
				res |= 1 << i;
				a -= b << i;
			}
		}

		if (isNeg)
			res = -res;
		return res;
	}

	public static void main(String args[]) {
		int res = DivideIntegers.Divide(13, 3);
		System.out.println("Result: " + res);
	}
}
