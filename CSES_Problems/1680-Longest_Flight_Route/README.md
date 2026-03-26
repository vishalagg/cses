# Longest Flight Route (ID: 1680)

**Problem Link:** [https://cses.fi/problemset/task/1680/](https://cses.fi/problemset/task/1680/)

## Problem Description

Uolevi has won a contest, and the prize is a free flight trip that can consist of one or more flights through cities. Of course, Uolevi wants to choose a trip that has as many cities as possible.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

using state=pair<long long, int>;

int n, m;
vector<vector<int>> graph;
vector<int> visited;
vector<int> topo;

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

    vector<int> dp(n + 1, -1e9);
    vector<int> parent(n + 1, -1);

    dp[1] = 1;

    for (int t: topo) {
        if (dp[t] < 0) continue;
        for (int v: graph[t]) {
            if (dp[v] < dp[t] + 1) {
                dp[v] = dp[t] + 1;
                parent[v] = t;
            }
        }
    }

    if (dp[n] < 0) {
        cout << "IMPOSSIBLE";
    } else {
        cout << dp[n] << '\n';

        int t = n;
        vector<int> path;
        while (t != -1) {
            path.push_back(t);
            t = parent[t];
        }

        reverse(path.begin(), path.end());
        for (int x: path) {
            cout << x << " ";
        }
    }
}
```
