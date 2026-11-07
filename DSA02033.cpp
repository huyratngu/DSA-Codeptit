#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool used[15];
bool biggerthan0(string path, int digit) {
    if(path.size() == 0) return true;
    int lastDigit = path.back() - '0';
    return abs(lastDigit - digit) != 1; 
}
void solve(int n, string path) {
    if((int)path.size() == n) {
        cout << path << "\n";
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(used[i]) continue;
        if(biggerthan0(path, i)) {
            path += ('0' + i);
            used[i] = true;
            solve(n, path);
            used[i] = false;
            path.pop_back();
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < 15; i++) used[i] = false;
        string path = "";
        solve(n, path);
    }
    return 0;
}