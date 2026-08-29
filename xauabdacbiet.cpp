#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, k, ok;
vector<string> res;
string s;
void initialize() {
    cin >> n >> k;
    s = string(n, 'A');
}
void gen() {
    int i = n - 1;
    while(i >= 0 && s[i] == 'B') {
        s[i] = 'A';
        i--;
    }
    if(i >= 0) {
        s[i] = 'B';
    }
    else {
        ok = 0;
    }
}
bool check_k() {
    int cnt = 0;
    int cnt_k = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') {
            cnt++;
        }
        else{
            if(cnt == k) {
                cnt_k++;
            }
            else if (cnt > k)
            {
                return false;
            }
            cnt = 0;
        }
    }
    if(cnt == k) cnt_k++;
    else if (cnt > k)
    {
        return false;
    }
    
    return cnt_k == 1;
}
int main() {
        initialize();
        ok = 1;
        while(ok) {
            if(check_k()) {
                res.push_back(s);
            }
            gen();
        }
            cout << res.size() << endl;
            for(int i = 0; i < res.size(); i++) {
            cout << res[i] << endl;
            }
    return 0;
}
