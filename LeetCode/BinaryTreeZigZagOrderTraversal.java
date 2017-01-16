
/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
    public ArrayList<ArrayList<Integer>> zigzagLevelOrder(TreeNode root) {
        
        ArrayList <ArrayList<Integer>> result = new ArrayList <ArrayList<Integer>>();
        ArrayList listVal = new ArrayList();
        
        if(root == null)
            return result;
        
        LinkedList <TreeNode> stack1 = new LinkedList<TreeNode>();
        LinkedList <TreeNode> stack2 = new LinkedList<TreeNode>();
        
        stack1.push(root);
        boolean zigzag = true;
        
        while (!stack1.isEmpty())
        {
            TreeNode curNode = stack1.pop();
            
            if (zigzag)
            {
                if (curNode.left != null)
                    stack2.push(curNode.left);
                
                if (curNode.right!=null)
                    stack2.push(curNode.right);
            }
            
            else
            {
                 if (curNode.right!=null)
                    stack2.push(curNode.right);
                    
                if (curNode.left!=null)
                    stack2.push(curNode.left);
            }
            
            listVal.add(curNode.val);
            
            if (stack1.isEmpty())
            {
                stack1 = stack2;
                stack2 = new LinkedList<TreeNode>();
                result.add(listVal);
                listVal = new ArrayList();
                zigzag =  (zigzag == true) ? false: true;
            }
        }
        
        return result;
    }
}
