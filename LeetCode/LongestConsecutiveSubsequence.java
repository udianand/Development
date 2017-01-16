/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

public class LongestConsecutiveSubsequence {
    public int longestConsecutive(int[] num) {
        
        Set <Integer> set = new HashSet<Integer>();
        int max = 1;
        
        for (int i : num)
            set.add(i);
        
        for (int j: num)
        {
           int left = j-1;
           int right = j+1;
           int count = 1;
            
            while(set.contains(left))
            {
                count +=1;
                set.remove(left);
                left -=1;
            }
            
            while (set.contains(right))
            {
                count +=1;
                set.remove(right);
                right +=1;
            }
            
            max = Math.max(count, max);
        }
        
        return max;
        
    }
}