// CSES Problem 1633: Dice Combinations
// Link: https://cses.fi/problemset/task/1633/
// Description: Your task is to count the number of ways to construct sum n by throwing a dice o...

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    long long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; dp[1] = 1;


    for(int i = 2; i <= n; i++) {
        for (int j=1; j<=6; j++) {
            if (i - j < 0) break;
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }

    cout << dp[n] % mod << "\n";
}
