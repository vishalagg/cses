// CSES Problem 1195: Flight Discount
// Link: https://cses.fi/problemset/task/1195/
// Description: Your task is to find a minimum-price flight route from Syrjälä to Metsälä. You h...

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
vector<vector<pair<int, ll>>> graph;

vector<vector<ll>> dist;
using state=tuple<ll, int, int>; // <dist, node, cupounUsed>

void dijkastra() {
    dist.resize(n + 1, vector<ll>(2, 1e18));
    dist[1][0] = 0;

    priority_queue<state> q;
    q.push({-0, 1, 0});
    vector<vector<int>> vis;
    vis.resize(n + 1, vector<int>(2, 0));

    while (!q.empty()) {

        auto [cdis, cnode, cused] = q.top();
        q.pop();
        cdis = -cdis;

        if (vis[cnode][cused])  continue;
        vis[cnode][cused] = 1;


        for (pair<int, ll> nbr: graph[cnode]) {
            int v = nbr.first;
            ll w = nbr.second;

            if (dist[v][cused] > cdis + w) {
                dist[v][cused] = cdis + w;
                q.push({-dist[v][cused], v, cused});
            }

            if (cused == 0) {
                ll new_w = w / 2;
                if (dist[v][1] > cdis + new_w) {
                    dist[v][1] = cdis + new_w;
                    q.push({-dist[v][1], v, 1});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    graph.resize(n + 1);
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
    }

    dijkastra();

    cout << min(dist[n][0], dist[n][1]) << "\n";

}
