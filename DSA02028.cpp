#include <iostream>
#include <vector>
using namespace std;
int counting(vector<int> &numbers, int k, int n, int target, vector<int> temp, int start, int group) {
    int count = 0;
    if(k > n) {
        cout << 0 << "\n";
        return 0;
    }
    for(int i = start; i < n; i++) {
        temp.push_back(numbers[i]);
        int sum = 0;
        for(int j = 0; j < temp.size(); j++) sum += temp[j];
        if(sum == target) {
            if(group + 1 == k) {
                if(i == n - 1) count++;
            } else {
                vector<int> newTemp;
                count += counting(numbers, k, n, target, newTemp, i + 1, group + 1);
            }
        }
    }
    return count;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int target = 0;
    for(int i = 0; i < n; i++) target += nums[i];
    if(target % k != 0) {
        cout << 0 << "\n";
        return 0;
    }
    target = target / k;
    vector<int> temp;
    cout << counting(nums, k, n, target, temp, 0, 0) << "\n";
    return 0;
}