#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
vector<int> nums;
int n;
vector<int> path;
vector<vector<int>> res;
void solve(int start, int sum) {
    if(sum == n) {
        res.push_back(path);
        return;
    }
    if(sum > n) return;
    for(int i = start; i < n; i++) {
        path.push_back(nums[i]);
        solve(i, sum + nums[i]);
        path.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        nums.clear();
        path.clear();
        res.clear();
        nums.resize(n);
        for(int i = 0; i < n; i++) nums[i] = n - i;
        solve(0, 0);
        cout << res.size() << "\n";
        for(auto v : res) {
            cout << "(";
            for(size_t i = 0; i < v.size(); i++) {
                if(i) cout << " ";
                cout << v[i];
            }
            cout << ")";
            cout << " ";
        }
        cout << "\n";
    }
    return 0;
}