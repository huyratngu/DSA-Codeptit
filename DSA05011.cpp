#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;
long long dp[101][901];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int s = 1; s <= 9; s++) dp[1][s] = 1;
    for(int i = 2; i <= 100; i++) {
        for(int s = 0; s <= 900; s++) {
            for(int d = 0; d <= 9; d++) {
                if(s - d >= 0) dp[i][s] += dp[i - 1][s - d];
                dp[i][s] %= MOD;
            }
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(k > 9*n) {
            cout << 0 << "\n";
            continue;
        }
        else {
            cout << dp[n][k] << "\n";
        }
    }
    return 0;
}