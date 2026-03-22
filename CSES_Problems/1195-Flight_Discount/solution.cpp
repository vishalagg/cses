// CSES Problem 1195: Flight Discount
// Link: https://cses.fi/problemset/task/1195/
// Description: Your task is to find a minimum-price flight route from Syrjälä to Metsälä. You h...

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

int n, m;

vector<vector<pair<int,ll>>> graph;
vector<vector<ll>> dist;

using state = tuple<ll, int, int>; // {neg_dist, node, used}

void dijkstra() {
    dist.assign(n+1, vector<ll>(2, INF));

    priority_queue<state> pq; // max-heap

    dist[1][0] = 0;
    pq.push({-0, 1, 0});

    while (!pq.empty()) {
        auto [neg_d, u, used] = pq.top();
        pq.pop();

        ll d = -neg_d;

        if (d > dist[u][used]) continue;

        for (auto [v, w] : graph[u]) {

            // 1. Normal move
            if (dist[v][used] > d + w) {
                dist[v][used] = d + w;
                pq.push({-dist[v][used], v, used});
            }

            // 2. Use coupon
            if (used == 0) {
                ll newCost = d + (w / 2);
                if (dist[v][1] > newCost) {
                    dist[v][1] = newCost;
                    pq.push({-newCost, v, 1});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    graph.resize(n+1);

    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    dijkstra();

    cout << min(dist[n][0], dist[n][1]) << "\n";
}
