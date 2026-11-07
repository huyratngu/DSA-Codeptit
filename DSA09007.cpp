#include <bits/stdc++.h>
using namespace std;
bool bfs(vector<int> &res, vector<vector<int>> &graph, int start, int end, vector<bool> &visited, vector<int> &parent) {
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == end) return true;
        for (int x : graph[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                parent[x] = curr;
                q.push(x);
            }
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int V, E, S, F;
        cin >> V >> E >> S >> F;
        vector<int> res;
        vector<vector<int>> graph(V + 1);
        vector<bool> visited(V + 1, false);
        vector<int> parent(V + 1, -1);
        for (int i = 0; i < E; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        bool right = bfs(res, graph, S, F, visited, parent);
        if (right) {
            int curr = F;
            while (curr != -1) {
                res.push_back(curr);
                curr = parent[curr];
            }
            reverse(res.begin(), res.end());
            for (int x : res) cout << x << " ";
            cout << "\n";
        }
        else cout << -1 << "\n";
    }
    return 0;
}