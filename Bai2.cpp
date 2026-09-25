#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void append(Node*& First, Node*& Last, int value) {
    Node* newNode = createNode(value);
    if (First == nullptr) {
        First = newNode;
        Last = newNode;
    } else {
        Last->next = newNode;
        Last = newNode;
    }
}

void removeDuplicates(Node*& First) {
    if (First == nullptr) return;
    unordered_set<int> seen;
    Node* curr = First;
    Node* prev = nullptr;
    while (curr != nullptr) {
        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
}

void printList(Node* First) {
    Node* temp = First;
    bool isFirst = true;
    while (temp != nullptr) {
        if (!isFirst) {
            cout << " ";
        }
        cout << temp->data;
        isFirst = false;
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    Node* First = nullptr;
    Node* Last = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        append(First, Last, val);
    }
    
    removeDuplicates(First);
    printList(First);
    
    return 0;
}