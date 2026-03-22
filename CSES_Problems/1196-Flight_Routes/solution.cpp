// CSES Problem 1196: Flight Routes
// Link: https://cses.fi/problemset/task/1196/
// Description: Your task is to find the k shortest flight routes from Syrjälä to Metsälä. A rou...

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m, k;
vector<vector<pair<int, ll>>> graph;

vector<priority_queue<ll>> dist;

void dijkastra() {
    dist.resize(n + 1);
    dist[1].push(0);

    priority_queue<pair<ll, int>> q;
    q.push({0, 1});


    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        d = -d;

        if (dist[u].size() == k && dist[u].top() < d)   continue;

        for (auto nbr: graph[u]) {
            int v = nbr.first;
            ll w = nbr.second;

            if (dist[v].size() < k) {
                dist[v].push(d + w);
                q.push({-(d + w), v});
            } else if (dist[v].top() > d + w) {
                dist[v].pop();
                dist[v].push(d + w);
                q.push({-(d + w), v});
            }
        }
    }

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    graph.resize(n + 1);

    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
    }

    dijkastra();

    vector<ll> ans;

    while (!dist[n].empty()) {
        ans.push_back(dist[n].top());
        dist[n].pop();
    }

    reverse(ans.begin(), ans.end());

    for (ll a: ans) {
        cout << a << " ";
    }
}
