# Missing Number (ID: 1083)

**Problem Link:** [https://cses.fi/problemset/task/1083/](https://cses.fi/problemset/task/1083/)

## Problem Description

You are given all numbers between 1,2,\ldots,n except one. Your task is to find the missing number.

## Solution

```cpp
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;
const int MAX = 2 * 100100;
long double PI = acos(-1.0);
int mod = 1e9 + 7;

signed main() {

    ll n;
    cin >> n;
    ll sum = 0;

    for (int i=0; i<n-1; i++) {
        int t;
        cin >> t;
        sum += t;
    }
    cout << ((n * (n + 1))/2) - sum;
}
```
