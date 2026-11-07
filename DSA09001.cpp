#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> graph(V + 1);
        for(int i = 0; i < E; i++) {
            int u;
            int v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i = 1; i <= V; i++) {
            sort(graph[i].begin(), graph[i].end());
            cout << i << ":";
            for(int x : graph[i]) cout << " " << x;
            cout << "\n";
        }
    }
    return 0;
}