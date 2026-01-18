#include<bits/stdc++.h>
using namespace std;


struct node
{
    int key;
    node *left;
    node *right;
    node(int n){
        key = n;
        left = nullptr;
        right = nullptr;
    }
    //node(int k): data(k), left(nullptr), right(nullptr){}
};

node* insertNode(node* root, int value)
{
    if(root==nullptr) return new node(value);
    if(value<root->key) root->left=insertNode(root->left, value);
    else if(value>root->key) root->right=insertNode(root->right, value);
    return root;
}

bool searchNode(node* root, int target)
{
    if (root==nullptr) return false;
    if(root->key==target) return true;
    else if(target<root->key) return seachNode (root->left, target);
    else return seachNode (root->right, target);
}

void preOrder(node* root)
{
    if(!root) return;
    cout<<root->key<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node* root)
{
    if(!root) return;
    inOrder(root->left);
    cout<<root->key<<" ";
    inOrder(root->right);
}

void postOrder(node* root)
{
    if(!root) return;
    cout<<root->key<<" ";
    postOrder(root->right);
    postOrder(root->left);
}

node* minValueNode(node* node)
{
    node* cur = node;
    while (cur!= nullptr && cur->left !=nullptr)
    {
        cur= cur->left;
    }
    return cur;
}


node* deleteNode(node* root, int target)
{
    if(root==nullptr) return nullptr;
    if(target<root->key)
    {
        root->left= deleteNode(root->left, target);
    }
    else if(target<root->key)
    {
        root->right= deleteNode(root->right, target);
    }
    else
        {
        if(root->left= nullptr)
        {
            node* temp = root->right;
            delete root;
            return temp
        }
        else if(root->right= nullptr)
        {
            node* temp = root->left;
            delete root;
            return temp
        }
        else
            {
            node* inorderSuccessor = minValueNode(root->right);
            root->key = inorderSuccessor->key;
            root->right = deleteNode(root->right, inorderSuccessor->key);
        }
    }
}


int main()
{
    node* root = nullptr;
    int n;
    while(true)
    {
        cout<<"1. Insertion."<<endl;
        cout<<"2. Search a node."<<endl;
        cout<<"3. Show PreOrder."<<endl;
        cout<<"4. Show PostOrder."<<endl;
        cout<<"5. Show InOrder."<<endl;
        cout<<"6. Delete."<<endl;
        cout<<"Enter your Choice: ";
        cin>>n;
        switch(n)
        {
        case 1:
            cout<<"Insert the value: ";
            int val;
            cin>>val;
            insertNode(root,val);
            break;

        case 2:
            cout<<"Enter the  target: "
            int val;
            cin>>val;
            searchNode(root,val);
            break;
        case 3:
        case 4:
        case 5:
        case 6:

        }

    }

}
