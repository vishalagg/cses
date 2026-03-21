// CSES Problem 1669: Round Trip
// Link: https://cses.fi/problemset/task/1669/
// Description: Byteland has n cities and m roads between them. Your task is to design a round t...

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> graph;

bool possible;
vector<int> visited;
vector<int> parent;
vector<int> cycle;

void dfs(int node, int par) {
    visited[node] = 2;
    parent[node] = par;

    for (int v: graph[node]) {
        if (v == par) continue;
        if (visited[v] == 1) {
            dfs(v, node);
        } else if (visited[v] == 2) {
            if (cycle.size() == 0) {
                cycle.push_back(v);
                int tmp = node;
                while (tmp != v) {
                    cycle.push_back(tmp);
                    tmp = parent[tmp];
                }
                cycle.push_back(v);
            }
        }
    }

    visited[node] = 3;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    graph.resize(n + 1);
    visited.assign(n + 1, 1);
    parent.assign(n + 1, 0);

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i=1; i<=n; i++) {
        if (visited[i] == 1) {
            dfs(i, 0);
        }
    }

    if (cycle.size() == 0) {
        cout << "IMPOSSIBLE";
    } else {
        cout << cycle.size() << '\n';
        for (int v: cycle) {
            cout << v << " ";
        }
    }
}
