#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int m, n, p;
        cin >> m >> n >> p;
        string x, y , z;
        cin >> x >> y >> z;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(p + 1, 0)));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= p; k++) {
                    if(x[i - 1] == y[j - 1] && y[j - 1] == z[k - 1]) dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    else {
                        dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]}); 
                    }
                }
            }
        }
        cout << dp[m][n][p] << "\n";
    }
    return 0;
}