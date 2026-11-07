#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    for(int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for(int j = i + 1; j < n; j++) {
            if(nums[j] < nums[minIdx]) minIdx = j; 
        }
        swap(nums[i], nums[minIdx]);
        cout << "Buoc " << i + 1 << ": ";
        for(int z = 0; z < n; z++) cout << nums[z] << " ";
        cout << "\n";
    }
    return 0;
}