/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
   
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

public class Solution {
    public boolean isSymmetric(TreeNode root) {
        
        if (root == null)
            return true;
            
         return isSymmetric(root.left, root.right);     
        
    }
    
    private boolean isSymmetric(TreeNode left, TreeNode right)
    {
        if (left == null)
            return right == null;
        
        if (right == null)
            return left == null;
            
        if (left.val != right.val )
                return false;
        
        return ( isSymmetric(left.left, right.right) && isSymmetric(left.right, right.left));        
    }
}
