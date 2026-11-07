#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        int neg = -1e9;
        vector<int> dp(k, neg);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            vector<int> temp = dp;
            for(int j = 0; j < k; j++) {
                int r = (j + nums[i]) % k;
                temp[r] = max(temp[r], dp[j] + 1);
            }
            dp = temp;
        }
        cout << dp[0] << "\n";
    }
    return 0;
}