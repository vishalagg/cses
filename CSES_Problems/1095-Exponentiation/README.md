# Exponentiation (ID: 1095)

**Problem Link:** [https://cses.fi/problemset/task/1095/](https://cses.fi/problemset/task/1095/)

## Problem Description

Your task is to efficiently calculate values a^b modulo 10^9+7.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long pow(int a, int b) {
    if (b == 0) return 1;
    if (a == 0) return 0;

    if (b % 2 == 0) {
        long long h = pow(a, b / 2);
        return (h * h) % mod;
    }

    return (a * pow(a, b - 1)) % mod;
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;

        cout << pow(a, b) << "\n";
    }
}
```
