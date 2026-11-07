#include <bits/stdc++.h>
using namespace std;
void solve(int n) {
    queue<string> q;
    q.push("1");
    for (int i = 0; i < n; i++) {
        if (q.empty()) break;
        string s = q.front();
        q.pop();
        cout << s << " ";
        q.push(s + "0");
        q.push(s + "1");
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
        cout << "\n";
    }
    return 0;
}