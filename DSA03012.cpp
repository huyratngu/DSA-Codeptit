#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s;
        int d;
        cin >> d >> s;
        unordered_map<char, int> mp;
        int freq = 0;
        for(char x : s) {
            mp[x]++;
            freq = max(freq, mp[x]);
        }
        int b = 0;
        for(auto x : mp) if(x.second == freq) b++;

        int n = s.size();
        if(d <= 1 || (long long)(freq - 1) * d + b <= n) {
            cout << 1 << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
    return 0;
}