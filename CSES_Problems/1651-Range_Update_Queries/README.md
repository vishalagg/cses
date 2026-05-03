# Range Update Queries (ID: 1651)

**Problem Link:** [https://cses.fi/problemset/task/1651/](https://cses.fi/problemset/task/1651/)

## Problem Description

Given an array of n integers, your task is to process q queries of the following types:

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 200100;

int arr[N];
long long tree[4 * N];

void update(int i, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;

    if (l == r) {
        tree[i] += val;
        return;
    }
    int mid = l + (r - l)/2;
    update(2 * i, l, mid, pos, val);
    update(2 * i + 1, mid + 1, r, pos, val);

    tree[i] = tree[2 * i] + tree[2 * i + 1];
}

long long query(int i, int l, int r, int lq, int rq) {
    if (lq > r || l > rq)   return 0;
    if (lq <= l && rq >= r) {
        return tree[i];
    }
    int mid = l + (r - l)/2;
    return query(2 * i, l, mid, lq, rq) + query(2 * i + 1, mid + 1, r, lq, rq);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int n, q;
    cin >> n >> q;

    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    while (q--) {
        int ch;
        cin >> ch;
        if (ch == 1) {
            int a, b, u;
            cin >> a >> b >> u;

            update(1, 1, n, a, u);
            update(1, 1, n, b + 1, -u);
        } else {
            int k;
            cin >> k;

            cout << arr[k] + query(1, 1, n, 1, k) << "\n";
        }
    }
}
```
