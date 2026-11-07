#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void solve(vector<int> &arr, vector<string> &results, int lastidx, vector<int> path) {
    if((int)path.size() >= 2) {
        string s;
        for(int i = 0; i < (int)path.size(); i++) {
            if(i > 0) s += " ";
            s += to_string(path[i]);
        }
        results.push_back(s);
    }
    for(int i = lastidx + 1; i < (int)arr.size(); i++) {
        if(path.empty() || arr[i] > path.back()) {
            path.push_back(arr[i]);
            solve(arr, results, i, path);
            path.pop_back();
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<string> results;
    vector<int> path;
    solve(arr, results, -1, path);
    sort(results.begin(), results.end());
    for(const string &s : results) cout << s << "\n";
    return 0;
}