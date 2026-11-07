#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();
    vector<pair<int, int>> adj;
    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int u = i + 1;
        int v;
        while (ss >> v) {
            if (u < v) adj.push_back({u, v});
        }
    }
    sort(adj.begin(), adj.end());
    for (auto x : adj) cout << x.first << " " << x.second << "\n";
    return 0;
}