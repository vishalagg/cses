# Christmas Party (ID: 1717)

**Problem Link:** [https://cses.fi/problemset/task/1717/](https://cses.fi/problemset/task/1717/)

## Problem Description

There are n children at a Christmas party, and each of them has brought a gift. The idea is that everybody will get a gift brought by someone else.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<long long> dp(n + 1, 0);

    //dp[i] = (i-1)[dp[i-2] + dp[i-1]];
    dp[0] = 1; dp[1] = 0;

    for (int i=2; i<=n; i++) {
        dp[i] = ((i-1) * ((dp[i-2] + dp[i-1]) % mod)) % mod;
    }

    cout << dp[n];
}
```
