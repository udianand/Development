
// Implement pow(x, n).

public class Pow {
    public double pow(double x, int n) {
        
        double temp;
        
        if (x == 1)
            return 1;
        
        if (n == 0)
            return 1;
        
       /*
        * When n < 0 (-ive)
        * Change x = 1/x and make
        * n +ive.
        */
        
        if (n < 0)
        {
            x = 1/x;
            n = -n;
        }  
        
        temp = pow(x,n/2);
        
        return (n % 2 == 0) ? temp*temp:temp*temp*x ; 
        
    }
}