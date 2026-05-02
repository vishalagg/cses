# Range Xor Queries (ID: 1650)

**Problem Link:** [https://cses.fi/problemset/task/1650/](https://cses.fi/problemset/task/1650/)

## Problem Description

Given an array of n integers, your task is to process q queries of the form: what is the xor sum of values in range [a,b]?

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

    int arr[n];
    int pre[n];

    for (int i=0; i<n; i++) {
        cin >> arr[i];

        if (i > 0) {
            pre[i] = pre[i-1] ^ arr[i];
        } else {
            pre[i] = arr[i];
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        if (a >= 1) {
            cout << (pre[b] ^ pre[a-1]) << "\n";
        } else {
            cout << pre[b] << "\n";
        }
    }
}
```
