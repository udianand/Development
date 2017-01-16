/*

The problem:

Given a singly linked list L: L0→L1→ … →Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

For example, given {1,2,3,4}, reorder it to {1,4,2,3}. You must do this in-place without altering the nodes’ values.

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

    public static void reorderList(ListNode head) {
        if (head != null && head.next!=null)
	{
		ListNode slow, fast, second;;
		slow = head;
		fast = head;
		
		while(fast!=null && fast.next!=null && fast.next.next!=null)
		{
			fast = fast.next.next;
			slow = slow.next;	
		}
		
		second = slow.next;
    		slow.next = null;
		
		second = reverseList(second);
		head = mergeList(head, second);
		
	}
       
    }
    
    private static ListNode mergeList (ListNode first, ListNode second)
	{
		ListNode list1 = first;
		ListNode list2 = second;
		
		while (list2!=null)
		{
			ListNode temp1 = list1.next;
			ListNode temp2 = list2.next;
			
			list1.next = list2;
			list2.next = temp1;
			
			list2 = temp2;
			list1 = temp1;
		}
		
		return first;
	}
    
	private static ListNode reverseList(ListNode head)
	{
		if (head == null || head.next == null)
		{
			return head;
		}
		
		ListNode currentNode = head;
		ListNode nextNode = head.next;
		
		while (nextNode!=null)
		{
			ListNode tempNode = nextNode.next; 
			nextNode.next = currentNode;
			currentNode = nextNode;
			nextNode = tempNode;
		}
		
		head.next = null;
		
		return currentNode;
	}

}
