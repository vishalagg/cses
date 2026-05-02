# Static Range Sum Queries (ID: 1646)

**Problem Link:** [https://cses.fi/problemset/task/1646/](https://cses.fi/problemset/task/1646/)

## Problem Description

Given an array of n integers, your task is to process q queries of the form: what is the sum of values in range [a,b]?

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int arr[200100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    long long pref[n + 1];
    pref[0] = arr[0];

    for (int i=1; i<n ;i++) {
        pref[i] = pref[i - 1] + arr[i];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        a--; b--;
        if (a >= 1)
        cout << pref[b] - pref[a - 1] << "\n";
        else
        cout << pref[b] << "\n";
    }

}
```
