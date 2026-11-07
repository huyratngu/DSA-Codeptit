#include <bits/stdc++.h>
using namespace std;
int prio(char &c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}
long long calculation(long long a, long long b, char c) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    if (c == '/') return a / b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<long long> nums;
        stack<char> ops;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(static_cast<unsigned char>(s[i]))) {
                long long num = 0;
                while (i < s.size() && isdigit(static_cast<unsigned char>(s[i]))) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                nums.push(num);
                i--;
            }
            else if (s[i] == '(') {
                ops.push(s[i]);
            }
            else if (s[i] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    long long a = nums.top();
                    nums.pop();
                    long long b = nums.top();
                    nums.pop();
                    char current_op = ops.top();
                    ops.pop();
                    long long res = calculation(b, a, current_op);
                    nums.push(res);
                }
                ops.pop();
            }
            else {
                while (!ops.empty() && ops.top() != '(' && prio(ops.top()) >= prio(s[i])) {
                    long long c = nums.top();
                    nums.pop();
                    long long d = nums.top();
                    nums.pop();
                    char nextchar = ops.top();
                    ops.pop();
                    long long res = calculation(d, c, nextchar);
                    nums.push(res);
                }
                ops.push(s[i]);
            }
        }
        while (!ops.empty()) {
            long long a = nums.top();
            nums.pop();
            long long b = nums.top();
            nums.pop();
            char c = ops.top();
            ops.pop();
            long long res = calculation(b, a, c);
            nums.push(res);
        }
        cout << nums.top() << "\n";
    }
    return 0;
}