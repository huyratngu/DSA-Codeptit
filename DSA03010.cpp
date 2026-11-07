#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i = 0; i < n; i++) {
            long long value;
            cin >> value;
            pq.push(value);
        }
        long long total = 0;
        while(pq.size() >= 2) {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long s = a + b;
            total += s;
            pq.push(s);
        }
        cout << total << "\n";
    }
}