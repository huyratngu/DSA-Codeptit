#include <iostream>
#include <string>
using namespace std;
bool used[10];
bool check(string path, int digit) {
    if((int)path.size() == 0) return true;
    char lastDigit = path.back() - '0';
    return abs(lastDigit - digit) != 1;
}
void solve(string path, int n) {
    if((int)path.size() == n) {
        cout << path << "\n";
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(used[i]) continue;
        if(check(path, i)) {
            path += ('0' + i);
            used[i] = true;
            solve(path, n);
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
        for(int i = 3; i < 10; i++) used[i] = false;
        string path = "";
        solve(path, n);
    }
    return 0;
}