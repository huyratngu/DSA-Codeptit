#include <iostream>
using namespace std;
int n, ok;
string s;
void initialize() {
    cin >> n;
    s = string(n, 'A');
}
void gen() {
    int i = s.length() - 1;
    while(i >= 0 && s[i] == 'H') {
        s[i] = 'A';
        i--;
    }
    if(i >= 0) {
        s[i] = 'H';
    }
    else {
        ok = 0;
    }
}
bool checker() {
    int j = s.length() - 1;
    if(s[0] == 'H' && s[j] == 'A') {
        for(int i = 0; i < j; i++) {
            if(s[i] == 'H' && s[i+1] == 'H') {
                return false;
            }
        }
        return true;
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        initialize();
        ok = 1;
        while(ok) {
            if(checker()) {
                cout << s << endl;
            }
            gen();
        }
    }
    return 0;
}
