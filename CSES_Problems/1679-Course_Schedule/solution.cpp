// CSES Problem 1679: Course Schedule
// Link: https://cses.fi/problemset/task/1679/
// Description: You have to complete n courses. There are m requirements of the form "course a h...

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> visited;
vector<int> par;
bool cycle;
vector<int> seq;

void dfs(int node, int parent) {
    visited[node] = 2;
    par[node] = parent;

    for (int v: graph[node]) {
        if (visited[v] == 1)
        dfs(v, node);
        else if (visited[v] == 2) {
            cycle = true;
        }
    }

    visited[node] = 3;
    seq.push_back(node);
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
                cout << "IMPOSSIBLE";
                break;
            }
        }
    }

    if (!cycle) {
        reverse(seq.begin(), seq.end());
        for (int s: seq) {
            cout << s << " ";
        }
    }

}
