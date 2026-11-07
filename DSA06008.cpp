#include <bits/stdc++.h>
using namespace std;
int powr(int x, int y) {
    int sum = 0;
    for (int i = 1; i < y; i++) {
        sum += x * x;
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> first(n);
        vector<int> sec(m);
        for (int &x : first) cin >> x;
        for (int &y : sec) cin >> y;
        vector<int> temp(n);
        vector<int> temp_2(m);
        for (int i = 0, j = 0; i < first.size() || j < m; i++, j++) {
            temp.push_back(powr(first[i], sec[j]));
            temp_2.push_back(powr(sec[j], first[i]));
        }
        int cnt = 0;
        for (int i = 0, j = 0; i < n || j < m; i++, j++) {
            if (temp[i] > temp_2[j]) cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}