public class Solution {
    public int numTrees(int n) {
        
        if (n<=1)
            return 1;
        
        int root, left, right;
        int sum = 0;
        
        for (root = 1; root<= n; root++)
        {
            left = numTrees(root-1);
            right = numTrees(n-root);
            
            sum = sum + (left*right);
        }
        
        return sum;
    }
}