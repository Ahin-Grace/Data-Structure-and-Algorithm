#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int n)
    {
        key = n;
        left = nullptr;
        right = nullptr;
    }

};
Node* insertNode(Node* root,int key)
{
    Node* newNode = new Node(key);
    if(root == nullptr) return newNode;
    if(key<root->key)
    {
        root->left= insertNode(root->left,key);
    }
    else if(key>root->key){
        root->right= insertNode(root->right,key);
    }
}

void order(Node* root)
{
    if(root == nullptr) return;
   order(root->right);
    cout<<root->key<<" ";
   order(root->left);
}


int main()
{
    Node* root = nullptr;
    int n,m;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements in a sequence: ";
    for (int i=0; i<n; i++)
    {
        cin>>m;
       root= insertNode(root,m);
    }
    order(root);
}




