// CSES Problem 1678: Round Trip II
// Link: https://cses.fi/problemset/task/1678/
// Description: Byteland has n cities and m flight connections. Your task is to design a round t...

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> visited;
vector<int> par;
bool cycle;
vector<int> path;

void dfs(int node, int parent) {
    visited[node] = 2;
    par[node] = parent;

    for (int v: graph[node]) {
        if (visited[v] == 1)
        dfs(v, node);
        else if (visited[v] == 2) {
            if (!cycle) {
                cycle = true;
                path.push_back(v);
                int tmp = node;
                while (tmp != v) {
                    path.push_back(tmp);
                    tmp = par[tmp];
                }
                path.push_back(v);
            }
        }
    }

    visited[node] = 3;
}

int main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    graph.resize(n + 1);
    visited.resize(n + 1, 1);
    par.resize(n + 1, 0);

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    cycle = false;

    for (int i=1; i<=n; i++) {
        if (visited[i] == 1) {
            dfs(i, par[i]);
            if (cycle) {
                cout << path.size() << '\n';
                reverse(path.begin(), path.end());
                for (int p: path) {
                    cout << p << " ";
                }

                break;
            }
        }
    }

    if (!cycle) {
        cout << "IMPOSSIBLE";
    }

}
