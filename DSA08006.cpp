#include <bits/stdc++.h>
using namespace std;
long long solve(int &n) {
    queue<string> q;
    q.push("9");
    if (9 % n == 0) return 9;
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        long long num = stoll(s);
        if (num % n == 0) return num;
        q.push(s + "0");
        q.push(s + "9");
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << "\n";
    }
}