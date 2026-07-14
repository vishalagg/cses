// CSES Problem 3426: Sliding Window Xor
// Link: https://cses.fi/problemset/task/3426/
// Description: You are given an array of n integers. Your task is to calculate the bitwise xor ...

#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, k;
    long long x, a, b, c;

    cin >> n >> k >> x >> a >> b >> c;

    long long i = 0, prev = x, xr = 0, sxr = 0 ;
    vector<long long> arr(k);

    for (int j = 0; j < n; j++) {
        long long curr;
        if (j == 0) {
            curr = x;
        } else {
            curr = (((prev * a) % c ) + b) % c;
        }

        arr[j % k] = curr;
        xr = xr ^ curr;

        if (j >= k - 1) {
            sxr = sxr ^ xr;
            xr = xr ^ arr[i % k];
            i++;
        }

        prev = curr;
    }

    cout << sxr;
}
