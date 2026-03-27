// CSES Problem 1202: Investigation
// Link: https://cses.fi/problemset/task/1202/
// Description: You are going to travel from Syrjälä to Lehmälä by plane. You would like to find...

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int n, m;
vector<vector<pair<int, int>>> graph;
vector<long long> dist;
vector<long long> num;
vector<int> minF;
vector<int> maxF;

void dijkastra() {
    priority_queue<pair<long long, int>> q;
    q.push({0, 1});
    dist[1] = 0;
    num[1] = 1;
    minF[1] = 0;
    maxF[1] = 0;

    while (!q.empty()) {
        auto [d, node] = q.top();
        q.pop();
        d = -d;
        if (d > dist[node]) continue;

        for (auto nbr: graph[node]) {
            long long vd = nbr.second;
            int v = nbr.first;

            if (dist[v] > d + vd) {
                dist[v] = d + vd;
                q.push({-dist[v], v});
                num[v] = num[node];
                minF[v] = minF[node] + 1;
                maxF[v] = maxF[node] + 1;
            } else if (dist[v] == (d + vd)) {
                num[v] = (num[v] + num[node]) % mod;
                minF[v] = min(minF[v], minF[node] + 1);
                maxF[v] = max(maxF[v], maxF[node] + 1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    graph.resize(n + 1);
    dist.resize(n+1, 1e18);
    num.resize(n + 1, 0);
    minF.resize(n + 1, 1e9);
    maxF.resize(n + 1, 0);

    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
    }

    dijkastra();
    cout << dist[n] << ' ';
    cout << num[n] << ' ';
    cout << minF[n] << ' ';
    cout << maxF[n] << ' ';
}
