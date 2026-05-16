# Book Shop (ID: 1158)

**Problem Link:** [https://cses.fi/problemset/task/1158/](https://cses.fi/problemset/task/1158/)

## Problem Description

You are in a book shop which sells n different books. You know the price and number of pages of each book.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, x;
int prices[1001], pages[1001];
// int dp[1001][100001];

// int rec(int i, int amount) {
    //     if (amount > x) return 0;

    //     if (i == n) {
        //         return 0;
        //     }

        //     if (dp[i][amount] != -1)
        //         return dp[i][amount];

        //     int op1 = rec(i + 1, amount);
        //     int op2 = 0;

        //     if (amount + prices[i] <= x)
        //         op2 = pages[i] + rec(i + 1, amount + prices[i]);

        //     dp[i][amount] = max(op1, op2);

        //     return dp[i][amount];
        // }

        int main() {
            ios::sync_with_stdio(0);
            cin.tie(0); cout.tie(0);

            cin >> n >> x;


            for (int i=0; i<n; i++) {
                cin >> prices[i];
            }

            for (int i=0; i<n; i++) {
                cin >> pages[i];
            }

            // 	memset(dp, -1, sizeof(dp));

            // dp[i][j] -> max pages can be collected from ith to n'th book if already
            // spent j amount

            // 	cout << rec(0, 0) << "\n";

            //     memset(dp, 0, sizeof(dp)); // dp[n][amount] = 0

            // 	for (int i=n-1; i>=0; i--) {
                // 	    for (int sum =0 ; sum <= x; sum++) {
                    // 	        int op1 = dp[i + 1][sum];
                    // 	        int op2 = 0;
                    // 	        if (sum + prices[i] <= x) {
                        // 	            op2 = pages[i] + dp[i + 1][sum + prices[i]];
                        // 	        }
                        // 	        dp[i][sum] = max(op1, op2);
                        // 	    }
                        // 	}

                        // 	cout << dp[0][0] << "\n";

                        int dp[100001];
                        memset(dp, 0, sizeof(dp));

                        for (int i=n-1; i>=0; i--) {
                            for (int sum = 0; sum <=x; sum++) {
                                int op2 = 0;
                                if (sum + prices[i] <= x)
                                op2 = pages[i] + dp[sum + prices[i]];
                                dp[sum] = max(dp[sum], op2);
                            }
                        }

                        cout << dp[0] << "\n";
                    }
```
