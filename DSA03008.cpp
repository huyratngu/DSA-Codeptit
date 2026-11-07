#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i].first;
        for(int j = 0; j < n; j++) cin >> nums[j].second;
        sort(nums.begin(), nums.end(), cmp);
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i].first >= nums[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1); 
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < dp.size(); i++) ans = max(ans, dp[i]);
        cout << ans << "\n";
    }
    return 0;
}