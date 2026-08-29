#include <iostream>
using namespace std;
int ok;
string s;
void initialize() {
    cin >> s;
}
void binarygen() {
    int i = s.length() - 1;
    while(i >= 0 && s[i] == '0') {
        s[i] = '1';
        i--;
    }
    if(i >= 0) {
        s[i] = '0';
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
        binarygen();
        cout << s << endl;
    }
}
