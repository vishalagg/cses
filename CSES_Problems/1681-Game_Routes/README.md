# Game Routes (ID: 1681)

**Problem Link:** [https://cses.fi/problemset/task/1681/](https://cses.fi/problemset/task/1681/)

## Problem Description

A game has n levels, connected by m teleporters, and your task is to get from level 1 to level n. The game has been designed so that there are no directed cycles in the underlying graph. In how many ways can you complete the game?

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

using state=pair<long long, int>;

int n, m;
vector<vector<int>> graph;
vector<int> visited;
vector<int> topo;

const int mod = 1e9 + 7;

void dfs(int node) {
    visited[node] = 1;

    for (int v: graph[node]) {
        if (visited[v] == 0) {
            dfs(v);
        }
    }
    topo.push_back(node);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    graph.resize(n + 1);
    visited.resize(n + 1, 0);

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
    }

    dfs(1);

    reverse(topo.begin(), topo.end());

    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    for (int t: topo) {
        if (t == 0) continue;
        for (int v: graph[t]) {
            dp[v] = (dp[v] + dp[t]) % mod;
        }
    }

    cout << dp[n];
}
```
