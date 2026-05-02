# Static Range Minimum Queries (ID: 1647)

**Problem Link:** [https://cses.fi/problemset/task/1647/](https://cses.fi/problemset/task/1647/)

## Problem Description

Given an array of n integers, your task is to process q queries of the form: what is the minimum value in range [a,b]?

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int arr[200100];
int tree[800400];

void build(int i, int l, int r) {
    if (l == r) {
        tree[i] = arr[l];
        return;
    }
    int mid = l + (r - l)/2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    tree[i] = min(tree[2*i], tree[2*i+1]);
}

int query(int i, int l, int r, int lq, int rq) {
    if (lq > r || l > rq)
    return 1e9;

    if (lq <= l && r <= rq)
    return tree[i];

    int mid = l + (r - l)/2;

    return min(query(2*i, l, mid, lq, rq), query(2*i+1, mid+1, r, lq, rq));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n-1);

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << query(1, 0, n-1, x, y) << "\n";
    }

}
```
