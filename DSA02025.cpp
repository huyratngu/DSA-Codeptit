#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int dupeChecks(const string &a, const string &b) {
    int cnt = 0;
    for(char c : a) {
        for(char d : b) {
            if(c == d) cnt++;
        }
    }
    return cnt;
}
vector<vector<int>> cost(vector<string> &strs, int n) {
    vector<vector<int>> costs(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) {
                costs[i][j] = dupeChecks(strs[i], strs[j]);
            }
        }
    }
    return costs;
}
int findmin(vector<vector<int>> &cost, int n) {
    vector<int> indx(n);
    for(int i = 0; i < n; i++) indx[i] = i;
    int best = INT_MAX;
    do {
        int total = 0;
        for(int i = 0; i < n - 1; i++) {
            total += cost[indx[i]][indx[i+1]];
        }
        best = min(best, total);
    } while(next_permutation(indx.begin(), indx.end()));
    return best;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> strs(n);
    for(int i = 0; i < n; i++) cin>> strs[i];
    vector<vector<int>> costmatrix = cost(strs, n);
    int ans = findmin(costmatrix, n);
    cout << ans << "\n";
}