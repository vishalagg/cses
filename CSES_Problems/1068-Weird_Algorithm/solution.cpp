// CSES Problem 1068: Weird Algorithm
// Link: https://cses.fi/problemset/task/1068/
// Description: Consider an algorithm that takes as input a positive integer n. If n is even, th...

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
