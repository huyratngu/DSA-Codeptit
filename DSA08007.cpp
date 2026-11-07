#include <bits/stdc++.h>
using namespace std;
vector<long long> bdn;
void gen() {
    queue<long long> q;
    q.push(1);
    long long cnt = 0;
    while (!q.empty()) {
        long long front = q.front();
        q.pop();
        bdn.push_back(front);
        if (front <= (LONG_LONG_MAX - 1)/10) {
            q.push(front * 10 + 0);
            q.push(front * 10 + 1);
            cnt++;
        }
    }
    sort(bdn.begin(), bdn.end());
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    gen();
    while (t--) {
        long long n;
        cin >> n;
        cout << upper_bound(bdn.begin(), bdn.end(), n) - bdn.begin() << "\n";
    }
    return 0;
}