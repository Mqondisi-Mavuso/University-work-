#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

// A utility function that returns
// maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Returns the maximum value that
// can be put in BUDGET
int solution(int BUDGET, int price[], int preference[], int n)
{
    int dp[n + 1][BUDGET + 1];

    // Build table dp[][] in bottom up manner
    for (int i = 0; i <= n; i++)                        // This takes O(n x B) where B is the budget 
    {
        for (int w = 0; w <= BUDGET; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (price[i - 1] <= w)
                dp[i][w] = max(preference[i - 1] +
                    dp[i - 1][w - price[i - 1]],
                    dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][BUDGET];
}


int main()
{
    //test cases provided 
    int preference[] = { 60, 100, 120 };
    int price[] = { 10, 20, 30 };
    int BUDGET = 50;
    int n = sizeof(preference) / sizeof(preference[0]);

    cout << solution(BUDGET, price, preference, n);

    return 0;
}


