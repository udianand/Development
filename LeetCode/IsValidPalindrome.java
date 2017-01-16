/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

public class IsValidPalindrome {
    public boolean isPalindrome(String s) {
        
        if (s.length() < 2)
            return true;
        
        s = s.replaceAll("[^a-zA-Z0-9]","");
        s = s.toLowerCase();
        
        Stack <Character> stack = new Stack<Character>();
        int index = 0;
        
        while (index < (s.length())/2)
        {
            stack.push(s.charAt(index));
            index +=1;
        }
        
        // if s.length is odd increment index by 1.
        if (s.length() % 2 == 1) 
            index +=1;
        
        while (index < s.length())
        {
            if (stack.empty())
             return false;
             
            if (s.charAt(index)!=stack.pop())
                return false;
            else
            index +=1;
        }
           
        return  true;
    }
}
