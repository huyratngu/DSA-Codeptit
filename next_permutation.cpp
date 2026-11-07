#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int ok;
void initialize(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }    
}
void Next_permutations() {
    int j = n - 1;
    while (j > 0 && a[j] > a[j+1]) {
        j--;
    }
    if(j > 0) {
        int k = n;
        while(a[j] > a[k]) {
            k--;
        }
        int t = a[j];
        a[j] = a[k];
        a[k] = t;
        int r = j + 1;
        int s = n;
        while (r <= s) {
            t = r;
            r = s;
            s = t;
            r++;
            s--;
        }
    }
    else {
        ok = 0;
    }
    if(ok == 0) {
        for (int i = 1; i <= n; i++) {
            a[i] = i;
        }
        ok = 1;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
    initialize();
    ok = 1;
    Next_permutations();
    }
}