#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtBeginning(int data)
{
    Node* newnode = new Node();
    newnode->data=data;
    newnode->next = head;
    head = newnode;
}

void inserAtEnd(int data)
{
    Node* newnode = new Node();
    newnode->data = data;
    newnode->next = nullptr;
    if (head==nullptr)
    {
        head = newnode;
        return;
    }
    Node* current = head;
    while(current->next != nullptr)
    {
        current=current->next;
    }
    current->next = newnode;
}

bool insertAfterValue(int data,int value)
{
    Node* newnode = new Node();
    newnode->data = data;
    Node* current = head;
    while (current=nullptr && current->data != value)
    {
        current = current->next;
    }

    if (current==nullptr) return false;
    newnode->next = current->next;
    current->next = newnode;
    return true;
}

void deleteAtBeginning()
{
    if(head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}
void deleteAtEnd()
{
    if (head == nullptr) return;
    if (head->next ==nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node* current = head;
    while(current->next->next != nullptr)
    {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}

void deleteAtValue(int value)
{
    if(head==nullptr) return;
    if(head->data == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* previous = head;
    Node* current = head->next
    while (current!=nullptr && current->data != value)
    {
        previous = current;
        current = current->next;
    }

    if (current==nullptr) return;
    previous->next = current->next;
    delete current;
}

int searchList (int value)
{
    Node* temp = head;
    int index =0;
    while(temp != nullptr)
    {
        if(temp->data == value) return index;
        temp= temp->next;
        index++;
    }
}



int main()
{

}
