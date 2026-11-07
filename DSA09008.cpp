#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &graph, vector<bool> &visited, int start) {
    stack<int> st;
    st.push(start);
    visited[start] = true;
    while (!st.empty()) {
        int curr = st.top();
        st.pop();
        for (int next : graph[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                st.push(next);
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
        int V, E;
        cin >> V >> E;
        vector<vector<int>> graph(1001);
        vector<bool> visited(1001, false);
        for (int i = 0; i < E; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int cnt = 0;
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                dfs(graph, visited, i);
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}