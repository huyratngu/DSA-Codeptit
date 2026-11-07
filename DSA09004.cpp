#include <bits/stdc++.h>
using namespace std;
int m;
void dfs(int n, vector<int> &res, vector<vector<int>> &graph, vector<bool> &visited) {
    visited[n] = true;
    res.push_back(n);
    for (int i = 0; i < graph[n].size(); i++) {
        int next = graph[n][i];
        if (!visited[next]) dfs(next, res, graph, visited);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n ,p;
        cin >> m >> n >> p;
        vector<vector<int>> graph(m + 1);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x;
            cin >> y;
            graph[y].push_back(x);
            graph[x].push_back(y);
        }
        vector<bool> visited(m + 1, false);
        vector<int> res;
        dfs(p, res, graph, visited);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}