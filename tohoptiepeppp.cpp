#include <iostream>
#include <vector>
using namespace std;
int n, k, a[100], ok, res[100];
void initialize() {
    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        cin >> a[i];
        res[i] = a[i];
    }
}
void next_combination() {
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
}
void check() {
    if(ok == 0) {
        cout << k << endl;
    }
    else {
    int count = 0;
    for (int i = 1; i <= k; i++) {
        bool found = false;
        for(int j = 1; j <= k; j++) {
            if(res[i] == a[j]) {
                found = true;
                break;
            }
        }
        if(!found) {
            count++;
        }
    }
    cout << count << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        initialize();
        ok = 1;
        next_combination();
        check();
    }
    return 0;
}