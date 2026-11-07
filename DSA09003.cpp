#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V + 1);
        for (int i = 0; i < E; i++) {
            int x;
            int y;
            cin >> x >> y;
            graph[x].push_back(y);
        }
        for (int i = 1; i <= V; i++) {
            cout << i << ":";
            for (int x : graph[i]) cout << " " << x;
            cout << "\n";
        }
    }
    return 0;
}
