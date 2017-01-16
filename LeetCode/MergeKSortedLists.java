/*
 * Merge k sorted linked lists and return it as one sorted list. 
 */


import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;


// Linked List Definition.
 class ListNode
{
	int val;
	ListNode next;
	
	ListNode(int value)
	{
		val = value;
		next = null;
	}
}
 
public class MergeKSortedLists {
	
	public static ListNode mergeKLists(ArrayList<ListNode> lists)
	{
		 if (lists == null || lists.isEmpty()) return null;  
		 
		int dummyVal = 0; // Dummy Value to initialize the sentinel node.
	   Comparator <ListNode> comparator = new Comparator<ListNode>()
			   {
		           @Override
		   			public int compare(ListNode n1, ListNode n2)
		   			{
		        	   if (n1.val > n2.val)
							return 1;
						else if(n1.val == n2.val)
							return 0;
						else 
							return -1;
		   			}
			   };
			   
		PriorityQueue <ListNode>pq = new PriorityQueue<ListNode>(lists.size(), comparator);
		
		// Add elements to the Priority Queue.
		for (ListNode list: lists)
		{
			if (list!=null)	
			pq.add(list);
			
		}
			
		ListNode head = new ListNode(dummyVal);
		ListNode prev = head;
		
		while (pq.size()>0)
		{
			ListNode temp = pq.poll();
			prev.next = temp;
			
			if (temp.next != null)
			pq.add(temp.next);
			
			prev = prev.next;
		}
		
		return head.next;
	}

	public static void main (String args[])
	{
		ArrayList<ListNode> list = new ArrayList<ListNode>();
		
		// First List 
		ListNode first_FirstList = new ListNode(7);
		ListNode second_FirstList = new ListNode(8);
		ListNode third_FirstList = new ListNode(9);
		
		first_FirstList.next = second_FirstList;
		second_FirstList.next = third_FirstList;
		
		
		// Second List
		ListNode first_SecondList = new ListNode(4);
		ListNode second_SecondList = new ListNode(5);
		ListNode third_SecondList = new ListNode(6);
		
		first_SecondList.next = second_SecondList;
		second_SecondList.next = third_SecondList;
		
		
		// Third List 
		ListNode first_ThirdList = new ListNode(1);
		ListNode second_ThirdList = new ListNode(2);
		ListNode third_ThirdList = new ListNode(3);
		
		first_ThirdList.next = second_ThirdList;
		second_ThirdList.next = third_ThirdList;
		
		// Add the three lists to ArrayList lists.
		list.add(first_FirstList);
		list.add(first_SecondList);
		list.add(first_ThirdList);
		
		ListNode result = mergeKLists(list);
		ListNode temp = result;
		
		while (temp!=null)
		{
			System.out.print(temp.val + "  ");
			temp = temp.next;
		}
	}
}
