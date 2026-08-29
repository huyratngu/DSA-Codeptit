#include <bits/stdc++.h>
using namespace std;
int n, w;
int a[100], b[100];
void ktao() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i] >> b[i];
        }
    }
}
void KS() {
    int c = w;
    int result = 0;
    if (n == 0 || c == 0) result = 0;
    else if (a[n] > c) {
        result = KS(n-1, c);
    }
    else {
        int tmp1 = KS(n-1, c);
        int tmp2 = b[n] + KS(n-1, C - a[n]);
        result = max(tmp1, tmp2);
    }
}
int main () {
    ktao();
    for (int i = 1; i <= n; i++) {
        KS();
        cout << 
    }
}