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
    public ListNode partition(ListNode head, int x) {
   
   if (head == null)
    return null;
    
   ListNode fakeHead1 = new ListNode(0);
   ListNode fakeHead2 = new ListNode(0);
   fakeHead1.next = head;
   
   ListNode current = head;
   ListNode prev = fakeHead1;
   ListNode newList = fakeHead2;
   
    while (current!=null)
    {
        if (current.val < x)
        {
            current = current.next;
            prev = prev.next;
        }
        
        else
        {
            newList.next = current;
            prev.next = current.next;
            current = prev.next;
            newList = newList.next;
        }
    }
    
    newList.next = null;
    prev.next = fakeHead2.next;
    
    return fakeHead1.next;
    }
}