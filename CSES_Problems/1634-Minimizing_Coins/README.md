# Minimizing Coins (ID: 1634)

**Problem Link:** [https://cses.fi/problemset/task/1634/](https://cses.fi/problemset/task/1634/)

## Problem Description

Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(x + 1, 1e9);

    dp[0] = 0;

    for (int i=1; i<=x; i++) {
        for (int coin: arr) {
            if (i - coin >= 0)
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    if (dp[x] == 1e9)
    cout << "-1";
    else
    cout << dp[x];
}
```
