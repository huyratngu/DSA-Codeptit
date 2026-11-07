#include <bits/stdc++.h>
using namespace std;
int ok;
void solve() {
    string s;
    cin >> s;
    int n = s.length() - 1;
    int i = n;
    while(i >= 0 && s[i] != '0') {
        s[i] = '0';
        i--;
    }
    if(i >= 0) {
        s[i] = '1';
    }
    cout << s << endl;
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}