
/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

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
    public ArrayList<Integer> postorderTraversal(TreeNode root) {
        
        ArrayList<Integer> al = new ArrayList<Integer>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        // use one stack, after visiting a node, insert it into the front of al
        if (root == null)
            return al;
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode top = stack.pop();
            if (top.left != null)
                stack.push(top.left);
            if (top.right != null)
                stack.push(top.right);
            al.add(0, top.val);
        }
        return al;
    }
}
