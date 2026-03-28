# Counting Rooms (ID: 1192)

**Problem Link:** [https://cses.fi/problemset/task/1192/](https://cses.fi/problemset/task/1192/)

## Problem Description

You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> graph;

void dfs(int i, int j) {

    if (i < 0 || i >= n || j < 0 || j >= m || graph[i][j] == '#') {
        return;
    }

    graph[i][j] = '#';
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    graph.resize(n);

    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        graph[i] = s;
    }

    long long cnt = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (graph[i][j] == '.') {
                dfs(i, j);
                cnt += 1;
            }
        }
    }


    cout << cnt << "\n";
}
```
