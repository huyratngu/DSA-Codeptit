#include <iostream>
#include <vector>
using namespace std;
vector<int> moneyExchange = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int exchange(int n) {
    int res = 0;
    for(int j = moneyExchange.size() - 1; j >= 0; j--) {
        if(n >= moneyExchange[j]) {
            int cnt = (n / moneyExchange[j]);
            res += cnt;
            n -= (cnt*moneyExchange[j]);
        }
        if(n == 0) {
            break;
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int r;
        cin >> r;
        cout << exchange(r) << "\n";
    }
}