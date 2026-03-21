// CSES Problem 1671: Shortest Routes I
// Link: https://cses.fi/problemset/task/1671/
// Description: There are n cities and m flight connections between them. Your task is to determ...

#include <bits/stdc++.h>

using namespace std;

using ii=pair<long long, long long>;
int n, m;
vector<vector<ii>> graph;
vector<long long> dist;

void bfs() {

    vector<int> vis;

    priority_queue<ii> q;
    dist.resize(n + 1, 1e18);
    vis.resize(n + 1, 0);

    q.push({0, 1});
    dist[1] = 0;

    while (!q.empty()) {
        ii curr = q.top();
        q.pop();
        long long cdist = -curr.first;
        long long cnode = curr.second;

        if (vis[cnode] == 1) continue;
        vis[cnode] = 1;

        for (ii v: graph[cnode]) {

            if (dist[v.first] > v.second + cdist) {
                dist[v.first] = v.second + cdist;
                q.push({-dist[v.first], v.first});
            }
        }
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    graph.resize(n + 1);
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    bfs();

    for (int i=1; i<=n ;i++) {
        cout << dist[i] << " ";
    }
}
