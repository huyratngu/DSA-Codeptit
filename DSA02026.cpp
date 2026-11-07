#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
bool matchpattern(string &pattern, int num) {
    string numStr = to_string(num);
    if(numStr.length() != pattern.length()) return false;
    for(int i = 0; i < (int)pattern.size(); i++) {
        if(pattern[i] != '?' && pattern[i] != numStr[i]) {
            return false;
        }
    }
    return true;
}
void parseLines(string &s, string &op1, string &op, string &op2, string &result) {
    stringstream ss(s);
    string equalSign;
    ss >> op1 >> op >> op2 >> equalSign >> result;
}
string solve(string &op1pattern, string &oppattern, string &op2pattern, string &resultpattern) {
    string best = "";
    vector<char> possibleOps;
    if(oppattern == "?") {
        possibleOps = {'+', '-', '/', '*'};
    } else {
        possibleOps.push_back(oppattern[0]);
    }
    for(int a = 10; a <= 99; a++) {
        if(!matchpattern(op1pattern, a)) continue;
        for(int b = 10; b <= 99; b++) {
            if(!matchpattern(op2pattern, b)) continue;
            for(char op : possibleOps) {
                int result;
                if(op == '+') result = a + b;
                else if(op == '-') result = a - b;
                else if(op == '*') result = a * b;
                else if(op == '/') {
                    if(b == 0 || a % b != 0) continue;
                    result = a/b;
                }
                if(result < 10 || result > 99) continue;
                if(!matchpattern(resultpattern, result)) continue;
                string candidate = to_string(a) + " " + op + " " + to_string(b) + " = " + to_string(result);
                if(best == "" || candidate < best) {
                    best = candidate;
                }
            }
        }
    }
    return best;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string s;
        getline(cin, s);
        string op1, op2, op, result;
        parseLines(s, op1, op, op2, result);
        string answer = solve(op1, op, op2, result);
        if(answer == "") cout << "WRONG PROBLEM!\n";
        else cout << answer << "\n";
    }
    return 0;
}
