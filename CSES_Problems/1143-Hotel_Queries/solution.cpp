// CSES Problem 1143: Hotel Queries
// Link: https://cses.fi/problemset/task/1143/
// Description: There are n hotels on a street. For each hotel you know the number of free rooms...

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
    tree[i] = max(tree[2 * i], tree[2 * i + 1]);
}

void update(int i, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        arr[l] = val;
        tree[i] = val;
        return;
    }
    int mid = l + (r - l)/2;
    update(2 * i, l, mid, pos, val);
    update(2 * i + 1, mid + 1, r, pos, val);
    tree[i] = max(tree[2 * i], tree[2 * i + 1]);
}

int query(int i, int l, int r, int val) {
    if (tree[i] < val)
    return 0;
    if (l == r) {
        if (tree[i] >= val) return l;
        return 0;
    }
    int mid = l + (r - l)/2;
    int left = query(2 * i, l, mid, val);
    if (left == 0) {
        return query(2 * i + 1, mid + 1, r, val);
    }
    return left;
}

int main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    build(1, 1, n);

    while (m--) {
        int x;
        cin >> x;

        int i = query(1, 1, n, x);
        cout << i << " ";
        if (i > 0)
        update(1, 1, n, i, arr[i] - x);

    }
}
