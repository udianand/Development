/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
     
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
    public void flatten(TreeNode root) {
        
        Stack <TreeNode> rNodes = new Stack <TreeNode>();
        TreeNode temp = root;
        
        while (temp!=null || !rNodes.isEmpty())
        {
            if (temp.right != null)
                rNodes.push(temp.right);
            
            if (temp.left!=null)
            {
                temp.right = temp.left;
                temp.left = null;
            }
            
            else if (!rNodes.isEmpty())
            {
                TreeNode rightNode = rNodes.pop();
                temp.right = rightNode;
                
            }
            
            temp = temp.right;
        }
        
    }
}
