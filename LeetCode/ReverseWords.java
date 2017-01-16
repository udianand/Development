public class Solution {
    public String reverseWords(String s) {
        
        String str1[] = s.split(" ");
		StringBuilder sb = new StringBuilder();
		
		for (int i = (str1.length -1); i>=0; i--)
		{
	
			if(str1[i].length()>0)
				sb.append(str1[i] + " ");
		}
	
	  
		return sb.toString().trim();
    }
}