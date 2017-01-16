package com.fi.sort.list;

/*Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes 
 * of the first two lists.*/

// Definition for singly-linked list.
 class ListNode {
 int val;
     ListNode next;
     ListNode(int x) {
         val = x;
         next = null;
     }
}

public class MergeTwoLists {

	public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		
		ListNode tempList1 = l1;
		ListNode tempList2 = l2;
		ListNode mergedList = new ListNode(100);
		ListNode tempMergeList = mergedList;
		
		while (tempList1!=null || tempList2!=null)
		{
			if (tempList1==null && tempList2!=null)
			{
				tempMergeList.next = new ListNode(tempList2.val);
				tempList2 = tempList2.next;
				tempMergeList = tempMergeList.next; 
			}
			
			else if (tempList2==null && tempList1!=null)
			{
				tempMergeList.next = new ListNode(tempList1.val);
				tempList1 = tempList1.next;
				tempMergeList = tempMergeList.next;
			}
			
			else if (tempList1.val <= tempList2.val )
			{
				tempMergeList.next = new ListNode(tempList1.val);
				tempList1 = tempList1.next;
				tempMergeList = tempMergeList.next;
			}
			
			else
			{
				tempMergeList.next = new ListNode(tempList2.val);
				tempList2 = tempList2.next;
				tempMergeList = tempMergeList.next;	
			}
		}
		return mergedList.next;

	}
	
	private static void printList(ListNode mergedList) {
		
		ListNode tempList = mergedList;
		while (tempList!=null)
		{
			System.out.print(tempList.val + " ");
			tempList = tempList.next;
		}
		
	}
	
	public static void main (String args[])
	{
		ListNode l11 = new ListNode(1);
		ListNode l12 = new ListNode(3);
		ListNode l13 = new ListNode(5);
		ListNode l14 = new ListNode(7);
		
		l11.next = l12;
		l12.next = l13;
		l13.next = l14;
	
		ListNode l21 = new ListNode(2);
		ListNode l22 = new ListNode(4);
		ListNode l23 = new ListNode(6);
		ListNode l24 = new ListNode(8);
		
		l21.next = l22;
		l22.next = l23;
		l23.next = l24;
		
		ListNode mergedList = mergeTwoLists(l11,l21);
		
		printList(mergedList);
		
	}

	

}
