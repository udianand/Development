/* Given a binary tree, find the maximum path sum.
   The path may start and end at any node in the tree.
   */

/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class MaxPathSolution {
    int maxSum;
    
    public int maxPathSum(TreeNode root) {
		
		/* If root is null initialise maxSum 
		to 0 else the value of the root.*/
        maxSum = (root==null) ? 0 : root.val;
        findPathSum(root);
        return maxSum;
    }
    
    private int findPathSum(TreeNode node)
    {
        if (node==null)
            return 0;
        
        int leftSum = Math.max(findPathSum(node.left),0); // Taking care of -ives
        int rightSum = Math.max(findPathSum(node.right),0); // Same as above.
        
        maxSum = Math.max(maxSum, node.val + leftSum + rightSum);
        
        return node.val + Math.max(leftSum, rightSum);
        
    }
}