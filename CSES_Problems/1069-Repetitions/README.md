# Repetitions (ID: 1069)

**Problem Link:** [https://cses.fi/problemset/task/1069/](https://cses.fi/problemset/task/1069/)

## Problem Description

You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.

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
    string s;
    cin >> s;

    char prev = '\0';
    int count = 0, mx = 0;

    for (char c: s) {
        if (prev == c) count++;
        else count = 1;
        prev = c;
        mx = max(mx, count);
    }
    cout << mx;
}
```
