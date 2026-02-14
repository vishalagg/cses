# Permutations (ID: 1070)

**Problem Link:** [https://cses.fi/problemset/task/1070/](https://cses.fi/problemset/task/1070/)

## Problem Description

A permutation of integers 1,2,\ldots,n is called beautiful if there are no adjacent elements whose difference is 1.

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
    int n;
    cin >> n;
    int t = n-1;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    if (n < 4) {
        cout << "NO SOLUTION";
        return 0;
    }
    while (t > 0) {
        cout << t << " ";
        t -= 2;
    }
    t = n;
    while (t > 0) {
        cout << t << " ";
        t -= 2;
    }
}
```
