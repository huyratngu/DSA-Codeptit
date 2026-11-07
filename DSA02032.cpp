#include <iostream>
#include <vector>
using namespace std;
void solve(int start, int remaining, vector<int> &nums, vector<vector<int>> &results, vector<int> path) {
    if(remaining < 0) return;
    if(remaining == 0) {
        results.push_back(path);
        return;
    }
    for(int i = start; i < nums.size(); i++) {
        path.push_back(nums[i]);
        solve(i, remaining - nums[i], nums, results, path);
        path.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> nums(n);
        vector<vector<int>> results;
        vector<int> path;
        for(int i = 0; i < n; i++) cin >> nums[i];
        solve(0, x, nums, results, path);
        if(results.empty()) cout << -1 << "\n";
        else {
            cout << results.size() << " "; 
            for(int i = 0; i < (int)results.size(); i++) {
                cout << "{";
                for(int j = 0; j < (int)results[i].size(); j++) {
                    cout << results[i][j];
                    if(j != results[i].size() - 1) cout << " ";
                }
                cout << "}";
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}