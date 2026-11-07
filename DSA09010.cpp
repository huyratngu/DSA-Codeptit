#include <bits/stdc++.h>
using namespace std;
void dfs(vector<bool>& visited, int i, vector<vector<int>>& nums) {
    visited[i] = true;
    for (int x : nums[i]) {
        if (!visited[x]) dfs(visited, x, nums);
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
        vector<bool> visited(V + 1, false);
        vector<vector<int>> adj(V + 1);
        vector<vector<int>> revadj(V + 1);
        vector<int> res;
        for (int i = 0; i < E; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            revadj[y].push_back(x);
        }
        dfs(visited, 1, adj);
        int first = count(visited.begin() + 1, visited.end(), true);
        fill(visited.begin(), visited.end(), false);
        dfs(visited, 1, revadj);
        int second = count(visited.begin() + 1, visited.end(), true);
        bool isConnectedStrongly = (first == V && second == V);
        if (isConnectedStrongly) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}