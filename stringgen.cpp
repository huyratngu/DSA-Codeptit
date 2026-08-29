#include <bits/stdc++.h>
using namespace std;
int n, ok;
string s;
void initialize() {
    cin >> n;
    s = string(n, 'A');
}
void stringgen() {
    int i = n - 1;
    while (i >= 0 && s[i] == 'B') {
        s[i] = 'A';
        i--;
    }
    if (i >= 0) {
        s[i] = 'B';
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
            cout << s;
            cout << " ";
            stringgen();
        }
        cout << endl;
    }
}