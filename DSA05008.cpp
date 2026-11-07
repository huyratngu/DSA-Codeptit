#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        vector<bool> dp(s + 1, false);
        dp[0] = true;
        for(int i = 0; i < n; i++) {
            for(int j = s; j >= nums[i]; j--) {
                if(dp[j - nums[i]]) {
                    dp[j] = true;
                }
            }
        }
        cout << (dp[s] ? "YES" : "NO") << "\n";
    }
    return 0;
}