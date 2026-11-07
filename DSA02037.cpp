#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> nums;
vector<int> path;
vector<vector<int>> res;
bool isPrime(int n) {
    if (n < 2) return false;
    for(int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
void solve(int start,int sum) {
    if(!path.empty() && isPrime(sum)) res.push_back(path);
    for(int i = start; i < n; i++) {
        path.push_back(nums[i]);
        solve(i + 1, sum + nums[i]);
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
        nums.resize(n);
        path.clear();
        res.clear();
        for(int i = 0; i < n; i++) cin >> nums[i];
        sort(nums.begin(), nums.end(), greater<int>());
        solve(0, 0);
        sort(res.begin(), res.end());
        for(auto x : res) {
            for(size_t i = 0; i < x.size(); i++) {
                if(i) cout << " ";
                cout << x[i];
            }
            cout << "\n";
        }
    }
    return 0;
}