#include <bits/stdc++.h>
using namespace std;
int n, ok, a[100];
void initialize() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i] = n - i + 1;
    }
}
void next_permutation() {
    int j = n - 1;
    while (j > 0 && a[j] < a[j + 1]) {
        j--;
    }
    if (j > 0) {
        int k = n;
        while(a[j] < a[k]) {
            k--;
        }
        int t = a[j];
        a[j] = a[k];
        a[k] = t;
        int r = j + 1;
        int s = n;
        while (r <= s) {
            swap(a[r], a[s]);
            r++;
            s--;
        }
    }
    else {
        ok = 0;
    }
}
int main () {
    int t;
    cin >> t;
    while(t--) {
        initialize();
        ok = 1;
        while(ok) {
            for (int i = 1; i <= n; i++) {
                cout << a[i];
            }
            cout << " ";
            next_permutation();
        }
        cout << endl;
    }
return 0;
}