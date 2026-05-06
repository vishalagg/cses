# Dice Combinations (ID: 1633)

**Problem Link:** [https://cses.fi/problemset/task/1633/](https://cses.fi/problemset/task/1633/)

## Problem Description

Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    // long long dp[n + 1];
    // memset(dp, 0, sizeof(dp));
    // dp[0] = 1; dp[1] = 1;


    // for(int i = 2; i <= n; i++) {
        //     for (int j=1; j<=6; j++) {
            //         if (i - j < 0) break;
            //         dp[i] = (dp[i] + dp[i - j]) % mod;
            //     }
            // }

            // cout << dp[n] % mod << "\n";

            //space optimized:
            long long last[6];
            memset(last, 0, sizeof(last));
            last[0] = 1;

            for (int i=1; i<=n; i++) {
                long long curr = 0;
                for (long long x: last)
                curr = (curr + x) % mod;

                for (int j = 5; j > 0; j--) {
                    last[j] = last[j-1];
                }
                last[0] = curr;
            }

            cout << last[0];
        }
```
