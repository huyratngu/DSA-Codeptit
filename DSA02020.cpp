#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
long long res;
int n;
void solve(int i, long long x, long long y) {
    if(y > n) return;
    if(y == n) res = min(res, x);
    for(int j = 1;; j++) {
        if(x*A[i] > res) break;
        x *= A[i];
        solve(i + 1, x, y * (j+1));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        res = 1e18;
        solve(0, 1, 1);
        cout << res << "\n";
    }
}