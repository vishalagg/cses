# Bit Strings (ID: 1617)

**Problem Link:** [https://cses.fi/problemset/task/1617/](https://cses.fi/problemset/task/1617/)

## Problem Description

Your task is to calculate the number of bit strings of length n.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

long long powmod(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;

    while (exp > 0) {
        if (exp & 1) {
            res = (res * base) % mod;
        }
        exp >>= 1;
        base = (base * base) % mod;
    }

    return res;
}

int main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    cout << powmod(2, n, 1e9 + 7);
}
```
