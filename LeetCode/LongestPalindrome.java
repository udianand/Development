
/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one 
unique longest palindromic substring.
*/

public class LongestPalindrome {
    public String longestPalindrome(String s) {
        
        if (s.isEmpty())
            return null;
        
        if (s.length() == 1)
            return s;
        
        String longest = s.substring(0,1);
        String temp;
        int tempLength;
        
        for (int i = 0; i< s.length(); i++)
        {
            // odd
            temp = helper(s, i, i);
            longest = longest.length() > temp.length() ? longest: temp;
            
            // even
            temp = helper(s,i,i+1);
            longest = longest.length() > temp.length() ? longest: temp;
            
        }
        
        return longest;
    }
    
    String helper(String s, int begin, int end)
    {
        while(begin >=0 && end < s.length() && s.charAt(begin) == s.charAt(end))
        {
            begin --;
            end ++;
        }
        
        return s.substring(begin+1, end);
    }
}