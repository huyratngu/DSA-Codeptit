#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> nums;
int n, k;
vector<int> path;
vector<vector<int>> res;
void solve(int start) {
    if((int)path.size() == k) {
        res.push_back(path);
        return;
    }
    for(int i = start; i < n; i++) {
        path.push_back(nums[i]);
        solve(i + 1);
        path.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        nums.clear();
        path.clear();
        res.clear();
        nums.resize(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        sort(nums.begin(), nums.end());
        solve(0);
        sort(res.begin(), res.end());
        for(auto v : res) {
            for(size_t i = 0; i < v.size(); i++) {
                if(i) cout << " ";
                cout << v[i];
            }
            cout << "\n";
        }
    }
    return 0;
}