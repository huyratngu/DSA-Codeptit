#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        stable_sort(nums.begin(), nums.end(), [&](int a, int b) {
            return abs(x - a) < abs(x - b);
        });
        for (auto x : nums) cout << x << " ";
        cout << "\n";
    }
    return 0;
}