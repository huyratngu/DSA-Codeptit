#include <iostream>
using namespace std;
int n, ok, a[100];
void initialize() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        a[i] = 0;
    }
}
void magraygen() {
    int i = n;
    while(i > 0 && a[i] != 0) {
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
int main() {
    int t;
    cin >> t;
    while(t--) {
        initialize();
        ok = 1;
        while(ok) {
            cout << a[1];
            for(int i = 2; i <= n; i++) {
                cout << (a[i-1] ^ a[i]);
            }
            cout << " ";
            magraygen();
        }
        cout << endl;
    }
    return 0;
}