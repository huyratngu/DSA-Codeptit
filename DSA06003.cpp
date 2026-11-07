#include <iostream>
#include <vector>
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
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            int minidx = i;
            for(int j = i + 1; j < n; j++) {
                if(arr[j] < arr[minidx]) {
                    minidx = j;
                }
            }
            if(minidx != i) {
                swap(arr[i], arr[minidx]);
                count++;
            }       
        }
        cout << count << "\n";
    }
    return 0;
}