// CSES Problem 1071: Number Spiral
// Link: https://cses.fi/problemset/task/1071/
// Description: A number spiral is an infinite grid whose upper-left square has number 1. Here a...

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;
const int MAX = 2 * 100100;
long double PI = acos(-1.0);
int mod = 1e9 + 7;

void sol();

signed main() {
    int t = 1;
    cin >> t;

    while (t--) {
        sol();
    }
}

void sol() {
    ll x, y;
    cin >> x >> y;

    int layer = max(x, y);
    if ((layer & 1) == 1) {
        swap(x, y);
    }
    if(layer == y) {
        cout <<  (ll)(layer - 1) * (layer - 1) + 1 + x - 1 << endl;
    } else {
        cout << (ll)layer * layer - (y - 1) << endl;
    }
}
