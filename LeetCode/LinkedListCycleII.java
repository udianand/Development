
/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
 
public class Solution {
    public ListNode detectCycle(ListNode head) {
    ListNode fast, slow;
	fast = head;
	slow = head;
	
	while (fast!=null && fast.next!=null && fast.next.next!=null )
	{
		fast = fast.next.next;
		slow = slow.next;
		
		if (fast == slow)
		{
			fast = head;
	        
	        while (slow!=fast)
			
			 {
				 slow = slow.next;
				 fast = fast.next;
			 }
			 
			return slow;
		}
        
    }
    
    return null;
}
}
