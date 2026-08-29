#include <iostream>
using namespace std;

int n, k;
int x[1005];

void prevcombination() {
    int i = k;
    while(i > 0 && x[i] == x[i-1] + 1) {
        i--;
    }
    if(i > 0) {
        x[i] = x[i] - 1;
        for(int j = i + 1; j <= k; j++) {
            x[j] = n - (k - j);
        }
    } else {
        for(int j = 1; j <= k; j++) {
            x[j] = n - k + j;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        x[0] = 0;
        for(int i = 1; i <= k; i++) {
            cin >> x[i];
        }
        
        prevcombination();
        
        for(int i = 1; i <= k; i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    }
    return 0;
}