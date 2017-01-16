/* Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest 
path from the root node down to the farthest leaf node.
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
public class MaxDepthSolution {

    private static int nodeHeight = 1;
    
    public int maxDepth(TreeNode root) {
        
        if (root == null)
            return 0;
        
        else if (root.left == null && root.right == null)
            return 1;
            
        int leftHeight = maxDepth(root.left);
        int rightHeight = maxDepth(root.right);
        
        return (nodeHeight + Math.max(leftHeight,rightHeight));
    }
}