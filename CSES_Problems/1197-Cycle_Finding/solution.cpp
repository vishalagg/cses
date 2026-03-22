// CSES Problem 1197: Cycle Finding
// Link: https://cses.fi/problemset/task/1197/
// Description: You are given a directed graph, and your task is to find out if it contains a ne...

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> edges;
    for (int i=0; i<m; i++) {
        int a, b, c;

        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    vector<ll> dist(n + 1, 1e18);
    vector<ll> parent(n + 1, -1);
    dist[1] = 0;

    int x = -1;

    for (int i=1; i<=n; i++) {
        x = -1;
        for (int j=0; j<m; j++) {
            ll u = edges[j][0];
            ll v = edges[j][1];
            ll w = edges[j][2];
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) {
        cout << "NO";
    } else {
        cout << "YES\n";

        for (int i=0; i<n; i++) {
            x = parent[x];
        }

        vector<int> cycle;
        int cur = x;

        do {
            cycle.push_back(cur);
            cur = parent[cur];
        } while (cur != x);

        cycle.push_back(x);
        reverse(cycle.begin(), cycle.end());

        for (int v : cycle) {
            cout << v << " ";
        }
    }
}
