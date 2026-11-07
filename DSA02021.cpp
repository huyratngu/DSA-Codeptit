#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
int n;
int k;
char recurse(string &abc, long long n, long long k) {
    if(k < abc.size()) return abc[k];
    if(k < n / 2) return recurse(abc, n/2, k);
    if(k == n/2) return recurse(abc, n/2, k - 1);
    if(k > n/2) return recurse (abc, n/2, k - (n/2) - 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        s.clear();
        cin >> s >> k;
        n = s.size();
        k--;
        while(n <= k) n*=2;
        cout << recurse(s, n, k) << "\n";
    }
    return 0;
}