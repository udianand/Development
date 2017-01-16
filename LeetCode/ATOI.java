//package com.fi.atoi;

//Implement atoi to convert a string to an integer.

public class ATOI {

	public static void main(String args[]) {
		String str = "-2147483s648";
		int result = atoi(str);
		System.out.println("Result:" + result);
	}

	public static int atoi(String str) {

		if (str == null || str.trim().length() == 0) {
			return 0;
		}

		boolean negate = false;
		char num;
		int intNum;
		double result = 0;

		String s = str;
		s = s.trim();
		// String s1, s2; Un-comment in case of line 45.

		if (s.charAt(0) == '-') {
			negate = true;
			s = s.substring(1);
		}

		else if (s.charAt(0) == '+') {
			s = s.substring(1);
		}

		for (int i = 0; i < s.length(); i++) {
			num = s.charAt(i);

			if (!(num >= '0' && num <= '9')) {

				s = s.substring(0, i);
				break;
				
/*TODO: Remove comment in case you want to parse and produce an 
 *      integer resulting from all the integers in the string.*/
				/*
				 * s2 = s.substring(i + 1);
				 * 
				 * s = s1 + s2;
				 * 
				 * i = i - 1;
				 */

			}

		}

		for (int index = 0; index < s.length(); index++) {
			num = s.charAt(index);

			if ((num >= '0' && num <= '9')) {
				intNum = num - '0'; // Sub ASCII values of num and 0 (49) to get
				result += intNum * Math.pow(10, (s.length() - index - 1));
			}
		}

		/*TODO: Remove comment in case you want to parse and produce an 
		 *      integer resulting from all the integers in the string.*/
		/*
		 * for (int index = 0; index < s.length(); index++) { num =
		 * s.charAt(index);
		 * 
		 * if ((num >= '0' && num <= '9')) { intNum = num - '0'; // Sub ASCII
		 * values of num and 0 (49) to get result += intNum * Math.pow(10,
		 * (s.length() - index - 1)); } }
		 */

		if (negate)
			result = -(result);

		if (result > Integer.MAX_VALUE)
			return Integer.MAX_VALUE;

		if (result < Integer.MIN_VALUE)
			return Integer.MIN_VALUE;

		return (int) result;

	}

}
