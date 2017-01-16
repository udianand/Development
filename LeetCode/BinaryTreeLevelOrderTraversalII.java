
/*

Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7]
  [9,20],
  [3],
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
    public ArrayList<ArrayList<Integer>> levelOrderBottom(TreeNode root) {
        
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        ArrayList listVal = new ArrayList();
        
        if (root == null)
            return result;
            
        LinkedList <TreeNode> mainQueue  = new LinkedList<TreeNode>();
        LinkedList <TreeNode> auxQueue = new LinkedList<TreeNode>();
        
        mainQueue.add(root);
        
        while(!mainQueue.isEmpty())
        {
            TreeNode current = mainQueue.poll();
            
            if(current.left!=null)
                auxQueue.offer(current.left);
            
            if(current.right!=null)
                auxQueue.offer(current.right);
            
            listVal.add(current.val);
            
            if (mainQueue.isEmpty())
            {
                result.add(listVal);
                listVal = new ArrayList();
                mainQueue = auxQueue;
                auxQueue = new LinkedList<TreeNode>();
            }
        }
        
        Collections.reverse(result);
        return result;
    }
}
