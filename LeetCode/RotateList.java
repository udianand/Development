/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    
    public static ListNode rotateRight(ListNode head, int n) {
        if (n == listLength(head) || n <= 0 || listLength(head) == 1)
				return head;
	
		int count = 1;
		ListNode firstList, secondList, rotatedList;
		
		// Initial case
		firstList = head;
		secondList = splitList(firstList); // Remove the last Node.
		
		while (count <= n-1)
		{
			firstList = mergeList(firstList, secondList); // Prefix last Node to front of list.
			secondList = splitList(firstList);
			count = count + 1;
		}
		
		rotatedList = mergeList(firstList, secondList);
		
		return rotatedList;
    }
	
	private static ListNode mergeList(ListNode first, ListNode second)
	{
		ListNode tempHead = second;
		
		while (tempHead!=null)
		{
			if (tempHead.next == null)
			{
				tempHead.next = first;
				break;	
			}
			
			tempHead = tempHead.next;
		}
		
		return second;
	}
	
	private static ListNode splitList(ListNode node)
	{
		
		ListNode tempNode = node;
		ListNode secondList = null;
		
		while (tempNode!=null)
		{
			
			if (tempNode.next.next == null)
			{
				secondList = tempNode.next;
				tempNode.next = null;
			}

			tempNode = tempNode.next;
		}
		
	    return secondList;
	}
	
	private static int listLength(ListNode node)
	{
		int count = 0;
		ListNode tempNode = node;
		
		while (tempNode != null)
		{
			count = count + 1;
			tempNode = tempNode.next;
		}
		
		return count; 
	}
}
