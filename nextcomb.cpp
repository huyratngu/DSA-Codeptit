#include <bits/stdc++.h>
using namespace std;
int a[100];
int n, k;
int ok;
void initialize() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
}
void solve() {
    int i = k;
    while(i > 0 && a[i] == n - k + i) {
        i--;
    }
    if(i > 0) {
        a[i] = a[i] + 1;
        for (int j = i + 1; j <= k; j++) {
            a[j] = a[i] + j - i;
        }
    }
    else {
        ok = 0;
    }
    if(ok == 0) {
        for(int j = 1; j <= k; j++) {
            a[j] = j;
    }
        ok = 1;
    }
    for(int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main () {
    int t;
    cin >> t;
    while(t--) {
        initialize();
        ok = 1;
        solve();
    }
}