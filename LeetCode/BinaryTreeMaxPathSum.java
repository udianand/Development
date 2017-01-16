/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    int maxSum;
    
    public int maxPathSum(TreeNode root) {
        maxSum = (root==null) ? 0 : root.val;
        findPathSum(root);
        return maxSum;
    }
    
    private int findPathSum(TreeNode node)
    {
        if (node==null)
            return 0;
        
        int leftSum = Math.max(findPathSum(node.left),0);
        int rightSum = Math.max(findPathSum(node.right),0);
        
        maxSum = Math.max(maxSum, node.val + leftSum + rightSum);
        
        return node.val + Math.max(leftSum, rightSum);
        
    }
}