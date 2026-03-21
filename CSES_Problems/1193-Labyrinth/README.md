# Labyrinth (ID: 1193)

**Problem Link:** [https://cses.fi/problemset/task/1193/](https://cses.fi/problemset/task/1193/)

## Problem Description

You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.

## Solution

```cpp
#include <bits/stdc++.h>

using namespace std;

using ii=pair<int, int>;

int n, m;
ii st, en;
vector<string> graph;
vector<vector<int>> vis;
vector<vector<vector<int>>> parent;
bool pathExist;

// int dx[] = {1, 0, -1, 0};
// int dy[] = {0, -1, 0, 1};
// char dir[] = {'R', 'U', 'L', 'D'};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char dir[] = {'R', 'D', 'L', 'U'};
int ln;

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == 0
    && graph[i][j] != '#';
}

void bfs () {
    queue<ii> q;
    q.push(st);
    vis[st.first][st.second] = 1;
    ln = 0;

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            ii curr = q.front();
            q.pop();

            if (curr == en) {
                pathExist = true;
                return;
            }

            for (int k=0; k<4; k++) {
                int x = curr.first + dx[k];
                int y = curr.second + dy[k];

                if (valid(x, y)) {
                    q.push({x, y});
                    vis[x][y] = 1;
                    parent[x][y][0] = curr.first;
                    parent[x][y][1] = curr.second;
                    parent[x][y][2] = k;
                }
            }

        }
        ln++;
    }
}


signed main() {

    cin >> n >> m;
    graph.resize(n);
    vis.assign(n, vector<int>(m, 0));
    parent.assign(n, vector<vector<int>>(m, vector<int>(3, 0)));
    pathExist = false;

    for (int i=0; i<n; i++) {
        cin >> graph[i];

        for (int j=0; j<m; j++) {
            if (graph[i][j] == 'A') {
                st = {i, j};
            } else if (graph[i][j] == 'B') {
                en = {i, j};
            }
        }
    }

    bfs();
    if (pathExist) {
        cout << "YES" << '\n';
        cout << ln << '\n';

        ii tmp = en;
        string direction = "";
        while (tmp != st) {
            direction += dir[parent[tmp.first][tmp.second][2]];
            ii temp = { parent[tmp.first][tmp.second][0],
            parent[tmp.first][tmp.second][1]};

            tmp = temp;
        }

        reverse(direction.begin(), direction.end());
        cout << direction << '\n';

    } else {
        cout << "NO" << '\n';
    }

}
```
