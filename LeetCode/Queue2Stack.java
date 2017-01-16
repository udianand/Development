/*
WAP to implement push and pop stack operations using 2 Queues.
*/

import java.util.LinkedList;
import java.util.Queue;

public class Queue2Stack {

	static Queue<Integer> q1 = new LinkedList<Integer>();
	static Queue<Integer> q2 = new LinkedList<Integer>();

	public static void main(String args[]) {
		int sampleArray[] = { 1, 2, 3, 4, 5 };
		int val = 6;

		pushArray(sampleArray);
		System.out.println(pop());

		pushVal(val);
		System.out.println(pop());
	}

	// Push an array to the stack.
	public static void pushArray(int sampleArray[]) {
		for (int i = 0; i < sampleArray.length; i++) {
			q1.offer(sampleArray[i]);

		}

	}

	// Push a single value to the stack.
	public static void pushVal(int val) {
		q1.offer(val);
	}

	// Pop an element from the stack.
	public static int pop() {
		int lastElement;

		while (q1.size() > 1) {
			q2.offer(q1.poll());
		}

		lastElement = q1.poll();

		while (!q2.isEmpty()) {
			q1.offer(q2.poll());
		}

		return lastElement;
	}

}
