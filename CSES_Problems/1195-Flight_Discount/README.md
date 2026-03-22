# Flight Discount (ID: 1195)

**Problem Link:** [https://cses.fi/problemset/task/1195/](https://cses.fi/problemset/task/1195/)

## Problem Description

Your task is to find a minimum-price flight route from Syrjälä to Metsälä. You have one discount coupon, using which you can halve the price of any single flight during the route. However, you can only use the coupon once.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;
vector<vector<pair<int, ll>>> graph;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    graph.resize(2 * n + 1);

    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[n + a].push_back({n + b, c});
        graph[a].push_back({n + b, c / 2});
    }

    vector<ll> dist(2 * n + 1, 1e18);
    priority_queue<pair<ll, int>> q;
    dist[1] = 0;
    q.push({-0, 1});

    vector<int> vis(2*n + 1, 0);

    while (!q.empty()) {
        auto [d, node] = q.top();
        q.pop();
        d = -d;

        if (vis[node]) continue;
        vis[node] = 1;

        for (auto [v, w]: graph[node]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                q.push({-dist[v], v});
            }
        }
    }

    cout << min(dist[n], dist[2*n]) << "\n";
}
```
