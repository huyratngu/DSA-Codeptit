#include <iostream>
#include <vector>
using namespace std;
int n;
int OK;
int k;
void permutate(vector<int> &p) {
    int i = k;
    while(i > 0 && p[i] == n - k + i) i--;
    if(i > 0) {
        p[i] = p[i] + 1;
        for(int j = i + 1; j <= k; j++) {
            p[j] = p[i] + j - i;
        }
    }
    else {
        OK = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<int> x(k + 1);
        for(int i = 1; i <= k; i++) cin >> x[i];
        vector<int> p(k + 1);
        for(int i = 1; i <= n; i++) p[i] = i;
        int rank = 1;
        OK = 1;
        while(OK) {
            bool same = true;
            for(int i = 1; i <= k; i++) {
                if(p[i] != x[i]) {
                    same = false;
                    break;
                }
            }
                if(same) break;
                permutate(p);
                rank++;
        }
        cout << rank << "\n";
    }
    return 0;
}