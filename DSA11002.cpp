#include <bits/stdc++.h>
using namespace std;
struct Node {
    string data;
    Node *left, *right;
    Node(string key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};
bool isOp(string c) {
    return (c == "+" || c == "-" || c == "*" || c == "/");
}
Node* buildTree() {
    string token;
    cin >> token;
    Node* root = new Node(token);
    queue<Node*> pending;
    pending.push(root);
    while (!pending.empty()) {
        Node* parent = pending.front();
        pending.pop();
        if (isOp(parent->data)) {
            cin >> token;
            parent->left = new Node(token);

            cin >> token;
            parent->right = new Node(token);
            pending.push(parent->left);
            pending.push(parent->right);
        }
    }
    return root;
}
long long eval(Node* node) {
    if (node->left == nullptr) return stoll(node -> data);
    long long left = eval(node->left);
    long long right = eval(node->right);
    if (node->data == "+") return left + right;
    if (node->data == "-") return left - right;
    if (node->data == "*") return left * right;
    return left / right;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node* root = buildTree();
        cout << eval(root) << "\n";
    }
    return 0;
}