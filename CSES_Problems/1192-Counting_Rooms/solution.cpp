// CSES Problem 1192: Counting Rooms
// Link: https://cses.fi/problemset/task/1192/
// Description: You are given a map of a building, and your task is to count the number of its r...

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> graph;

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && graph[i][j] == '.';
}

void dfs(int i, int j) {
    graph[i][j] = '#';

    if (valid(i + 1, j)) dfs(i + 1, j);
    if (valid(i - 1, j)) dfs(i - 1, j);
    if (valid(i, j + 1)) dfs(i, j + 1);
    if (valid(i, j - 1)) dfs(i, j - 1);
}

signed main() {

    cin >> n >> m;
    graph.resize(n);

    for (int i=0; i<n; i++) {
        cin >> graph[i];
    }

    int cnt = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (graph[i][j] == '.') {
                dfs(i, j);
                cnt++;
            }
        }
    }


    cout << cnt;
}
