
/*

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
    public ArrayList<ArrayList<Integer>> levelOrder(TreeNode root) {
        
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        ArrayList listVal = new ArrayList();
       
        if(root == null)
            return result;
        
        LinkedList<TreeNode> mainQueue = new LinkedList<TreeNode>();
        LinkedList<TreeNode> auxQueue = new LinkedList<TreeNode>();
        
        mainQueue.add(root);
        
        while(!mainQueue.isEmpty()){
            
            TreeNode node = mainQueue.remove();
            
            if(node.left != null)
                auxQueue.add(node.left);
            
            if(node.right != null)
                auxQueue.add(node.right);
            
            listVal.add(node.val);
            
            if(mainQueue.isEmpty()){
                mainQueue = auxQueue;
                auxQueue = new LinkedList<TreeNode>();
                result.add(listVal);
                listVal = new ArrayList();
            }
            
             
        }
        return result;
        
    }
}
