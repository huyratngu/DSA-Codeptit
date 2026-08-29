#include <iostream>
#include <string>
using namespace std;
int n, ok;
string s;
void initialize() {
    cin >> s;
}
void magraygen() {
    int size = s.length() - 1;
    int i = size;
    while(i >= 0 && s[i] != 0) {
        s[i] = 0;
        i--;
    }
    if(i >= 0) {
        s[i] = 1;
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
        magraygen();
        cout << s;
    }
    return 0;
}