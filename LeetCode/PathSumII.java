/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    public ArrayList<ArrayList<Integer>> pathSum(TreeNode root, int sum) {
        
      ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
      ArrayList<Integer> list = new ArrayList<Integer>();
      
      computeSum(root, sum, list, result);
        
      return result;
    }
    
    private void computeSum(TreeNode node, int sum, ArrayList<Integer> list, ArrayList<ArrayList<Integer>> result)
    {
        if (node == null)
            return;
            
        list.add(node.val);
        sum = sum - node.val;
        
        if (sum==0 && node.left == null && node.right == null)
            result.add(new ArrayList<Integer> (list));
        
        else
        {
            computeSum(node.left, sum, list, result);
            computeSum(node.right, sum, list, result);
        }
        
        list.remove(list.size() - 1);
    }

}
