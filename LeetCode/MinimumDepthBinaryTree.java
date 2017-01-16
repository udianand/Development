/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    
    private static int nodeHeight = 1;
    
    public int minDepth(TreeNode root) {
         
         if (root == null)
            return 0;
        
        LinkedList <TreeNode> nodes = new LinkedList<TreeNode>();
        LinkedList <Integer> counts = new LinkedList<Integer>();
        
        counts.add(1);
        nodes.add(root);
        
        while(!nodes.isEmpty())
        {
            TreeNode current = nodes.poll();
            int count = counts.poll();
            
            if (current.left!=null)
            {
                nodes.add(current.left);
                counts.add(count + 1);
            }
            
            if (current.right!=null)
            {
                nodes.add(current.right);
                counts.add(count + 1);
            }
            
            if (current.left == null && current.right== null)
                return count;
        }
        
        return 0;
    }
}
