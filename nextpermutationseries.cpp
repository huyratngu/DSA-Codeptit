#include <bits/stdc++.h>
using namespace std;
int sothutu;
int n;
int ok;
string s;
string res;
void initialize() {
    cin >> sothutu;
    cin >> s;
    n = s.length() - 1;
    res = s;
}
void next_permutation() {
    int j = n - 1;
    while(j >= 0 && s[j] >= s[j+1]) {
        j--;
    }
    if(j >= 0) {
        int k = n;
        while(s[j] >= s[k]) {
            k--;
        }
        char t = s[j];
        s[j] = s[k];
        s[k] = t;
        int l = j + 1;
        int r = n;
        while(l <= r) {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;
            r--;
        }
    }
    else {
        ok = 0;
    }
}
bool check_bigger_int_permutations() {
    if (ok == 0) {
        cout << "BIGGEST";
        return 0;
    }
    else {
    long long current_res = stoll(res);
    long long next_perm = stoll(s);
    if(next_perm > current_res) {
        return true;
    }
    else {
        return false;
        }
    }
}
int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        initialize();
        ok = 1;
        next_permutation();
        if(ok == 1) {
            cout << i << " " << s;
        }
        if(ok == 0) {
            cout << i << " " << "BIGGEST";
        }
        cout << endl;
    }
    return 0;
}
