#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> results;
string path;
string s;
void solve(int start) {
    if(!path.empty()) {
        results.push_back(path);
    }
    for(int i = start; i < s.size(); i++) {
        path += s[i];
        solve(i + 1);
        path.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        path.clear();
        results.clear();
        s.clear();
        int n;
        cin >> n;
        cin >> s;
        solve(0);
        sort(results.begin(), results.end());
        for(int i = 0; i < results.size(); i++) cout << results[i] << " ";
        cout << "\n";
    }
    return 0;
}