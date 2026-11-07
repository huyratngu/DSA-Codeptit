#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        vector<int> dp(n);
        for(int i = 0; i < n; i++) {
            dp[i] = nums[i];
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + nums[i]);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
}