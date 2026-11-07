#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool used[10];
string letters;
string current;
int n;
bool vowel(char ch) {
    return ch == 'A' || ch == 'E';
}
bool end() {
    int len = current.size();
    if(len < 3) return false;
    char left = current[len-3];
    char mid = current[len-2];
    char right = current[len-1];
    return(!vowel(left) && vowel(mid) && !vowel(right));
}
void combo(int pos) {
    if(pos == n) {
        cout << current << "\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        if(used[i]) continue;
        current += letters[i];
        used[i] = true;
        if(!end()) {
            combo(pos + 1);
        }
        used[i] = false;
        current.pop_back();
    }
}
int main() {
    char c;
    cin >> c;
    for(char ch = 'A'; ch <= c; ch++) letters += ch;
    n = letters.size();
    combo(0);
    return 0;
}