/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class GFG {

	// Initialise an array t of length 31, we will use from
	// index to 1 to 30
	static int[] t = new int[31];

	static int minThrow(int n, int arr[])
	{
		// code here
		for (int i = 0; i < 31; i++) {
			// initialising every index of t with -1
			t[i] = -1;
		}
		// create hashmap to store snakes and ladders start
		// and end for better efficiency
		HashMap<Integer, Integer> h = new HashMap<>();
		for (int i = 0; i < 2 * n; i = i + 2) {
			// store start as key and end as value
			h.put(arr[i], arr[i + 1]);
		}
		// final ans
		return sol(1, h);
	}

	// recursive function
	static int sol(int i, HashMap<Integer, Integer> h)
	{
		// base condintion
		if (i >= 30)
			return 0;

		// checking if block is already visited or
		// not(memoization).
		else if (t[i] != -1)
			return t[i];

		// initialising min as max int value
		int min = Integer.MAX_VALUE;

		// for loop for every dice value from 1 to 6
		for (int j = 1; j <= 6; j++) {
			// incrementing value of i with dice value i.e j
			// taking new variable k
			//->taking new variable so that we dont change i
			// as we will need it again in another iteration
			int k = i + j;
			if (h.containsKey(k)) {
				// checking if this is a snake of ladder
				// if a snake then we continue as we dont
				// need a snake
				if (h.get(k) < k)
					continue;
				// updating if its a ladder to ladder end
				// value
				k = h.get(k);
			}
			// updating min in every iteration for getting
			// minimum throws from this particular block
			min = Math.min(min, sol(k, h) + 1);
		}
		// updating value of t[i] to min
		// memoization
		t[i] = min;
		return t[i];
	}

	// main
	public static void main(String[] args)
	{
		// Given a 5x6 snakes and ladders board
		// You are given an integer N denoting the total
		// number of snakes and ladders and an array arr[]
		// of 2*N size where 2*i and (2*i + 1)th values
		// denote the starting and ending point respectively
		// of ith snake or ladder
		int N = 8;
		int[] arr = new int[2 * N];
		arr[0] = 3;
		arr[1] = 22;
		arr[2] = 5;
		arr[3] = 8;
		arr[4] = 11;
		arr[5] = 26;
		arr[6] = 20;
		arr[7] = 29;
		arr[8] = 17;
		arr[9] = 4;
		arr[10] = 19;
		arr[11] = 7;
		arr[12] = 27;
		arr[13] = 1;
		arr[14] = 29;
		arr[15] = 9;

		System.out.println("Min Dice throws required is "
						+ minThrow(N, arr));
	}
}
