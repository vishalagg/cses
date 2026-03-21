// CSES Problem 1668: Building Teams
// Link: https://cses.fi/problemset/task/1668/
// Description: There are n pupils in Uolevi's class, and m friendships between them. Your task ...

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> graph;

bool possible;
vector<int> colors;

void dfs(int node, int color) {
    colors[node] = color;

    for (int v: graph[node]) {
        if (colors[v] == 0) {
            dfs(v, 3-color);
        } else if (colors[v] == color) {
            possible = false;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    graph.resize(n + 1);
    colors.assign(n + 1, 0);
    possible = true;

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i=1; i<=n; i++) {
        if (colors[i] == 0) {
            dfs(i, 1);
            if (!possible) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        cout << colors[i] << " ";
    }
}
