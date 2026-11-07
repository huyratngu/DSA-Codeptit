#include <bits/stdc++.h>
using namespace std;
struct Node {
    char data;
    Node* left, *right;
    Node(char key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};
bool isOps(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
Node* buildtree(const string& s) {
    stack<Node*> st;
    for (char c : s) {
        Node* node = new Node(c);
        if (isOps(c)) {
            node->right = st.top();
            st.pop();
            node->left = st.top();
            st.pop();
        }
        st.push(node);
    }
    return st.top();
}
void printNode(Node* root) {
    if (root == nullptr) return;
    printNode(root->left);
    cout << root-> data;
    printNode(root->right);
}
void deleteNode(Node* root) {
    if (root == nullptr) return;
    deleteNode(root->left);
    deleteNode(root->right);
    delete root;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Node* root = buildtree(s);
        printNode(root);
        cout << "\n";
        deleteNode(root);
    }
    return 0;
}