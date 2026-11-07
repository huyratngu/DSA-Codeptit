#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isSq(const string &c,const string &s) {
    int k = 0;
    for(int i = 0; i < (int)s.size() && k <(int)c.size(); i++) {
        if(s[i] == c[k]) k++;
    }
    return k == (int)c.size();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        string s = to_string(n);
        long long best = -1;
        for(long long i = 1; i * i * i <= n; i++){
            long long cube = i * i * i;
            string c = to_string(cube);
            if(isSq(c, s)) best = max(best, cube);
        }
        cout << best << "\n";   
    }
}