import java.util.Scanner;

public class KnapSack {

	private static void optimizeKnapsack(int N, int maxW) {

		int[] W = new int[N + 1]; // Weight of N items.
		int[] V = new int[N + 1]; // Value of N items.

		for (int n = 1; n <= N; n++) {
			V[n] = (int) (Math.random() * 1000);
			W[n] = (int) (Math.random() * maxW);
		}

		int optVal[][] = new int[N + 1][maxW + 1]; // Optimum Value Array.
		boolean keep[][] = new boolean[N + 1][maxW + 1]; // Keep Count of optimal path.

		for (int n = 1; n <= N; n++) {
			for (int w = 1; w <= maxW; w++) {
				int opt1 = optVal[n - 1][w];
				int opt2 = Integer.MIN_VALUE;

				if (W[n] <= w)
					opt2 = V[n] + optVal[n - 1][w - W[n]];

				optVal[n][w] = Math.max(opt1, opt2);

				keep[n][w] = opt2 > opt1;

			}
		}

		// Determine which items to take.
		// Will backtrack from the nth row and wth column to find optimum path.
		boolean add[] = new boolean[N + 1];
		for (int n = N; n > 0; n--) {
			if (keep[n][maxW]) {
				add[n] = true;
				maxW = maxW - W[n];
			}

			else
				add[n] = false;
		}

		System.out.println("item" + "\t" + "Value" + "\t" + "Weight" + "\t"
				+ "Add");
		for (int n = 1; n <= N; n++) {
			System.out.println(n + "\t" + V[n] + "\t" + W[n] + "\t" + add[n]);
		}
	}

	public static void main(String args[]) {
		Scanner reader = new Scanner(System.in);

		System.out.println("Enter the number of items: ");
		int nitems = reader.nextInt();

		System.out.println("Enter the max Capacity of KnapSack: ");
		int maxCapacity = reader.nextInt();

		optimizeKnapsack(nitems, maxCapacity);
	}

}
