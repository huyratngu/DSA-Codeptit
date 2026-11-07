#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int> &res, vector<vector<int>> &graph, int start, vector<bool> &visited, int target) {
    visited[start] = true;
    res.push_back(start);
    if (start == target) return true;
    for (int i = 0; i < graph[start].size(); i++) {
        int curr = graph[start][i];
        if (!visited[curr]) {
            if (dfs(res, graph, curr, visited, target)) return true;
        }
    }
    res.pop_back();
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int V, E, U, X;
        cin >> V >> E >> U >> X;
        vector<vector<int>> graph(V + 1);
        vector<bool> visited(V + 1, false);
        vector<int> res;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if (dfs(res, graph, U, visited, X)) {
            for (auto x : res) cout << x << " ";
            cout << "\n";
        }
        else cout << -1 << "\n";
    }
    return 0;
}