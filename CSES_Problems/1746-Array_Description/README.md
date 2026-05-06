# Array Description (ID: 1746)

**Problem Link:** [https://cses.fi/problemset/task/1746/](https://cses.fi/problemset/task/1746/)

## Problem Description

You know that an array has n integers between 1 and  m, and the absolute difference between two adjacent values is at most 1.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(m + 1, 0));

    if (arr[0] == 0) {
        fill(dp[0].begin(), dp[0].end(), 1);
    } else {
        dp[0][arr[0]] = 1;
    }

    for (int i=1; i<n; i++) {
        if (arr[i] == 0) {
            for (int j=1; j<=m; j++) {
                if (j - 1 > 0)
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
                if (j + 1 <= m)
                dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
            }
        } else {
            if (arr[i] - 1 > 0)
            dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i]-1]) % mod;
            dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i]]) % mod;
            if (arr[i] + 1 <= m)
            dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i]+1]) % mod;
        }
    }

    long long total = 0;
    for (int i=1; i<=m; i++) {
        total = (total + dp[n-1][i]) % mod;
    }

    cout << total;
}
```
