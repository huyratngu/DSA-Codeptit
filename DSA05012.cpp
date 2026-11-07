#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;
int M = 1005;
vector<vector<int>> dp(M, vector<int>(M));
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < M; i++) {
        dp[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        cout << dp[n][k] << "\n";
    }
    return 0;
}