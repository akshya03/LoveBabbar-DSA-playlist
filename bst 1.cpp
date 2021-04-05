//find a value in bst

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
void inOrder(Node *root){
    if(!root)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

bool searchBST(Node* root,int x){
    if(!root)
        return false;
    else if(x==root->data)
        return true;
    else if(x<root->data)
        return searchBST(root->left,x);
    else
        return searchBST(root->right,x);
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
    cout<<searchBST(root,10)<<" "<<searchBST(root,50);
    return 0;
}
