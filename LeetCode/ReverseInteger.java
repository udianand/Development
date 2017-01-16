/* Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321 */

public class ReverseInteger {
    public int reverse(int x) {
        
        boolean check = false;
        int revInt = 0;
        int rem;
        
        if ( x < 0 )
        {
            x = 0 - x;
            check = true;
        }
        
        while (x > 0)
        {
          rem = x % 10;
          x = x/10;
          revInt = revInt * 10 + rem;
        }
        
        if (check)
            revInt = 0 - revInt;
            
        return revInt;    
    }
}