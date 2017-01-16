
/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6 
*/
 
public class Solution {
    public int evalRPN(String[] tokens) {
        String operators = "+-/*";
		Stack<String> digits = new Stack<String>();

		for (String t : tokens) {
			if (!operators.contains(t))
				digits.push(t);

			else {
				int index = operators.indexOf(t);
				int digit1 = Integer.valueOf(digits.pop());
				int digit2 = Integer.valueOf(digits.pop());

				switch (index) {
				case 0: {
					int result = digit1 + digit2;
					digits.push(String.valueOf(result));
					break;
				}
				case 1: {
					int result = digit2 - digit1;
					digits.push(String.valueOf(result));
					break;
				}
				case 2: {
					int result = digit2 / digit1;
					digits.push(String.valueOf(result));
					break;
				}
				case 3: {
					int result = digit1 * digit2;
					digits.push(String.valueOf(result));
					break;
				}
				}
			}
			
		}

		return Integer.valueOf(digits.pop());
    }
}
