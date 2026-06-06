// CSES Problem 1079: Binomial Coefficients
// Link: https://cses.fi/problemset/task/1079/
// Description: Your task is to calculate n binomial coefficients modulo 10^9+7....

#include <bits/stdc++.h>
using namespace std;

long long powmod(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;

    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }

    return res;
}

long long inverse(int x, int mod) {
    return powmod(x, mod - 2, mod);
}

int main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = 1000001, mod = 1e9 + 7;
    long long fact[N];
    long inv[N];

    fact[0] = 1;
    fact[1] = 1;
    for (int i=2; i<N; i++) {
        fact[i] = (i * fact[i-1]) % mod;
    }

    inv[N-1] = inverse(fact[N-1], mod);

    for (int i=N-2; i>=0; i--) {
        inv[i] = (inv[i+1] * (i+1)) % mod;
    }

    int t;
    cin >> t;

    while (t--) {
        int n, r;
        cin >> n >> r;

        long long res = fact[n] % mod ;
        res = (res * inv[r]) % mod;
        res = (res * inv[n - r]) % mod;

        cout << res << "\n";
    }

}
