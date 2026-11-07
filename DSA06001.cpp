#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        int left = 0;
        int right = n - 1;
        vector<int> res;
        while(left <= right) {
            if(left == right) {
                res.push_back(arr[right]);
                break;
            }
            res.push_back(arr[right]);
            res.push_back(arr[left]);
            left++;
            right--;
        }
        for(auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}