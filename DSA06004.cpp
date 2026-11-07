#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> uni;
        vector<int> inter;
        set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(uni));
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(inter));
        for(int x : uni) cout << x << " ";
        cout << "\n";
        for(int x : inter) cout << x << " ";
        cout << "\n";
    }
    return 0;
}