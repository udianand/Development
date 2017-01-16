/* 
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.*/


/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class SumRootToLeaf {
    
    public int sumNumbers(TreeNode root) {
        
        int initialPathSum = 0;
        return sumNumbers(root, initialPathSum);
        
    }
    
    private int sumNumbers(TreeNode node, int pathSum)
    {
        if (node == null)
            return 0;
            
            pathSum = (pathSum*10) + node.val;
            
            if (node.left == null && node.right == null)
            {
                
                return pathSum;
            }
            
            int sum = sumNumbers(node.left, pathSum) + sumNumbers(node.right, pathSum);
            return sum;
    }
}
