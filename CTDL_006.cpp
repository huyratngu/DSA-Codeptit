#include <iostream>
#include <unordered_set>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void in(Node* &head) {
    for(Node* p = head; p != NULL; p = p -> next) {
        cout << p -> data;
        if(p != nullptr) cout << " "; 
    }
    cout << "\n";
}
int main() {
    int n;
    cin >> n;
    Node* head = nullptr;
    Node* last = nullptr;
    unordered_set<int> nums;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(nums.insert(x).second) {
            Node *p = new Node{x, nullptr};
            if(head == nullptr) head = last = p;
            else {
                last -> next = p;
                last = p;
            }
        }
    }
    in(head);
    return 0;
}