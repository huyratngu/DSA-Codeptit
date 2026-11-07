#include <iostream>
#include <string>
#include <cctype>
#include <climits>
#include <stack>
using namespace std;
int precedenc(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s;
        getline(cin >> ws, s);
        stack<char> st;
        string res;
        for(char c : s) {
            if(isspace(static_cast<unsigned char>(c))) continue;
            if(isalnum(static_cast<unsigned char>(c))) {
                res += c;}
                else if(c == '(') st.push(c);
                else if(c == ')') {
                    while(!st.empty() && st.top() != '(') {
                        res += st.top();
                        st.pop();
                    }
                    if(!st.empty()) st.pop();
                }
                else {
                    while(!st.empty() && st.top() != '(' &&
                          (precedenc(st.top()) > precedenc(c) ||
                           (precedenc(st.top()) == precedenc(c) && c != '^'))) {
                        res += st.top();
                        st.pop();
                    }
                    st.push(c);
                }
            }
            while(!st.empty()) {
                if(st.top() != '(') res += st.top();
                st.pop();
            }
            cout << res << "\n";
        }
    return 0;
}
