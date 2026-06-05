# Exponentiation (ID: 1095)

**Problem Link:** [https://cses.fi/problemset/task/1095/](https://cses.fi/problemset/task/1095/)

## Problem Description

Your task is to efficiently calculate values a^b modulo 10^9+7.

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

    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;

        cout << powmod(a, b, 1e9+7) << "\n";
    }

}
```
