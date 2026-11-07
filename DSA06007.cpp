#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int &x : arr) cin >> x;
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        int l = 0;
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != temp[i]) {
                l = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] != temp[i]) {
                r = i;
                break;
            }
        }
        cout << l + 1 << " " << r + 1 << "\n";
    }
    return 0;
}