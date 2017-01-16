
/* 
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:
 1. The left subtree of a node contains only nodes with keys less than the node's key.
 2. The right subtree of a node contains only nodes with keys greater than the node's key.
 3. Both the left and right subtrees must also be binary search trees.*/

/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

 public class ValidBST {
    public boolean isValidBST(TreeNode root) {
        
        return ValidateBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
    
    private boolean ValidateBST(TreeNode node, int min, int max)
    {
        if (node == null)
            return true;
    
        else
        {
            if (node.val <= min || node.val >= max)
                return false;
            
            return (ValidateBST(node.left,min,node.val) && ValidateBST(node.right, node.val, max));
            
            }
    }
}