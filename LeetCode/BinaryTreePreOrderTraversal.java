/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

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
    public ArrayList<Integer> preorderTraversal(TreeNode root) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        
        if (root == null)
            return list;
        
        Stack <TreeNode> nodeStack = new Stack <TreeNode> ();
        nodeStack.push(root);
        
        while (!nodeStack.isEmpty())
        {
            TreeNode current = nodeStack.pop();
            list.add(current.val);
            
            if (current.right!=null)
                nodeStack.push(current.right);
            
            if (current.left!=null)
                nodeStack.push(current.left);
            
        }
        
        return list;
    }
}
