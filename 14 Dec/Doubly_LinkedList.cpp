#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
};

node *head = nullptr;


void printList(){
    node *p = head;
    cout << "\n[";
    while (p != nullptr) {
        cout << " " << p->data << " ";
        p = p->next;
    }
    cout << "]\n";
}

// Insert at beginning (head) - O(1)
void insertatbegin(int data){
    node *lk = new node();
    lk->data = data;
    lk->next = head;
    head->prev = lk;
    head = lk;
    head->prev = nullptr;
}

// Insert at end - O(n)
void insertatend(int data){
    node *lk = new node();
    lk->data = data;
    lk->next = nullptr;
    if (head == nullptr) {
        head = lk;
        lk->prev = nullptr;
        return;
    }
    node *cur = head;
    while (cur->next != nullptr)
    {
        cur = cur->next;

    }
    cur->next = lk;
    lk->prev = cur;
}

// Insert after the first node containing target
bool insertaftervalue(int target, int data){
    node *cur = head;
    node *lk = new node();
    lk->data = data;
    while (cur != nullptr && cur->data != target)
    {
        cur = cur->next;
    }
    if (cur==nullptr) return false;

    lk->next = cur->next;
    lk->prev = cur;
    cur->next = lk;
    lk->next->prev = lk;

    return true;
}

// Delete at beginning - O(1)
void deleteatbegin(){
    if (head==nullptr) return;
    node *tmp = head;
    head = head->next;
    head->prev = nullptr;
    delete tmp;
}

// Delete at end - O(n)
void deleteatend(){
    if (head==nullptr) return;
    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    if (temp->prev != nullptr) temp->prev->next = nullptr;
    delete temp;

}

// Delete first node with value == key - O(n)
void deletenode(int key){
    if (head==nullptr) return;

    node *cur = head;
    while (cur != nullptr && cur->data != key) {
        cur = cur->next;
    }
    if (cur==nullptr) return;
    if(cur->prev != nullptr) cur->prev->next = cur->next;
    if(cur->next != nullptr) cur->next->prev = cur->prev;
    delete cur;
}


int searchlist(int key){
    node *temp = head;
    int idx = 0;
    while (temp != nullptr) {
        if (temp->data == key) return idx;
        temp = temp->next;
        ++idx;
    }
    return -1;
}

// Clear list
void clearList() {
    while (head) {
        node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main(){
    int choice;
    cout << "Doubly Linked List - Interactive Menu (using new/delete)\n";
    while (true) {
        cout << "\nMenu:\n";
        cout << " 1  Insert at beginning\n";
        cout << " 2  Insert at end\n";
        cout << " 3  Insert after value\n";
        cout << " 4  Delete at beginning\n";
        cout << " 5  Delete at end\n";
        cout << " 6  Delete node by value\n";
        cout << " 7  Search for value\n";
        cout << " 8  Print list\n";
        cout << " 9  Clear list\n";
        cout << " 0  Exit\n";
        cout << "Choose an option: ";
        if (!(cin >> choice)) {
            cout << "Input error. Exiting.\n";
            break;
        }
        if (choice == 0) break;
        int val, after;
        int idx;
        bool ok;
        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: "; cin >> val;
                insertatbegin(val);
                break;
            case 2:
                cout << "Enter value to insert at end: "; cin >> val;
                insertatend(val);
                break;
            case 3:
                cout << "Enter existing value to insert after: "; cin >> after;
                cout << "Enter new value to insert: "; cin >> val;
                ok = insertaftervalue(after, val);
                if (ok) cout << "Inserted " << val << " after " << after << ".\n";
                else cout << "Value " << after << " not found.\n";
                break;
            case 4:
                deleteatbegin();
                break;
            case 5:
                deleteatend();
                break;
            case 6:
                cout << "Enter value to delete: "; cin >> val;
                deletenode(val);
                break;
            case 7:
                cout << "Enter value to search: "; cin >> val;
                idx = searchlist(val);
                if (idx >= 0) cout << "Found at index " << idx << ".\n";
                else cout << "Not found.\n";
                break;
            case 8:
                printList();
                break;
            case 9:
                clearList();
                cout << "List cleared.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }
    clearList();
    cout << "Exiting. List cleared.\n";
    return 0;
}

