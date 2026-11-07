#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long toMin(string s) {
    for (char &c : s) {
        if (c == '6') c = '5';
    }
    return stoll(s);
}

long long toMax(string s) {
    for (char &c : s) {
        if (c == '5') c = '6';
    }
    return stoll(s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        string a, b;
        cin >> a >> b;
        long long worst = toMin(a) + toMin(b);
        long long best = toMax(a) + toMax(b);
        cout << worst << " " << best << "\n";

}