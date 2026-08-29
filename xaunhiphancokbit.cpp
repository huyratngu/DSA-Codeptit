#include <iostream>
using namespace std;
int n, k, a[100], ok;
void initialize() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        a[i] = 0;
    }
}
void gen() {
    int i = n;
    while(i >= 0 && a[i] != 0) {
        a[i] = 0;
        i--;
    }
    if(i > 0) {
        a[i] = 1;
    }
    else {
        ok = 0;
    }
}
bool check_k() {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 1) {
            cnt++;
        }
    }
    return cnt == k;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        initialize();
        ok = 1;
        while(ok) {
            if(check_k()) {
                for(int i = 1; i <= n; i++) {
                    cout << a[i];
                }
                cout << endl;
            }
            gen();
        }
    }
    return 0;
}
