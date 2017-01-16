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
        
        int dummyVal = 1;
        ListNode dummyNode = new ListNode(dummyVal);
        dummyNode.next = head;
        ListNode current = head;
        ListNode prev = dummyNode;
       
        
        while (current!=null)
        {
            boolean repeat = false;
            
            while (current.next!=null && (current.val == current.next.val))
            {
                current = current.next;
                repeat = true;
            }
            
            if (repeat)
                prev.next = current.next;
            
            else
                prev = current;
            
            current = current.next;    
        }
        
        return dummyNode.next;
    }
}