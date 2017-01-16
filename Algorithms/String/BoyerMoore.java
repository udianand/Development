
public class BoyerMoore {
    private final int R;     // the radix
    private int[] right;     // the bad-character skip array
	private String pat;      // Pattern provided as a string

    // pattern provided as a string
    public BoyerMoore(String pat) {
        this.R = 256;
        this.pat = pat;
        right = new int[R];
        for (int c = 0; c < R; c++)
            right[c] = -1;
        for (int j = 0; j < pat.length(); j++)
             right[pat.charAt(j)] = j;
			 }
   

    // return offset of first match; N if no match
  public int search(String txt) {
        int M = pat.length();
       
        int N = txt.length();
        
        int skip;
        for (int i = 0; i <= N - M; i += skip) {
            skip = 0;
           
            for (int j = M-1; j >= 0; j--) {
				
                if (pat.charAt(j) != txt.charAt(i+j)) {
                    skip = Math.max(1, j - right[txt.charAt(i+j)]);
                    break;
                }
            }
         
            if (skip == 0) 
               return i;    // if pattern found
        }
        return N;        // if pattern not found
    }

	
  
    // Main Program
    public static void main(String[] args) {
        String txt = "FINDINAHAYSTACKNEEDELNOFINDNEEDLE";
        String pat = "NEEDLE";
        
        BoyerMoore boyermoore1 = new BoyerMoore(pat);
        
        int offset1 = boyermoore1.search(txt);
		
		//print results
        System.out.println("text:    " + txt);
		System.out.print("pattern: ");
        System.out.print(offset1);
        for (int i = 0; i < offset1; i++)
            System.out.print(" ");
        System.out.println(pat);

        
    }
}
