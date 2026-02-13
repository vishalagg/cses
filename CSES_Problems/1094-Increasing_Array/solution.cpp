// CSES Problem 1094: Increasing Array
// Link: https://cses.fi/problemset/task/1094/
// Description: You are given an array of n integers. You want to modify the array so that it is...

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;
const int MAX = 2 * 100100;
long double PI = acos(-1.0);
int mod = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    ll moves = 0, prev = -1;

    for (int i=0; i<n; i++) {
        int t;
        cin >> t;

        if (prev > t) {
            moves += prev - t;
        } else
        prev = t;
    }

    cout << moves;
}
