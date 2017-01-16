/*
Convert Sorted List to Binary Search Tree
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
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
    
    static ListNode auxNode;
    
    public TreeNode sortedListToBST(ListNode head) {
        
        auxNode = head;
        int listSize = countNodes(head);
        return sortedListToBST(0, listSize-1);
    }
    
    private int countNodes(ListNode head)
    {
        ListNode temp = head;
        int count = 0;
        
        while (temp!=null)
        {
            count = count + 1;
            temp = temp.next;
        }
        
        return count;
    }
    
    private TreeNode sortedListToBST(int start, int end)
    {
        if (start > end)
            return null;
            
        int mid = (end - start)/2 + start;
        
        TreeNode left = sortedListToBST(start, mid-1);
        
        TreeNode parent = new TreeNode(auxNode.val);
        auxNode = auxNode.next;
        
        TreeNode right = sortedListToBST(mid+1, end);
        
        parent.left = left;
        parent.right = right;
        
        return parent;
    }
}
