#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> nums(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> nums[i][j];
            }
        }
        int full = 1 << n;
        vector<long long> dp(full, - 1);
        dp[0] = 0;
        for(int mask = 0; mask < full; mask++) {
            if(dp[mask] == -1) continue;
            int row = __builtin_popcount(mask);
            if(row == n) continue;
            for(int j = 0; j < n; j++) {
                if(!(mask & (1 << j))) {
                    int newMask = mask | (1 << j);
                    dp[newMask] = max(dp[newMask], dp[mask] + nums[row][j]);
                }
            }
        }
        cout << dp[full - 1] << "\n";
    }
    return 0;
}