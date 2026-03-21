# Message Route (ID: 1667)

**Problem Link:** [https://cses.fi/problemset/task/1667/](https://cses.fi/problemset/task/1667/)

## Problem Description

Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.

## Solution

```cpp
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> vis;
vector<int> par;
bool canReach;
int ln;

void bfs() {
    queue<int> q;
    q.push(1);
    vis[1] = 1;


    while (!q.empty()) {
        int sz = q.size();

        while (sz--) {
            int curr = q.front();
            q.pop();
            if (curr == n) {
                canReach = true;
                return;
            }

            for (int v: graph[curr]) {
                if (vis[v] == 0) {
                    q.push(v);
                    vis[v] = 1;
                    par[v] = curr;
                }
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    graph.resize(n + 1);
    vis.assign(n + 1, 0);
    par.assign(n + 1, -1);

    canReach = false;

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs();

    if (canReach) {

        int tmp = n;
        vector<int> path;
        while (tmp != -1) {
            path.push_back(tmp);
            tmp = par[tmp];
        }

        reverse(path.begin(), path.end());
        cout << path.size() << '\n';
        for (int v: path) {
            cout << v << " ";
        }
    } else {
        cout << "IMPOSSIBLE";
    }
}
```
