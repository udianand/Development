/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

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
    public ArrayList<Integer> inorderTraversal(TreeNode root) {
        
        ArrayList<Integer> result = new ArrayList<Integer>();
        LinkedList<TreeNode> stack = new LinkedList<TreeNode>();
        
        if (root == null)
            return result;
            
        TreeNode temp = root;
        
        while(!stack.isEmpty() || temp != null)
        {
           // if it is not null, push to stack
            //and go down the tree to left
            
            if (temp!=null)
            {
                stack.push(temp);
                temp = temp.left;
            }
            
             // if no left child
            // pop stack, process the node
            // then let p point to the right
            
            else
            {
                TreeNode stackNode = stack.pop();
                result.add(stackNode.val);
                temp = stackNode.right; 
            }
        }
        
        return result;
    }
}
