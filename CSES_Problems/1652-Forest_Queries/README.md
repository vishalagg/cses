# Forest Queries (ID: 1652)

**Problem Link:** [https://cses.fi/problemset/task/1652/](https://cses.fi/problemset/task/1652/)

## Problem Description

You are given an n \times n grid representing the map of a forest. Each square is either empty or contains a tree. The upper-left square has coordinates (1,1), and the lower-right square has coordinates (n,n).

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    int sum[n + 1][n + 1];
    memset(sum, 0, sizeof(sum));

    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;

        for (int j=1; j<=n; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            if (s[j-1] == '*') sum[i][j] += 1;
        }
    }

    while (q--) {
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        cout << sum[y2][x2] - sum[y1 - 1][x2] - sum[y2][x1 - 1] + sum[y1 - 1][x1 - 1] << "\n";
    }


}
```
