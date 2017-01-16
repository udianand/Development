//package com.fi.checkcycle;

//Given a linked list, determine if it has a cycle in it.

class ListNode {

	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}

public class CheckCycle {

	public static boolean hasCycle(ListNode head) {

		ListNode fast, slow;
		fast = head;
		slow = head;

		while (fast != null && fast.next != null && fast.next.next != null) {
			fast = fast.next.next;
			slow = slow.next;

			if (fast == slow)
				return true;

		}

		return false;
	}

	public static void main(String args[]) {
		
		ListNode n1 = new ListNode(1);
		ListNode n2 = new ListNode(2);
		ListNode n3 = new ListNode(3);
		ListNode n4 = new ListNode(4);
		ListNode n5 = new ListNode(5);
		ListNode n6 = new ListNode(6);
		ListNode n7 = new ListNode(7);

		n1.next = n2;
		n2.next = n3;
		n3.next = n4;
		n4.next = n5;
		n5.next = n6;
		n6.next = n7;
		n7.next = n4;

		System.out.println(hasCycle(n1));
	}

}
