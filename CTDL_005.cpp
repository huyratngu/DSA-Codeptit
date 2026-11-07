#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
int xoa(Node* &first, int x) {
    int dem = 0;
    while(first != NULL && first -> data == x) {
        Node* temp = first;
        first = first -> next;
        delete temp;
        dem++;
    }
    if(first == NULL) return dem;
    Node* prev = first;
    Node* cur = first -> next;
    while(cur != NULL) {
        if (cur -> data == x) {
        prev -> next = cur -> next;
        delete cur;
        dem++;
        cur = prev -> next;
        }
        else {
            prev = cur;
            cur = cur -> next;
        }
    }   
    return dem;
}
void in(Node* &first) {
    for(Node* i = first; i != NULL; i = i -> next) {
        cout << i -> data;
        if(i -> next != NULL) cout << " ";
    }
    cout << "\n";
}
int main() {
    int n;
    cin >> n;
    Node* first = nullptr;
    Node* last = nullptr;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* p = new Node{x, nullptr};
        if(first == nullptr) {
            first = p;
            last = p;
        }
        else {
            last -> next = p;
            last = p;
        }
    }
    int x;
    cin >> x;
    xoa(first, x);
    in(first);
}