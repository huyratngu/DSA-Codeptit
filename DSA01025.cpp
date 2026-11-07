#include <string>
#include <iostream>
#include <vector>
using namespace std;
int n, k;
string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void solve(string &path, int start, vector<string> &res) {
    if(path.size() == n) {
        res.push_back(path);
        return;
    }
    for(int i = start; i < k; i++) {
        path += letters[i];
        solve(path, i + 1, res);
        path.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> k >> n;
        string path = "";
        vector<string> res;
        solve(path, 0, res);
        for(int i = 0; i < res.size(); i++) cout << res[i] << "\n";
    }
    return 0;
}