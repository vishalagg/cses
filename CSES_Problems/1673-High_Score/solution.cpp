// CSES Problem 1673: High Score
// Link: https://cses.fi/problemset/task/1673/
// Description: You play a game consisting of n rooms and m tunnels. Your initial score is 0, an...

#include <bits/stdc++.h>
using namespace std;

#define ll long long

using iii=pair<int, pair<int, ll>>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;

    cin >> n >> m;

    vector<iii> edges;
    vector<vector<int>> rev(n+1);

    for (int i=0; i<m; i++) {
        int a, b , c;
        cin >> a >> b >> c;
        edges.push_back({a, {b, -c}});
        rev[b].push_back(a);
    }

    vector<bool> canReachN;
    canReachN.resize(n + 1, false);
    queue<int> q;
    q.push(n);
    canReachN[n] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : rev[u]) {
            if (!canReachN[v]) {
                canReachN[v] = true; q.push(v);

            }

        }
    }

    vector<ll> dist;
    dist.resize(n + 1, 1e18);
    dist[1] = 0;

    for (int i=0; i<n-1; i++) {
        for (int j=0; j<m; j++) {
            int u = edges[j].first;
            int v = edges[j].second.first;
            ll w = edges[j].second.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    bool neg = false;

    for (int j=0; j<m; j++) {
        int u = edges[j].first;
        int v = edges[j].second.first;
        ll w = edges[j].second.second;

        if (dist[v] != 1e18 && dist[u] != 1e18 && canReachN[v] && dist[v] > dist[u] + w) {
            neg = true;
            break;
        }
    }

    if (neg) {
        cout << -1 << "\n";
    } else {
        cout << -dist[n] << "\n";
    }
}
