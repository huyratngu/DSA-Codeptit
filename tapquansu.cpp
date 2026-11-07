#include <bits/stdc++.h>
using namespace std;
int n, k, ok;
int x[100];
int res[100];
void initialize() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> x[i];
        res[i] = x[i];
    }
}
void next_combination() {
    int i = k;
    while(i > 0 && x[i] == n - k + i) {
        i--;
    }
    if(i > 0) {
        x[i] = x[i] + 1;
        for (int j = i + 1; j <= k; j++) {
            x[j] = x[i] + j - i;
        }
    }
    else {
        ok = 0;
    }
}
void check_if_same() {
if(ok == 0) {
        cout << k << endl;
    }
else {
    int cnt = 0;
    for(int i = 1; i <= k; i++) {
        bool found = false;
        for(int j = 1; j <= k; j++) {
            if(res[i] == x[j]){
                found = true;
                break;
            }
        }
        if(!found) {
            cnt++;
        }
    }
    cout << cnt << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        initialize();
        ok = 1;
        next_combination();
        check_if_same();
    }
}
