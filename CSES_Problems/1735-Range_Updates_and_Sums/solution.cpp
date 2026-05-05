// CSES Problem 1735: Range Updates and Sums
// Link: https://cses.fi/problemset/task/1735/
// Description: Your task is to maintain an array of n values and efficiently process the follow...

#include <bits/stdc++.h>
using namespace std;

long long arr[200100];

struct node {
    long long sum;
    long long add;
    long long set;

    node() {
        sum = 0; add = 0; set = 0;
    }

    node(long long s) {
        sum = s; add = 0; set = 0;
    }
};

node tree[800400];

node merge(node a, node b) {
    return node(a.sum + b.sum);
}

void push_down(int i, int l, int r) {
    if (l == r) return;
    if (tree[i].set) {
        tree[2 * i].set = tree[i].set;
        tree[2 * i + 1].set = tree[i].set;
        tree[2 * i].add = 0;
        tree[2 * i + 1].add = 0;
    }
    if (tree[i].add) {
        tree[2 * i].add += tree[i].add;
        tree[2 * i + 1].add += tree[i].add;
    }
}

void push(int i, int l, int r) {
    // apply, push_down, clear
    if (tree[i].set == 0 && tree[i].add == 0)   return;

    if (tree[i].set) {
        tree[i].sum = (r - l + 1) * tree[i].set;
    }

    if (tree[i].add) {
        tree[i].sum += (r - l + 1) * tree[i].add;
    }

    push_down(i, l, r);

    tree[i].set = 0;
    tree[i].add = 0;
}

void build(int i, int l, int r) {
    if (l == r) {
        tree[i] = node(arr[l]);
        return;
    }
    int mid = l + (r - l)/2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
}

void update_add(int i, int l, int r, int lq, int rq, int val) {
    push(i, l, r);
    if (l > rq || lq > r)   return;
    if (lq <= l && rq >= r) {
        tree[i].add += val;
        push(i, l, r);
        return;
    }
    int mid = l + (r - l)/2;
    update_add(2 * i, l, mid, lq, rq, val);
    update_add(2 * i + 1, mid + 1, r, lq, rq, val);
    tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
}

void update_set(int i, int l, int r, int lq, int rq, int val) {
    push(i, l, r);
    if (l > rq || lq > r)   return;
    if (lq <= l && rq >= r) {
        tree[i].set = val;
        push(i, l, r);
        return;
    }
    int mid = l + (r - l)/2;
    update_set(2 * i, l, mid, lq, rq, val);
    update_set(2 * i + 1, mid + 1, r, lq, rq, val);
    tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
}

node query(int i, int l, int r, int lq, int rq) {
    push(i, l, r);
    if (l > rq || lq > r)   return node();
    if (lq <= l && rq >= r) return tree[i];
    int mid = l + (r - l)/2;
    return merge(query(2 * i, l, mid, lq, rq), query(2 * i + 1, mid + 1, r, lq, rq));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    build(1 ,1, n);

    while (q--) {
        int ch;
        cin >> ch;

        if (ch == 1) {
            int a, b, x;
            cin >> a >> b >> x;
            update_add(1, 1, n, a, b, x);
        } else if (ch == 2) {
            int a, b, x;
            cin >> a >> b >> x;
            update_set(1, 1, n, a, b, x);
        } else {
            int a, b;
            cin >> a >> b;
            node ans = query(1, 1, n, a, b);
            cout << ans.sum << "\n";
        }
    }
}
