/*

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
    public boolean hasPathSum(TreeNode root, int sum) {
        
        if (root == null)
            return false;
            
        LinkedList <TreeNode> nodes = new LinkedList<TreeNode>();
        LinkedList <Integer> nodeVal = new LinkedList<Integer>();
        
        nodes.add(root);
        nodeVal.add(root.val);
        
        while (!nodes.isEmpty())
        {
            TreeNode node = nodes.poll();
            int result = nodeVal.poll();
            
            if (node.left == null && node.right == null && result == sum)
                    return true;
            
            if (node.left!=null)
            {
                nodes.add(node.left);
                nodeVal.add(result + node.left.val);
            }
            
            if (node.right!=null)
            {
                nodes.add(node.right);
                nodeVal.add(result + node.right.val);
            }
        
        }
        
        return false;
    }
}    
    
