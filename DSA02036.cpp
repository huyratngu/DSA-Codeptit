#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(vector<int> &nums, int n, vector<vector<int>> &res, vector<int> &path, int start, int sum) {
    if(!path.empty() && sum % 2 == 1) {
        res.push_back(path);
    }
    for(int i = start; i < n; i++) {
        path.push_back(nums[i]);
        solve(nums, n, res, path, i + 1, sum + nums[i]);
        path.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> res;
        vector<int> path;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        sort(nums.begin(), nums.end(), greater<int>());
        solve(nums, n, res, path, 0, 0);
        sort(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++) {
            for(int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}