# Weird Algorithm (ID: 1068)

**Problem Link:** [https://cses.fi/problemset/task/1068/](https://cses.fi/problemset/task/1068/)

## Problem Description

Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm divides it by two, and if n is odd, the algorithm multiplies it by three and adds one. The algorithm repeats this, until n is one. For example, the sequence for n=3 is as follows:
 3 \rightarrow 10 \rightarrow 5 \rightarrow 16 \rightarrow 8 \rightarrow 4 \rightarrow 2 \rightarrow 1
Your task is to simulate the execution of the algorithm for a given value of n.

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

    while (n != 1) {
        cout << n << " ";
        if (n & 1) {
            n = 3 * n + 1;
        } else {
            n = n >> 1;
        }
    }

    cout << 1;
}
```
