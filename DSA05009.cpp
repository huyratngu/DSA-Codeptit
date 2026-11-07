#include <iostream>
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
        vector<int> nums(n);
        int sum = 0;
        for(int i = 0; i < n; i++)  {
            cin >> nums[i];
            sum += nums[i];
        }
        int target = 0;
        if(sum % 2 != 0) {
            cout << "NO\n";
            continue;
        }
        target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(int x : nums) {
            for(int j = target; j >= x; j--) {
                if(dp[j - x]) dp[j] = true;
            }
        }
        cout << (dp[target] ? "YES\n" : "NO\n");
    }
    return 0;
}