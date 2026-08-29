#include <iostream>
using namespace std;

const int MAXN = 21;
const int MAXK = 11;
const int MAXS = 156;

long long dp[MAXN][MAXK][MAXS];

void precompute() {
    dp[0][0][0] = 1;
    for (int i = 1; i <= 20; i++) {
        for (int j = 0; j <= 10; j++) {
            for (int t = 0; t <= 155; t++) {
                dp[i][j][t] = dp[i-1][j][t];         
                if (j >= 1 && t >= i) {
                    dp[i][j][t] += dp[i-1][j-1][t-i]; 
                }
            }
        }
    }
}

int main() {
    precompute();
    int n, k, s;
    while (cin >> n >> k >> s) {
        if (n == 0 && k == 0 && s == 0) break;
        cout << dp[n][k][s] << endl;
    }
    return 0;
}