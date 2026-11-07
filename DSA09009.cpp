#include <bits/stdc++.h>
using namespace std;
void bfs(vector<bool> &visited, vector<vector<int>> &graph, int start) {
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int x : graph[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}
int main() {
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<bool> visited(1001, false);
        vector<vector<int>> graph(1000);
        for (int i = 0; i < E; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int cnt = 0;
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                bfs(visited, graph, i);
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}