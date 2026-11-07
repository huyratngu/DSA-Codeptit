#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s;
        stack<int> st;
        cin >> s;
        int total = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (s[i] == '+') total = b + a;
                if (s[i] == '-') total = b - a;
                if (s[i] == '*') total = b * a;
                if (s[i] == '/') total = b / a;
                st.push(total);
            }
            else {
                int num = s[i] - '0';
                st.push(num);
            }
        }
        cout << st.top() << "\n";
    }
    return 0;
}