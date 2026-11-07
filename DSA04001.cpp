#include <iostream>
using namespace std;
const long long MOD = 1000000007;
long long power(long long n, long long k) {
    if(k == 0) return 1;
    n %= MOD;
    long long half = power(n, k/2);
    long long result = (half * half) % MOD;
    if(k % 2 == 1) {
        result = (result * n) % MOD;
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        int k;
        cin >> n >> k;
        cout << power(n, k) << "\n";
    }
    return 0;
}