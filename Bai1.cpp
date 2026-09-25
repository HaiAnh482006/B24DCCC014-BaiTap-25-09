#include <iostream>

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

int removeAll(Node*& First, int x) {
    int count = 0;
    while (First != nullptr && First->data == x) {
        Node* temp = First;
        First = First->next;
        delete temp;
        count++;
    }
    if (First == nullptr) {
        return count;
    }
    Node* curr = First;
    while (curr->next != nullptr) {
        if (curr->next->data == x) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }
    return count;
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
    
    int x;
    cin >> x;
    
    removeAll(First, x);
    printList(First);
    
    return 0;
}