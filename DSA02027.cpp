#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int n;
        cin >> n;
        vector<vector<int>> values(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> values[i][j];
            }
        }
        const int biggest = 1e9;
        vector<vector<int>> dp(1 << n, vector<int>(n, biggest));
        for(int i = 0; i < n; i++) dp[1 << i][0] = 0;
        for(int mask = 0; mask <= (1 << n); mask++) {
            for(int i = 0; i < n; i++) {
                if(!(mask & 1 << i)) continue;
                if(dp[mask][i] == biggest) continue;
                for(int j = 0; j < n; j++) {
                    if(mask & 1 << j) continue;
                    int newmask = mask | (1 << j);
                    dp[newmask][j] = min(dp[newmask][j], dp[mask][i] + values[i][j]);
                }
            }
        }
        int full = (1 << n) - 1;
        int ans = biggest;
        for(int i = 0; i < n; i++) ans = min(ans, dp[full][i] + values[i][0]);
        cout << ans << "\n";
    return 0;
}