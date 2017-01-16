
/*
	Program to reverse a linked list
*/

// LinkedList Definition.
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

public class ReverseList
{
	public static void main (String args[])
	{
		ListNode n1 = new ListNode(1);
		ListNode n2 = new ListNode(2);
		ListNode n3 = new ListNode(3);
		ListNode n4 = new ListNode(4);
		ListNode n5 = new ListNode(5);
		
		n1.next = n2;
		n2.next = n3;
		n3.next = n4;
		n4.next = n5;

		System.out.println(n1.toString()); // Before Reverse.
		System.out.println(Reverse(n1).toString()); // After Reverse.
	}
	
	public static Reverse(ListNode node)
	{
		if (node == null || node.next == null)
			return node;

		ListNode remList = Reverse(node.next);

		ListNode current = remList;

		while (current.next != null) // Find the null node in the reversed list.
			current = current.next;
		
		current.next = node; // Add head element to reversed list.

		node.next = null; // sever the head.next relation.
		
		return remList;	
	}
}

