#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i  = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j],arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
        cout << "Buoc " << i + 1 << ": ";
        for (auto x : arr) cout << x << " ";
        cout << "\n";
    }
return 0;
}