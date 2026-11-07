#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    do {
        for(int i = 0; i < n; i++) cout << nums[i] << " ";
        cout << "\n";
    } while(next_permutation(nums.begin(), nums.end()));
    return 0;
}