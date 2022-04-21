/* A Naive recursive implementation of
0-1 Knapsack problem */
// Naive recursive approach wich takes time complexity of O(2^n)

#include <iostream>
#include <math.h>

using namespace std;

// A utility function that returns
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int profit[], int n)
{
	// Base Case
	if (n == 0 || W == 0)
		return 0;
	if (wt[n - 1] > W)
		return knapSack(W, wt, profit, n - 1);

	// Return the maximum of two cases:
	else
		return max(profit[n - 1] + knapSack(W - wt[n - 1],wt, profit, n - 1),knapSack(W, wt, profit, n - 1));
}

int main()
{
	// data inputs
	int profit[] = { 60, 100, 120 };				// profit of each product
	int wt[] = { 10, 20, 30 };					    // weight of each product
	int W = 50;									    // maximum weight of the knapsack
	int n = sizeof(profit) / sizeof(profit[0]);
	cout << knapSack(W, wt, profit, n);
	return 0;
}