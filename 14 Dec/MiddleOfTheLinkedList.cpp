#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

node *head = nullptr;

void middleOfLL()
{
    node *slow = head;
    node *fast = head;
    while (fast->next!=nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<"Middle of the Linked List: "<<slow->data<<endl;
}

void printList(){
    node *p = head;
    cout << "\n[";
    while (p != nullptr) {
        cout << " " << p->data << " ";
        p = p->next;
    }
    cout << "]\n";
}

void insertatend(int data){
    node *lk = new node();
    lk->data = data;
    lk->next = nullptr;
    if (head == nullptr) {
        head = lk;
        return;
    }
    node *cur = head;
    while (cur->next != nullptr) cur = cur->next;
    cur->next = lk;
}
void clearList() {
    while (head) {
        node *tmp = head;
        head = head->next;
        delete tmp;
    }
}


int main(){
    int choice;
    cout << "Singly Linked List - Finding Middle of the Linked List\n";
    while (true) {
        cout << "\nMenu:\n";
        cout << " 1  Insert value\n";
        cout << " 2  Middle Of the linked list\n";
        cout << " 3  Print list\n";
        cout << " 0  Exit\n";
        cout << "Choose an option: ";
        if (!(cin >> choice)) {
            cout << "Input error. Exiting.\n";
            break;
        }
        if (choice == 0) break;
        int val;
        switch (choice) {
            case 1:
                cout << "Enter value to insert at end: "; cin >> val;
                insertatend(val);
                break;
            case 2:
                middleOfLL();
                break;
            case 3:
                printList();
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }
    clearList();
    cout << "Exiting. List cleared.\n";
    return 0;
}
