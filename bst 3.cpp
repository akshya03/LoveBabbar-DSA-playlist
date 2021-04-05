//min max in bst
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left,*right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};

Node* findMax(Node *root){
    if(!root)
        return NULL;

    Node *curr=root;
    while(curr->right)
        curr=curr->right;
    return curr;
}
Node* findMin(Node *root){
    if(!root)
        return NULL;

    Node *curr=root;
    while(curr->left)
        curr=curr->left;
    return curr;
}

Node *Insert(Node *root,int x){
    if(!root)
        return new Node(x);
    else if(x<root->data)
        root->left=Insert(root->left,x);
    else if(x>root->data)
        root->right=Insert(root->right,x);
    return root;
}

int main(){
    int n,i,x;
    Node *root=NULL;
    /*
    cout<<"Enter no. of nodes in tree:";
    cin>>n;
    cout<<"Enter values:";
    for(i=0;i<n;++i){
        cin>>x;
    root=addNodeBST(root,x);
    }
    */
    root = Insert(root, 50);
    Insert(root, 30);
    Insert(root, 20);
    Insert(root, 40);
    Insert(root, 70);
    Insert(root, 60);
    Insert(root, 80);
    //inOrder(root);
    cout<<"Max value:"<<findMax(root)->data<<endl;
    cout<<"Min value:"<<findMin(root)->data<<endl;
    return 0;
}
