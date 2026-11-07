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
        vector<int> dp(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        dp[0] = nums[0];
        if(n > 1) {
            dp[1] = max(nums[0], nums[1]);
        }
        for(int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        cout << dp[n - 1] << "\n";
    }
    return 0;
}