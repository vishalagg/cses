// CSES Problem 1749: List Removals
// Link: https://cses.fi/problemset/task/1749/
// Description: You are given a list consisting of n integers. Your task is to remove elements f...

#include <bits/stdc++.h>
using namespace std;

int arr[200100];
long long tree[800400];

void build(int i, int l, int r) {
    if (l == r) {
        tree[i] = 1;
        return;
    }
    int mid = l + (r - l)/2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    tree[i] = tree[2 * i] + tree[2 * i + 1];
}

void update(int i, int l, int r, int pos) {
    if (pos < l || pos > r) return;
    if (l == r) {
        tree[i] = 0;
        return;
    }
    int mid = l + (r - l)/2;
    update(2 * i, l, mid, pos);
    update(2 * i + 1, mid + 1, r, pos);
    tree[i] = tree[2 * i] + tree[2 * i + 1];
}

long long query(int i, int l, int r, int k) {
    if (tree[i] < k) return 0;
    if (l == r) return l;
    int mid = l + (r - l)/2;
    int left = query(2 * i, l, mid, k);
    if (left != 0) return left;
    return query(2 * i + 1, mid + 1, r, k - tree[2 * i]);
}

int main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    build(1, 1, n);
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;

        int q = query(1, 1, n, k);
        cout << arr[q] << " ";
        if (q != 0) {
            update(1, 1, n, q);
        }
    }
}
