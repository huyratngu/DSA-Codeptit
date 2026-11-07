#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
string parenthchecker(string a) {
        stack<int> st;
        int n = a.size();
        for(int i = 0; i < n; i++) {
            if(a[i] == '(') {
                st.push(i);
            }
            else if(a[i] == ')') {
            int m = st.top();
            st.pop();
            if(m > 0 && a[m-1] == '-') {
                for(int j = m + 1; j < i; j++) {
                    if(a[j] == '+') {
                        a[j] = '-';
                    }
                    else if(a[j] == '-') a[j] = '+';
                }
            }
            a.erase(i, 1);
            a.erase(m, 1);
            i -= 2;
        }
    }
    return a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        cout << (parenthchecker(a) == parenthchecker(b) ? "YES" : "NO") << "\n";
    }
    return 0;
}