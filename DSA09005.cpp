#include <bits/stdc++.h>
using namespace std;
vector<int> res;
void bfs(vector<vector<int>> &graph, queue<int> &q, int start, vector<bool> &visited, vector<int>  &res) {
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        for (int next : graph[curr]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int V, E, F;
        cin >> V >> E >> F;
        vector<vector<int>> graph(V + 1);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        queue<int> q;
        vector<bool> visited(V + 1, false);
        res.clear();
        bfs(graph, q, F, visited,res);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}