/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        
        if (head == null || head.next == null)
            return head; 
            
        ListNode prev = head;
        ListNode current = head.next;
        
        while (current!=null)
        {
            if (prev.val == current.val)
            {
                prev.next = current.next;
                current = current.next;
            }
            
            else
            {
                prev = current;
                current = current.next;
            }
        }
        
        return head;
    }
}
