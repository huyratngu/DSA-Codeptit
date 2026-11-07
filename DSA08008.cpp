#include <bits/stdc++.h>
using namespace std;
long long solve(long long n) {
    queue<long long> q;
    q.push(1);
    while (!q.empty()) {
        long long x = q.front();
        q.pop();
        if (x % n == 0) {
            return x;
        }
        q.push(x * 10);
        q.push(x * 10 + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}