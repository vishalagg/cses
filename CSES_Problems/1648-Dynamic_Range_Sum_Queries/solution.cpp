// CSES Problem 1648: Dynamic Range Sum Queries
// Link: https://cses.fi/problemset/task/1648/
// Description: Given an array of n integers, your task is to process q queries of the following...

#include <bits/stdc++.h>
using namespace std;

int arr[200100];
long long tree[800400];

void build(int i, int l, int r) {
    if (l == r) {
        tree[i] = arr[l];
        return;
    }
    int mid = l + (r - l)/2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    tree[i] = tree[2*i] + tree[2*i+1];
}

void update(int i, int l, int r, int pos, int val) {
    if (pos < l || pos > r)
    return;

    if (l == r) {
        arr[pos] = val;
        tree[i] = val;
        return;
    }

    int mid = l + (r - l)/2;
    update(2*i, l, mid, pos, val);
    update(2*i+1, mid+1, r, pos, val);
    tree[i] = tree[2*i] + tree[2*i + 1];
}

long long query(int i, int l, int r, int lq, int rq) {
    if (lq > r || l > rq)
    return 0;

    if (lq <= l && r <= rq)
    return tree[i];

    int mid = l + (r - l)/2;

    return query(2*i, l, mid, lq, rq) + query(2*i+1, mid+1, r, lq, rq);
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
        int c;
        cin >> c;
        if (c == 1) {
            int k,u;
            cin >> k >> u;
            k--;
            update(1, 0, n-1, k, u);
        } else {
            int x, y;
            cin >> x >> y;
            x--; y--;
            cout << query(1, 0, n-1, x, y) << "\n";
        }
    }

}
