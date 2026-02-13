// CSES Problem 1068: Weird Algorithm
// Link: https://cses.fi/problemset/task/1068/
// Description: Consider an algorithm that takes as input a positive integer n. If n is even, th...

// Weird Algorithm
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif
using ll = long long;
long double PI = acos(-1.0);
int mod = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;

    cout << n << " ";
    while (n != 1) {
        if (n & 1) {
            n = 3 * n + 1;
        } else {
            n /= 2;
        }
        cout << n << " ";
    }
}

signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "w", stderr);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _t = 1;
    // cin >> _t;
    while (_t--) {
        try {
            solve();
        } catch (const exception &e) {
            cerr << "-------------------------------" << endl;
            cerr << "Error -> " << e.what() << endl;
            cerr << "-------------------------------" << endl;
        }
    }
    return 0;
}
